#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    vector<int> a(10, 2) ;      //大小为10初值为0的向量a
    int i ;
    for(i=0; i<a.size(); i++)
        cout<<a[i]<<" " ;
    cout << endl;
 
    //全部输出
    vector<int> b(a) ;//声明向量b，用a来初始化b    
    for(i=0; i<b.size(); i++)
        cout<<b[i]<<" " ;
    cout << endl;

    int n[] = {1, 2, 3, 4, 5} ;
    vector<int> c(n, n+5) ;              //将数组n的前5个元素作为向量a的初值
    for(i=0; i<c.size(); i++)
        cout<<c[i]<<" " ;
    cout << endl;
    
    vector<int> d(&n[1], &n[4]) ;        //将n[1] - n[4]范围内的元素作为向量a的初值 &n[4]为首地址，故不包含n[4]的数据
    cout << d.size()<<endl;
    for(i=0; i<d.size(); i++)
        cout<<d[i]<<" " ;
    cout << endl;

    return 0 ;
}