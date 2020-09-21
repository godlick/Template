#include <iostream>
#include <cstring>
#include <vector> //使用容器vector
using namespace std;

#define av if(a == v)\
	{\
		cout<< "==" << endl;\
	}\
	else if(a > v)\
	{\
		cout<< ">" << endl;\
	}\
	else\
	{\
		cout<< "<" << endl;\
	}


void knowFun_new(void)
{
	int a[2] = {1,3};
	int *p = new int[2];
	cout << *p << " " << *(p+1) << endl;
	memcpy(p, a, sizeof(int)*2);
	cout << *p << " " << *(p+1) << endl;
	cout << p << endl;
	cout << p+1 << endl;
	cout << p+2 <<endl;
	int *p1 = new int[1];
	int *p2 = new int[1];
	cout << p1 << endl;
	cout << p2 << endl;
	*(p+1) = 1;
	delete[] p;  //指针指向的空间的数据清零 指针P还是指向原本的地址
	cout << *(p + 1) << endl;
}
/*
（1）a.assign(b.begin(), b.begin()+3); //b为向量，将b的0~2个元素构成的向量赋给a
（2）a.assign(4,2); //是a只含4个元素，且每个元素为2
（3）a.back(); //返回a的最后一个元素
（4）a.front(); //返回a的第一个元素
（5）a[i]; //返回a的第i个元素，当且仅当a[i]存在2013-12-07
（6）a.clear(); //清空a中的元素
（7）a.empty(); //判断a是否为空，空则返回ture,不空则返回false
（8）a.pop_back(); //删除a向量的最后一个元素
（9）a.erase(a.begin()+1,a.begin()+3); //删除a中第1个（从第0个算起）到第2个元素，也就是说删除的元素从a.begin()+1算起（包括它）一直到a.begin()+         3（不包括它）
（10）a.push_back(5); //在a的最后一个向量后插入一个元素，其值为5
（11）a.insert(a.begin()+1,5); //在a的第1个元素（从第0个算起）的位置插入数值5，如a为1,2,3,4，插入元素后为1,5,2,3,4
（12）a.insert(a.begin()+1,3,5); //在a的第1个元素（从第0个算起）的位置插入3个数，其值都为5
（13）a.insert(a.begin()+1,b+3,b+6); //b为数组，在a的第1个元素（从第0个算起）的位置插入b的第3个元素到第5个元素（不包括b+6），如b为1,2,3,4,5,9,8         ，插入元素后为1,4,5,9,2,3,4,5,9,8
（14）a.size(); //返回a中元素的个数；
（15）a.capacity(); //返回a在内存中总共可以容纳的元素个数
（16）a.resize(10); //将a的现有元素个数调至10个，多则删，少则补，其值随机
（17）a.resize(10,2); //将a的现有元素个数调至10个，多则删，少则补，其值为2
（18）a.reserve(100); //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才         显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能） 
（19）a.swap(b); //b为向量，将a中的元素和b中的元素进行整体性交换
（20）a==b; //b为向量，向量的比较操作还有!=,>=,<=,>,<
  */
void knowFun_vector(void)
{
	vector<int> a; //定义 a 数组，当前数组长度为 0，但和普通数组不同的是，此数组 a 可以根据存储数据的数量自动变长。
	vector<int> v;
	av  //向量比较与字符串比较相一致
	for (int i = 0; i < 10 ; i++)
	{
		a.push_back(i);	
	}
	for (int i = 0; i < 2 ; i++)
	{
		v.push_back(1);	
	}
	av
}
void know_iterator(void)
{
	//容器类名::iterator  迭代器名; 				正向迭代器
	//容器类名::const_iterator  迭代器名;			常量正向迭代器
	//容器类名::reverse_iterator  迭代器名;		反向迭代器
	//容器类名::const_reverse_iterator  迭代器名;	常量反向迭代器
		//创建向量v
	vector<int> v;  //v是存放int类型变量的可变长数组，开始时没有元素
	for (int n = 0; n<5; ++n)
		v.push_back(n+1);  //push_back成员函数在vector容器尾部添加一个元素

	vector<int>::iterator i;  //定义正向迭代器
	for (i = v.begin(); i != v.end(); ++i) {  //用迭代器遍历容器
		cout << *i << " ";  //*i 就是迭代器i指向的元素
	}
	cout << endl;
	vector<int>::reverse_iterator j; //定义反向迭代器
	for (j = v.rbegin(); j != v.rend(); ++j)
		cout << *j << " ";
	cout << endl;

//begin 成员函数返回指向容器中第一个元素的迭代器
//end 成员函数返回的不是指向最后一个元素的迭代器，而是指向最后一个元素后面的位置的迭代器
//rbegin 成员函数返回指向容器中最后一个元素的迭代器
//rend 成员函数返回指向容器中第一个元素前面的位置的迭代器
	cout << *(v.begin()) << " " << *(v.rbegin()) <<endl;
	cout << *(v.end()-1) << " " << *(v.rend()-1) <<endl;

}

int main(void)
{
//	knowFun_new();
//	knowFun_vector();
	know_iterator();
	return 0;
}