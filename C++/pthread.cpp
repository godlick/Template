#include <iostream>
#include <pthread.h> //多线程相关操作头文件，可移植众多平台
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5 //线程数

void* say_hello( void* args )
{
    int i = *( (int*)args );
    cout << "hello..." << i << endl;

    int status = 10 + *(( int * )args); //线程退出时添加退出的信息，status供主程序提取该线程的结束信息  
    pthread_exit( ( void* )status );
} //函数返回的是函数指针，便于后面作为参数

class Hello
{
public:
    static void* say_hello( void* args )
    {
        int i = *( (int*)args );
        cout << "hello..." << i << endl;
    }
};

int main()
{
    pthread_t tids[NUM_THREADS+5+5]; //线程id
    int indexes[NUM_THREADS]; //用来保存i的值避免被修改 
    cout << "线程共用内存不同线程共用一个i值" <<endl;
    for( int i = 0; i < NUM_THREADS; ++i )
    {
        int ret = pthread_create( &tids[i], NULL, say_hello, (void*)&i ); //参数：创建的线程id，线程参数，线程运行函数的起始地址，运行函数的参数
        if( ret != 0 ) //创建线程成功返回0
        {
            cout << "pthread_create error:error_code=" << ret << endl;
        }
    }
//    pthread_exit( NULL ); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态
    sleep(1);
    cout << "不调用i的值，现象：" <<endl;
    for( int i = 0; i < NUM_THREADS; ++i )
    {
        indexes[i] = i;
        int ret = pthread_create( &tids[i+5], NULL, say_hello, (void*)&indexes[i] ); //参数：创建的线程id，线程参数，线程运行函数的起始地址，运行函数的参数
        if( ret != 0 ) //创建线程成功返回0
        {
            cout << "pthread_create error:error_code=" << ret << endl;
        }
    }

    sleep(1);
/*线程的属性由结构体pthread_attr_t进行管理。
typedef struct
{
	int					detachstate;     线程的分离状态
	int                schedpolicy;     线程调度策略
    struct sched_param schedparam;      线程的调度参数
    int                inheritsched;    线程的继承性 
    int                scope;           线程的作用域 
    size_t             guardsize;       线程栈末尾的警戒缓冲区大小 
    int                stackaddr_set; 
    void *             stackaddr;       线程栈的位置 
    size_t             stacksize;       线程栈的大小
}pthread_attr_t;
*/
    cout << "使用线程属性结构体pthread_attr_t:：" <<endl;
    pthread_attr_t attr; //线程属性结构体，创建线程时加入的参数 
    pthread_attr_init( &attr ); //初始化
    pthread_attr_setdetachstate( &attr, PTHREAD_CREATE_JOINABLE ); 
    //是设置你想要指定线程属性参数，这个参数表明这个线程是可以join连接的，
    //join功能表示主程序可以等线程结束后再去做某事，实现了主程序和线程同步功能

    for( int i = 0; i < NUM_THREADS; ++i )
    {
    	indexes[i] = i;
        int ret = pthread_create( &tids[i+10], &attr, say_hello, ( void* )&( indexes[i] ) );
        if( ret != 0 )
        {
        	cout << "pthread_create error:error_code=" << ret << endl;
        }
    }
    pthread_attr_destroy( &attr ); //释放内存
    void *status;
    for( int i = 0; i < NUM_THREADS; ++i )
    {
		int ret = pthread_join( tids[i+10], &status ); //主程序join每个线程后取得每个线程的退出信息status
		if( ret != 0 )
		{
			cout << "pthread_join error:error_code=" << ret << endl;
		}
		else
		{
			cout << "pthread_join get status:" << (long)status << endl;
		}
    }

    //没有下列的阻塞方式，会导致线程没有执行，进程却已经结束的现象
#if 1
    for( int i = 0; i < NUM_THREADS+5; ++i )  
        pthread_join( tids[i], NULL ); //pthread_join用来等待一个线程的结束，是一个线程阻塞的函数
#else
    pthread_exit( NULL ); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态  
#endif

}