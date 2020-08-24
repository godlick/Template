#include <iostream>
////C++的内存地址问题
using namespace std;

////////////////////////////////
//		命令行参数&环境变量
//
//		内存栈区			H
//
//		共享区
//
//		内存堆区
//
//		静态区
//		常量区			L
//
//		代码区
////////////////////////////////

int a = 100; //全局变量
int main(int argc, char const *argv[])
{
	cout << "局部变量" << endl;   //内存栈区 //数据无论初始还是未初始分布都相邻
	int b = 20; //局部变量
	int b1;
	cout << "			b的地址: " << &b << " b=" << b <<endl;
	cout << "			b1的地址: " << &b1 << endl;

	cout << "new申请的变量区域" << endl;//内存堆区  需手动回收区域
	int *d = new int;
	*d = b;
	cout << "			*d = " << d << "   *d=" << *d <<endl;

	cout << "malloc申请的变量区域" << endl;//内存堆区 需手动回收区域
	int *e = NULL;
	e = (int *)malloc(sizeof(int));
	*e = b;
	cout << "			*e = " << e << "   *e=" << *e <<endl;

	cout << "全局变量" << endl;  //静态区
	cout << "			a的地址: " << &a << " a=" << a <<endl;

	cout << "静态局部变量" << endl;//静态区  //数据初始与未初始分布不相邻
	static int c = 30; //静态局部变量
	static int c1 = 20;
	static int c2;
	cout << "			c的地址: " << &c << " c=" << c <<endl;
	cout << "			c1的地址: " << &c1 <<endl;
	cout << "			c2的地址: " << &c2 <<endl;

	cout << "常量数据" << endl;
	cout << "			'123456'的地址: " << (void*)("123456") <<endl;

	free(e);
	delete d;
	/* code */
	return 0;
}