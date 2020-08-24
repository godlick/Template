#include <iostream>
///C++的继承
using namespace std;

class PARENT
{
private:	//私有的
	int p1;
protected:	//受保护的
	int p2;
public:		//公有的
	//默认构造函数和析构函数
	PARENT();
	~PARENT();
	int p3;
};
PARENT::PARENT()
{
	p1 = 1;
	p2 = 2;
	p3 = 3;
}
PARENT::~PARENT()
{

}
// public继承时： 
//		父类public -> 子类public
//		父类protected -> 子类protected
//		父类private 无法被继承
class SON:public PARENT //子类包含成员p2 和 p3
{
public:
	SON();
	~SON();
	void show_p2();
	
};
SON::SON()
{
	//子类成员不包含父类私有变量
//	p1 = 1;		//error: ‘int PARENT::p1’ is private within this context
	p2 = 2;
	p3 = 3;
}
SON::~SON()
{

}
void SON::show_p2()
{
	printf("%d\n", p2);
}

// protected继承时： 
//		父类public -> 子类protected
//		父类protected -> 子类protected
//		父类private 无法被继承
class SON1:protected PARENT //子类包含成员p2 和 p3
{
public:
	SON1();
	~SON1();
	void show_p2p3();
};
SON1::SON1()
{
	p2 = 2;
	p3 = 3;
}
SON1::~SON1()
{}
void SON1::show_p2p3()
{
	printf("%d\n", p2);
	printf("%d\n", p3);
}
// private继承时： 
//		父类public -> 子类private
//		父类protected -> 子类private
//		父类private 无法被继承
//protected 和 private 的区别就是private不能被继承

int main(int argc, char const *argv[])
{
	SON s;
	//类外不允许调用protected变量
//	printf("%d\n", s.p2);		//error: ‘int PARENT::p2’ is protected within this context
	s.show_p2();			//可通过类内接口函数访问变量
	printf("%d\n", s.p3);

	SON1 s1;
//	printf("%d\n", s1.p2);	//error: ‘int PARENT::p2’ is protected within this context
//	printf("%d\n", s1.p3);	//error: ‘int PARENT::p3’ is inaccessible within this context
	s1.show_p2p3();
	return 0;
}
