///////////////////////////////////////////////////////////////////
//快速排序
//快速排序算法通过多次比较和交换来实现排序，其排序流程如下：
//(1)首先设定一个分界值，通过该分界值将数组分成左右两部分。 
//(2)将大于或等于分界值的数据集中到数组右边，小于分界值的数据集中到数组的左边。
//	 此时，左边部分中各元素都小于或等于分界值，而右边部分中各元素都大于或等于分界值。 
//(3)然后，左边和右边的数据可以独立排序。对于左侧的数组数据，又可以取一个分界值，
//	 将该部分数据分成左右两部分，同样在左边放置较小值，右边放置较大值。右侧的数组数据也可以做类似处理。 
//(4)重复上述过程，可以看出，这是一个递归定义。通过递归将左侧部分排好序后，再递归排好右侧部分的顺序。
//	 当左、右两个部分各数据排序完成后，整个数组的排序也就完成了。

//时间复杂度：
//最好：O(n log2 n)
//最坏：O(n^2)
//平均：O(n log2 n)
//空间复杂度：O(n log2 n)
//稳定性：不稳定
////////////////////////////////////////////////////////////////////
#include <stdio.h>

int QuickSort_left(int array[],int left,int right, int temp)
{
	if(right == left)
	{
		array[left] = temp;
		return left;
	}
	if(array[left] < temp)
	{
		QuickSort_left(array,left+1,right,temp);
	}
	else
	{
		array[right] = array[left];
		QuickSort_right(array,left,right-1,temp);
	}
}

int QuickSort_right(int array[],int left,int right, int temp)
{
	if(right == left)
	{
		array[left] = temp;//轴心选择首元素  //随机快速排序是在区间内随机选取一个元素，与首地址交换，作为轴心
		return left;
	}
	if(array[right] > temp)
	{
		QuickSort_right(array,left,right-1,temp);
	}
	else
	{
		array[left] = array[right];
		QuickSort_left(array,left+1,right,temp);
	}
}

void QuickSort(int array[],int left, int right)
{
	int temp = array[left];
	int mid_index = QuickSort_right(array,left,right,temp);
	if(left < mid_index)
	{
		QuickSort(array,left,mid_index-1);
	}
	if(right > mid_index)
	{
		QuickSort(array,mid_index+1,right);
	}
	return ;
}

int main(void)
{
	int array[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
	for(int i =0 ;i < sizeof(array)/4; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	QuickSort(array,0,(sizeof(array)/4-1));
	for(int i =0 ;i < sizeof(array)/4; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	return 0;
}