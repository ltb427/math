#include<iostream>
#include<string>
using namespace std;

//行为像值的类
class HasVal
{
public:
	HasVal();
	~HasVal();
	HasVal(const string&str,const int& i):ptr(new string(str)),i(i){}
	HasVal(const HasVal& other):ptr(new string(*other.ptr)),i(other.i){}
	HasVal& operator=(const HasVal& other);
private:
	string* ptr;
	int i;
};

HasVal::HasVal()
{
}

HasVal::~HasVal()
{
	delete ptr;
}



HasVal & HasVal::operator=(const HasVal & other)
{
	// TODO: 在此处插入 return 语句
	auto newp = new string(*other.ptr);
	delete ptr;
	ptr = newp;
	i = other.i;
	return *this;
}

//行为像指针的类
class HasPtr
{
public:
	HasPtr();
	HasPtr(const string&str,const int&i):ptr(new string(str)),i(i),use(new size_t(1)){}
	~HasPtr();
	HasPtr(const HasPtr& other) :ptr(other.ptr), i(other.i),use(other.use) { ++*use; }
	HasPtr& operator=(const HasPtr& other);
private:
	string* ptr;
	int i;
	size_t* use;
};

HasPtr::HasPtr()
{
}

HasPtr::~HasPtr()
{
	if (--*use==0)
	{
		delete ptr;
		delete use;
	}
	cout << "全部删除啦!" << endl;
}



HasPtr & HasPtr::operator=(const HasPtr & other)
{
	// TODO: 在此处插入 return 语句
	if (--*use == 0)
	{
		delete ptr;
		delete use;
		cout << "左侧删除了" << endl;
	}
	ptr = other.ptr;
	i = other.i;
	++(*other.use);
	use = other.use;
	return *this;
}

int main()
{
	HasVal* val = new HasVal("yukai", 25);
	HasPtr ptr("于凯", 24);
	HasPtr ptr1 = ptr;
	HasPtr pst2 = ptr;
	ptr = ptr1;
	return 0;
}
