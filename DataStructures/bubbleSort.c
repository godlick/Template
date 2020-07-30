/////////////////////////////////
//冒泡排序
/////////////////////////////////
#include <stdio.h>

int BubbleSort(int array[], int left, int right)
{
	for(int i = left; i < right; i++)
	{
		for(int j = 0; j < right - i; j++)
			if(array[j] > array[j+1])
			{
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
	}	
	return 1;
}

int main(void)
{
	int array[5] = {10,32,30,9,2};
	for(int i =0 ;i < 5; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	BubbleSort(array,0,4);
	for(int i =0 ;i < 5; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	return 0;
}

