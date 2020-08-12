//###########################################
//		归并排序算法步骤
//1.申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
//2.设定两个指针，最初位置分别为两个已经排序序列的起始位置；
//3.比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
//4.重复步骤 3 直到某一指针达到序列尾；
//5.将另一序列剩下的所有元素直接复制到合并序列尾。
//##########################################################
#include <stdio.h>

#define frond 0 //前部
#define rear 1 //后部 

int MergeSortHandl_TwoBlack(int array[], int left, int right, int len)
{
//	printf("%d %d\n", left,right);
	if(left >= right) //判断是否到末尾
		return (len *= 2);

	int a_index = left;
	int b_index = left+len;
	int t_index = 0;
	int tempArry [len*2];//存放两个数据的地址
	if(len == 1)
	{
		if(array[a_index] < array[b_index])
		{
			tempArry[t_index++] = array[a_index];
			tempArry[t_index] = array[b_index];
//			printf("%d %d\n",tempArry[t_index-1],tempArry[t_index] );
		}
		else
		{
			tempArry[t_index++] = array[b_index];
			tempArry[t_index] = array[a_index];
//			printf("%d %d\n",tempArry[t_index-1],tempArry[t_index] );
		}
	}
	else
	{
//		printf("%d %d\n", left,right);
		int complate = 0;
		while(1)
		{
			if (complate == 0x01)
			{
				tempArry[t_index] = array[b_index];
				t_index ++;
				if(b_index + 1 < left + 2*len && b_index + 1 <= right)
					b_index++;
				else
					complate |= 0x02;
			}
			else if(complate == 0x02)
			{
				tempArry[t_index] = array[a_index];
				t_index ++;
				if(a_index + 1 < left + len && a_index + 1 <= right)
					a_index++;
				else
					complate |= 0x01;
			}
			else if(array[a_index] < array[b_index])
			{
				tempArry[t_index] = array[a_index];
				t_index ++;
				if(a_index + 1 < left + len && a_index + 1 <= right)
					a_index++;
				else
					complate |= 0x01;
			}
			else
			{
				tempArry[t_index] = array[b_index];
				t_index ++;
				if(b_index + 1 < left + 2*len && b_index + 1 <= right)
					b_index++;
				else
					complate |= 0x02;
			}
//			printf("%d\n", complate);
			if(complate == 0x03)
				break;
		}
	}
	for(int i = 0;i < 2*len ;i++)
	{
		array[left+i] = tempArry[i];
	}
	len = MergeSortHandl_TwoBlack(array, left + 2*len , right , len);
//	if(len = 0)
//	return 0;
//	else
//	MergeSortHandl_TwoBlack(array, 0, right , len);
	return len;
}

int MergeSort(int array[], int left, int right)
{
	int len = 1;
	while(1)
	{
		len = MergeSortHandl_TwoBlack(array, left, right, len );
//		printf("%d\n", len);
		if(len > right)
			break;	
	}
	return 0;
}

int main(void)
{
	int array[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
	for(int i =0 ;i < sizeof(array)/4; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	MergeSort(array,0,(sizeof(array)/4-1));
	for(int i =0 ;i < sizeof(array)/4; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	return 0;
}