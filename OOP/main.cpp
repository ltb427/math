#include<iostream>
#include<string>

using namespace std;

class Quote
{
public:
	Quote() = default;
	virtual ~Quote() { cout << "基类析构函数" << endl; }
	Quote(const string& bookno,const double& price):bookNo(bookno),price(price){}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n)const
	{
		return n*price;
	}
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote:public Quote
{
public:
	Bulk_quote() = default;
	~Bulk_quote() { cout << "派生类析构函数" << endl; }
	Bulk_quote(const string&book, double price, size_t ctn, double disc):Quote(book,price),min_qty(ctn),discount(disc){}
	double net_price(size_t)const override;
private:
	size_t min_qty = 0;
	double discount = 0;
};



double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt*(1 - discount)*price;
	else
		return cnt*price;
}
struct demo {
	char c;//4
};
union MyUnion
{
	short c;
	short i;
};
typedef int(*pf)(int , int );
int max(int a, int b)
{
	return a > b ? a : b;
}
enum MyEnum
{
	man,
	woman,
	child
};
int main()
{
	MyEnum unm;
	cout << sizeof(unm) << endl;
}