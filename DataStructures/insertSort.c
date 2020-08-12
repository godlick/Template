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
	int array[] = {44,3,38,5,47,15,36,26,27,2,46,4,19,50,48};
	for(int i =0 ;i < sizeof(array)/4; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	InsertSort(array,0,sizeof(array)/4 -1);
	for(int i =0 ;i < sizeof(array)/4; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	return 0;
}
