/*采用数组实现哈希表*/ 

#include<stdio.h>
#define DataType int
#define Len 10

typedef struct HashNode    
{
	DataType data;    //存储值 
	int isNull;       //标志该位置是否已被填充 
}HashTable;

HashTable hashTable[Len];

void initHashTable()     //对hash表进行初始化 
{
	int i;
	for(i = 0; i<Len; i++)
	{
		hashTable[i].isNull = 1;    //初始状态为空 
	}
}

int getHashAddress(DataType key)    //Hash函数 
{
	return key * 3 % 7;      
}

int insert(DataType key)    
{
	int address = getHashAddress(key);       
	if(hashTable[address].isNull == 1)  //没有发生冲突 
	{
		hashTable[address].data = key;
		hashTable[address].isNull = 0;
	}
	else    //当发生冲突的时候 
	{
		while(hashTable[address].isNull == 0 && address<Len)
		{
			address++;          //采用线性探测法，步长为1 
		}
		if(address == Len)      //Hash表发生溢出 
			return -1;
		hashTable[address].data = key;
		hashTable[address].isNull = 0;
	}

	return 0;
}

int find(DataType key)
{
	int address = getHashAddress(key);
	while( !(hashTable[address].isNull == 0 && hashTable[address].data == key && address<Len))
	{
		address++;
	} 

	if( address == Len)
	{
		address = -1;
	}

	return address;
}


int main(int argc, char *argv[])
{
	int key[]={7,8,30,11,18,9,14,10,13};
	int i;
	initHashTable();

	for(i = 0; i<9; i++)
	{
		insert(key[i]);
	}

	for(i = 0; i<9; i++)
	{
		int address;
		address = find(key[i]);
		printf("key:%d\t address:%d\t hashTable[%d]:%d\n", key[i],address,address,hashTable[address].data);
	}

	for(i = 0; i<9; i++)
	{
		int address;
		address = getHashAddress(key[i]);
		printf("%d\n", address);
	} 
	return 0;
}
