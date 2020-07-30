/////////////////////////////////////////////
//插入排序
///////////////////////////////////////////
#include <stdio.h>

int InsertSort(int array[], int left, int right)
{
	int temp;
	int j;

	for (int i = left + 1; i <= right; i++)
	{
		temp = array[i];
        j = i - 1;

		while (j >= left && array[j] > temp)
		{
			array[j + 1] = array[j];
			j--;
	    }
		array[j+1] = temp;
	}
	return 0;
}

int main(void)
{
	int array[5] = {10,32,30,9,2};
	for(int i =0 ;i < 5; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	InsertSort(array,0,4);
	for(int i =0 ;i < 5; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	return 0;
}
