////////////////////////////////////////////////////////////////////////////////////
///	BFPRT算法:
///		1.先将数组五个五个分组.
///		2.在五个元素数组内进行排序,找出中位数.
///		3.将每五组的中位数取出,并置于数组前部.
///		4.将中位数组成的数组再次重复1-3步的嵌入操作,直到找出唯一一个中位数
///		5.将那个唯一的中位数置于数组尾部.
///		6.遍历数组,若小于中位数的置于左侧,大于中位数的置于右侧
///		7.判断所需要的值大于该中位数就嵌入右侧数组,执行1-6操作,小于反之，直至找出等于
////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
//#include<algorithm>
using namespace std;

int InsertSort(int  array[], int left, int right);                 //插入排序，返回中位数下标
int GetPivotIndex(int  array[], int left, int right);              //返回中位数的中位数下标
int Partition(int array[], int left, int right, int pivot_index);  //利用中位数的中位数的下标进行划分，返回分界线下标
int BFPRT(int array[], int left, int right, const int & k);        //求第k小，返回其位置的下标

/* 插入排序，返回中位数下标 */
int InsertSort(int array[], int left, int right)
{
	int temp;
	int j;
	for (int i = left + 1; i <= right; i++)
	{
		temp = array[i];
//		for(j = i - 1; j >= left; j--)
//		{
//			if(array[j] > temp)
//			{
//				array[j+1] = array[j];
//				array[j] = temp;
//			}
//		}
		j = i - 1;
		while (j >= left && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j+1] = temp;
//		for(int z = 0;z < 5; z++)
//			cout << array[z] << " ";
//		cout << endl;
	}

	return ((right - left) >> 1) + left;
}

/* 返回中位数的中位数下标 */
int GetPivotIndex(int array[], int left, int right)
{
	if (right - left < 5)
		return InsertSort(array, left, right);

	int sub_right = left - 1;
	//将数组分割,没五个元素为为一组,并进行排序,然后将每组的中位数置数组的前列
	for (int i = left; i + 4 <= right; i += 5)
	{
		int index = InsertSort(array, i, i + 4);  //找到五个元素的中位数的下标
		swap(array[++sub_right], array[index]);   //依次放在左侧
//		for (int i = 0; i < 10; i++)
//			cout << array[i] << " ";
//		cout << endl;
	}
	return BFPRT(array, left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

/* 利用中位数的中位数的下标进行划分，返回分界线下标 */
int Partition(int array[], int left, int right, int pivot_index)
{
	swap(array[pivot_index], array[right]);  //把基准放置于末尾

	int divide_index = left;  //跟踪划分的分界线
	for (int i = left; i < right; i++)
	{
		if (array[i] < array[right])
			swap(array[divide_index++], array[i]);  //比基准小的都放在左侧
	}

	swap(array[divide_index], array[right]);  //最后把基准换回来
	return divide_index;
}

int BFPRT(int array[], int left, int right, const int & k)
{
	int pivot_index = GetPivotIndex(array, left, right);            //得到中位数的中位数下标
	int divide_index = Partition(array, left, right, pivot_index);  //进行划分，返回划分边界
	int num = divide_index - left + 1;
	if (num == k)
		return divide_index;
	else if (num > k)
		return BFPRT(array, left, divide_index - 1, k);
	else
		return BFPRT(array, divide_index + 1, right, k - num);
}

int main()
{
	int k = 3;
	int array[10] = { 1,1,2,3,1,5,-1,7,8,-10 };

	cout << "原数组：";
	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;

	cout << "第" << k << "小值为：" << array[BFPRT(array, 0, 9, k)] << endl;

	cout << "变换后的数组：";
	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}
