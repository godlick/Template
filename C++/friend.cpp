#include <iostream>
using namespace std;//使用标准命名空间
//==========================================
 //认识友元的概念  //声明友元可访问类的所有数据
//==========================================

class A
{
public:
	A();
	~A();
	friend class Friend;  //声明Friend是友元类

	friend void friendShow_A();
	int pu;
protected:
	int pro;
private:
	int pri;
};
//类外内联函数
inline A::A()
{
	pu = 1;
	pro = 2;
	pri = 3;
}
inline A::~A(){}

class Friend
{
public:

	A a;
	//内联函数
	void show_A()  //友元类可以访问类A中所有数据(包括私有变量)
	{
		cout << "public:" << a.pu <<endl;
		cout << "protected:" << a.pro <<endl;
		cout << "private:" << a.pri <<endl;
	}
};

class NotFriend
{
public:

	A a;
	//内联函数
	void show_A()  //不是友元类只能访问公有变量
	{
		cout << "public:	" << a.pu <<endl;
//		cout << "protected:	" << a.pro <<endl; //error: ‘int A::pro’ is protected within this context
//		cout << "private:	" << a.pri <<endl; //error: ‘int A::pri’ is private within this context
	}
};

void friendShow_A()
{
	A a;
	cout << "public:" << a.pu <<endl;
	cout << "protected:" << a.pro <<endl;
	cout << "private:" << a.pri <<endl;
}

void NotFriendShow_A() //非友元函数只能访问公有变量
{
	A a;
	cout << "public:" << a.pu <<endl;
//	cout << "protected:" << a.pro <<endl;	//error: ‘int A::pro’ is protected within this context
//	cout << "private:" << a.pri <<endl;		//error: ‘int A::pri’ is private within this context
}

int main(int argc, char const *argv[])
{
	cout << "=====================友元类===================" << endl;
	Friend f;
	f.show_A();
	NotFriend nf;
	nf.show_A();
	cout << "====================友元函数==================" << endl;
	friendShow_A();
	NotFriendShow_A();
	return 0;
}