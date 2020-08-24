#include <iostream>
////C++的多态性
using namespace std;

class A
{
public:
	A();
	~A();
	virtual void show();
};
A::A()
{}
A::~A()
{}
void A::show()
{
	cout << "A的函数" <<endl;
}
class B:public A
{
public:
	B();
	~B();
	virtual void show();
};
B::B()
{}
B::~B()
{}
void B::show()
{
	cout <<"B的函数" << endl;
}

int main(int argc, char const *argv[])
{
	A a;
	a.show();	// 运行结果:A的函数
	
	B b;
	b.A::show();// 运行结果:A的函数 //子类象调用父类虚函数
	b.show();	// 运行结果:B的函数
	
	//父类对象指针指向子类对象地址,结果运行子类函数
	A *p,*p1;
	p = &a;
	p1 = &b;
	p->show();	// 运行结果:A的函数

	p1->A::show();// 运行结果:A的函数
	p1->show();	// 运行结果:B的函数
	return 0;
}