#include<stdio.h>
#include<stdlib.h>

char* getMemory(const int col);
char**ptr;
void main()
{
	int row, col;
	printf("请输入行数&列数: ");
	scanf("%d%d", &row, &col);
	ptr = (char**)malloc(sizeof(char*));
	if (ptr == NULL)
	{
		printf("not enough memory!\n");
		return;
	}
	for (int i = 0; i < row; ++i)
	{
		ptr[i] = getMemory(col);
		if (ptr[i] == NULL)
		{
			printf("not enough memory!\n");
			return;
		}
	}
	int k = 48;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col-1; ++j)
		{
			ptr[i][j] = k;
			++k;
		}
		ptr[i][col - 1] = 0;
	}
	for (int i = 0; i < row; ++i)
	{
		printf(ptr[i]);
		printf("\n");
	}
}
char* getMemory(const int col)
{
	char*ptr=(char*)malloc(col*sizeof(char));
	if (ptr == NULL)
	{
		printf("not enough memory!\n");
		return NULL;
	}
	return ptr;
}
