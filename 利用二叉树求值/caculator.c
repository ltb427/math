#include"caculator.h"
#include<math.h>
//二叉树存储结构
struct Tree {
	char data[15];
	struct Tree* LChild;
	struct Tree* RChild;
};
typedef struct Tree BiTree;
//递归建立二叉树
static BiTree* CreatTreePreorder(char(*str)[15], int start, int end);
//将叶节点字符型式转换为浮点型
static double StrDigital(char str[]);
//求整个表达式的结果
static double CaculateResult(BiTree* root);
//运算
static double Caculating(const char* equation);
//判断是否可以消除最外层符号
static int RemoveBrackets(char(*str)[15], int start, int end);
//获得表达式中优先级最低的操作符
static int GetLowestOper(char(*str)[15], int start, int end);

double getResult(const char * oring)
{
	return Caculating(oring);
}

void getResult_s(const char * oring, char * result, const int limit)
{
	double results = Caculating(oring);
	char buffer[64];
	sprintf(buffer,"%%.%df", limit);
	sprintf(result, buffer, results);
}

BiTree * CreatTreePreorder(char(*str)[15], int start, int end)
{
	int pos = -1;
	int sign = 0;
	BiTree *root;
	if (end - start == 0)
	{
		root = (BiTree*)malloc(sizeof(BiTree));
		strcpy(root->data, str[start]);
		root->LChild = NULL;
		root->RChild = NULL;
		return root;
	}
	pos = GetLowestOper(str, start, end);
	root = (BiTree*)malloc(sizeof(BiTree));
	strcpy(root -> data, str[pos]);
	//左
	int removeable = RemoveBrackets(str, start, pos-1);
	if (removeable == 1)
		root->LChild = CreatTreePreorder(str, start + 1, pos - 2);
	else
		root->LChild = CreatTreePreorder(str, start, pos - 1);
	//右
	removeable = RemoveBrackets(str, pos + 1, end);
	if (removeable == 1)
		root->RChild = CreatTreePreorder(str, pos+2, end - 1);
	else
		root->RChild = CreatTreePreorder(str, pos + 1, end);
	return root;
}

double StrDigital(char str[])
{
	int i, len, pos;
	double sum;
	len = strlen(str);
	for (i = 0; i < len; ++i)
		if (str[i] == '.')
			break;
	pos = i;
	i = 0; sum = 0;
	while(i < len)
	{
		if (i < pos)
			sum += (str[i] - '0')*pow(10, pos - i-1);
		else if (i>pos)
			sum += (str[i] - '0')*pow(10, pos - i);
		++i;
	}
	return sum;
}

double CaculateResult(BiTree * root)
{
	double result = 0;
	if (root->LChild == NULL&&root->RChild == NULL)
	{
		result = StrDigital(root->data);
		return result;
	}
	double Lresult = CaculateResult(root->LChild);
	double Rresult = CaculateResult(root->RChild);
	switch (root->data[0])
	{
		case '+':return Lresult + Rresult; break;
		case '-':return Lresult - Rresult; break;
		case '*':return Lresult * Rresult; break;
		case '/':return Lresult / Rresult; break;
		case '>':return Lresult > Rresult; break;
		case '<':return Lresult < Rresult; break;
		case '=':return Lresult == Rresult; break;
		case '&':return (int)Lresult & (int)Rresult; break;
		case '|':return (int)Lresult | (int)Rresult; break;
	}
	return result;
}

double Caculating(const char * equation)
{
	BiTree* root = NULL;
	double result;
	char str[100][15];
	memset(str, '\0', sizeof(str));
	int length = strlen(equation);
	int i, j, k;
	i = 0; k = 0;
	while (i<length)
	{
		if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' ||
			equation[i] == '/' || equation[i] == '(' || equation[i] == ')'||
			equation[i]=='&' || equation[i] == '|' || equation[i] == '>' || 
			equation[i] == '<' || equation[i] == '=')
			str[k++][0] = equation[i++];
		else
		{
			j = 0;
			while (equation[i]>='0'&&equation[i]<='9'||equation[i]=='.')
			{
				str[k][j] = equation[i];
				++i;
				++j;
			}
			++k;
		}
	}
	int start = 0;
	int end = k - 1;
	int removeable = RemoveBrackets(str, start, end);
	if (removeable == 1)
		root = CreatTreePreorder(str, start + 1, end - 1);
	else
		root = CreatTreePreorder(str, start, end);
	result = CaculateResult(root);
	return result;
}

int RemoveBrackets(char(*str)[15], int start, int end)
{
	int result = 0;
	if (strcmp(str[start], "(") == 0 && strcmp(str[end], ")") == 0)
	{
		char flag = ')';
		for (int i = start + 1; i < end; ++i)
		{
			if (strcmp(str[i], "(") == 0 || strcmp(str[i], ")") == 0)
				flag = str[i][0];
		}
		if (flag == ')')
			result = 1;
	}
	return result;
}

int GetLowestOper(char(*str)[15], int start, int end)
{
	int pos = -1;
	int sign = 0;
	int t = 1;
	while (pos==-1)
	{
		for (int i = start; i <= end; i++)
		{
			if (strcmp(str[i], "(") == 0)
			{
				++i;
				sign = 1;
				while (sign>0)
				{
					if (strcmp(str[i], "(") == 0)
						++sign;
					if (strcmp(str[i], ")") == 0)
						--sign;
					++i;
				}
				--i;
			}
			if (t == 1)
			{
				if (strcmp(str[i], ">") == 0 || strcmp(str[i], "<") == 0 ||
					strcmp(str[i], "=") == 0 || strcmp(str[i], "&") == 0 ||
					strcmp(str[i], "|") == 0)
					pos = i;
			}
			else if (t == 2)
			{
				if (strcmp(str[i], "+") == 0 || strcmp(str[i], "-") == 0)
					pos = i;
			}
			else
			{
				if (strcmp(str[i], "*") == 0 || strcmp(str[i], "/") == 0)
					pos = i;
			}
		}
		++t;
	}
	return pos;
}
