////////////////////////////////////////////
//选择排序
///////////////////////////////////////////
#include <stdio.h>

int SelectSort(int array[], int left, int right)
{	
	for(int i = left; i <= right; i++)
	{
		int arrayMin = array[i];
		int index = i;//记录最小值下标；
		for(int j = i; j <= right; j++)
			if(array[j] < arrayMin)
			{
				arrayMin = array[j];
				index = j;
			}
		int temp = array[i];
		array[i] = array[index];
		array[index] = temp;
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
	SelectSort(array,0,4);
	for(int i =0 ;i < 5; i++)
	{
		printf("%d " , array[i]);
	}
	printf("%c",'\n');
	return 0;
}