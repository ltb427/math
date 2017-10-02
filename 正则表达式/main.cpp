#include<sstream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
#include<iterator>
#include<functional>


using namespace std;
//使用partition
bool isLower(const int &i)
{
	return i > 5;
}
void _partition_(void)
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	auto end=partition(vec.begin(), vec.end(), isLower);
	for_each(vec.begin(), end, [](const int& j) {cout << j << endl; });
}
//使用sort
void _sort_(void)
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	sort(vec.begin(), vec.end());
	for_each(vec.begin(), vec.end(), [](const int &j) {cout << j << endl; });
}
//使用accumulate
void _accumulate_(void)
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	int sum = accumulate(vec.begin(), vec.end(), 0);
	cout << sum << endl;
}
//使用back_inserter
void _back_inserter_(void)
{
	vector<int> vec;
	fill_n(back_inserter(vec), 10, 0);
	for_each(vec.begin(), vec.end(), [](const int &j) {cout << j << " "; });
}
//使用copy
void _copy_(void)
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	vector<int> _vec(vec.size());
	copy(vec.begin(), vec.end(), _vec.begin());
	for_each(_vec.begin(), _vec.end(), [](const int &j) {cout << j << " "; });
}
//replace
void _replace_(void)
{
	vector<int> vec;
	vector<int>_vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	replace(vec.begin(), vec.end(), 0, 1);
	for_each(vec.begin(), vec.end(), [](const int &j) {cout << j << " "; });
	replace_copy(vec.begin(), vec.end(), back_inserter(_vec), 1, 10);
	cout << endl;
	for_each(_vec.begin(), _vec.end(), [](const int &j) {cout << j << " "; });
}
//transform
void _transform_(void)
{
	vector<int> vec;
	int i;
	while (cin >> i)
		vec.push_back(i);
	transform(vec.begin(), vec.end(), vec.begin(),[](int& i)->int {return i > 0 ? i : -i; });
	for_each(vec.begin(), vec.end(), [](const int &j) {cout << j << " "; });
}
bool tool(const char& ch)
{
	return ch >= 'A'&&ch <= 'Z';
}
bool isUpper(const string& lstr,const string& rstr)
{
	return all_of(lstr.begin(), lstr.end(), tool) && all_of(rstr.begin(), rstr.end(), tool);
}
//查找重复第一个的值 adjacent_find(beg,end)
void _adjacent_find_(void)
{
	vector<string> vec;
	string str;
	while (cin >> str)
		vec.push_back(str);
	auto end_it = adjacent_find(vec.begin(), vec.end(),isUpper);
	if (end_it != vec.end())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
bool isNum(const char& ch)
{
	return ch >= '0'&&ch <= '9';
}
//使用all_of
void _all_of_()
{
	string number = "12a456789";
	//algorithm
	bool flag = all_of(number.begin(), number.end(), isNum);
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
//next_permutation
void _next_permutation_(void)
{
	string msg = "123";
	do
	{
		cout << msg << endl;
	} while (next_permutation(msg.begin(), msg.end()));
}
//查询一个数组是不是递增的
void _check_arr_()
{
	int arr[5] = { 0,2,3,4,5 };
	vector<int> vec(begin(arr), end(arr));
	vector<int> _vec(vec);
	sort(vec.begin(), vec.end());
	/*sort(begin(arr), end(arr));*/
	bool flag = equal(vec.begin(), vec.end(), _vec.begin(), _vec.end());
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
//上一题利用递归
bool isArrUp(int* arr, int length, int index=0);
bool isArrUp(int* arr, int length, int index)
{
	if (index == length - 1)
		return true;
	return arr[index] < arr[index + 1] ? isArrUp(arr, length, ++index) : false;
}
struct Person {
	string name;
	vector<string> phone;
};
void telephone(void)
{
	ifstream in("1.txt", ios::in);
	string word;
	vector<Person> people;
	string _word;
	while (getline(in,word))
	{		
		Person self;
		istringstream ss(word);
		ss >> self.name;
		while (ss>>_word)
		{
			self.phone.push_back(_word);
		}
		people.push_back(self);
	}
	in.close();
	ofstream out("1.txt", ios::app);
	out << "\n";
	while (getline(cin,word))
	{
		out << word;
	}
	out.close();
}
//c风格文件操作读取
void _cfile_r()
{
	FILE *pf;
	pf = fopen("1.txt", "r");
	if (!pf)
	{
		cout << "Open Filed!" << endl;
		exit(0);
	}
	char ch;
	while ((ch = fgetc(pf)) != EOF)
	{
		cout << ch;
	}
	fclose(pf);
}
//c风格文件操作写入
void _cfile_w()
{
	FILE *pf;
	pf = fopen("1.txt", "a");
	if (!pf)
	{
		printf("文件打开失败!");
		exit(0);
	}
	char ch;
	fputc('\n', pf);
	while ((ch=getchar())!='@')
	{
		fputc(ch,pf);
	}
	fclose(pf);
}
///链表复习
struct List {
	int data;
	struct List* next;
};
struct List* CreatList()
{
	List* head, *temp, *link;
	int i;
	scanf("%d", &i);
	head = (struct List*)malloc(sizeof(struct List));
	temp = head;
	temp->next = NULL;
	while (i != -111)
	{		
		link = (struct List*)malloc(sizeof(struct List));
		link->data = i;
		link->next = NULL;
		temp->next = link;
		temp = link;	
		scanf("%d", &i);
	}
	return head;
}
void InserData(struct List* list,int data, int pos)
{
	struct List *temp, *link;
	int index = 1;
	temp = list->next;
	while (temp!=NULL&&index<pos-1)
	{
		++index;
		temp = temp->next;
	}
	link = (struct List*)malloc(sizeof(struct List));
	link->data = data;
	link->next = temp->next;
	temp->next = link;
}
int DeleteList(struct List* list, int pos)
{
	struct List* temp = list->next;
	int index = 1;
	while (temp!=NULL&&index<pos-1)
	{
		temp = temp->next;
		++index;
	}
	struct List* link = temp->next;
	int x = link->data;
	temp->next = link->next;
	free(link);
	return x;
}
void OutPutList(struct List* list)
{
	struct List* temp = list->next;
	while (temp!=NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	struct List* list = CreatList();
	OutPutList(list);
	InserData(list, 10, 2);
	OutPutList(list);
	DeleteList(list, 2);
	OutPutList(list);
	return 0;
}