#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
	MyString(const char *str = nullptr);//构造函数
	MyString(const MyString &str);//拷贝函数
	//运算符重写
	MyString& operator=(const MyString &str);
	void MyStringShow();//类显示函数
	
	~MyString();//析构函数
	
private:
	char *m_data;//类数据，外部不可访问
	int m_size; //类大小，外部不可访问
};

// 构造函数
MyString::MyString(const char *str) //类外要使用类名给定区域MyString，第一个为类名MyString，第二个为构造函数名
{
	//new 为申请空间存放数据
	if(str == nullptr)  // 对m_data加NULL 判断
	{
		m_data = new char[1];   //对空字符串自动申请存放结束标志'\0'的
		m_data[0] = '\0';
		m_size = 0;
	}
	else
	{
		m_size = strlen(str);
		m_data = new char[m_size + 1];
		strcpy(m_data, str);
	}
}

// 拷贝构造函数
MyString::MyString(const MyString &str)   // 输入参数为const型，固定不可更改
{
	m_size = str.m_size;
	m_data = new char[m_size + 1];  //对m_data加NULL 判断
	strcpy(m_data, str.m_data);
}

// 析构函数
MyString::~MyString()
{
//	delete[] m_data;
}

MyString& MyString::operator=(const MyString &str)  //这是对类MyString的=运算符的重写 
{
	if(this != &str)   //检查自赋值
	{
//		MyString strTemp(str);//类申请变量strTemp 并将形参的str的值传给strTemp（拷贝构造函数）

//		char* pTemp = strTemp.m_data;
//		strTemp.m_data = m_data;
//		m_data = pTemp;
//		m_size = strTemp.m_size;
		m_data = str.m_data;
		m_size = str.m_size;

	}
	return *this;  //返回本对象的引用
}

void MyString::MyStringShow()
{
	cout << "m_size: " << m_size <<endl;
	cout << "m_data: ";
	for(int i = 0; i < m_size; i++)
		cout << m_data[i];
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	char *cc = "yshsdsb";
	MyString mstr(cc); //普通构造一个类变量
	cout << "普通cc:" <<endl;
	mstr.MyStringShow();

	MyString cpstr(mstr); //拷贝构造
	cout << "拷贝cc:" <<endl;
	cpstr.MyStringShow();

	char *cf = "00";
	MyString sstr(cf);//普通构造一个类
	sstr = mstr;
	cout << "赋值cc:" <<endl;
	sstr.MyStringShow();
	return 0;
}