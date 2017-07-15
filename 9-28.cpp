#include <stdio.h>
#include <stdlib.h>
#define MAXSSLENGTH 7
#define MAXBLOCK 5
#define PERBLOCKSIZE 4
typedef struct Index
{
	int max;//这个块的最大值
	int address;//这个块的起始地址
}Index; 
typedef struct IndexTable
{
	Index *elem;
	int blockSize;
}IndexTable;
typedef struct SSTable
{
	int *elem;//下标从1开始
	int length;
}SSTable;
//利用折半查找，查找元素所在块。
int search_Index_Bin(IndexTable it,int key)
{
	if (key<it.elem[0].max)
	{
		return 0;
	}
	if (key>it.elem[it.blockSize-1].max)
	{
		return it.blockSize - 1;
	}
	int low = 0;
	int high = it.blockSize - 1;
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (key >= it.elem[mid].max&&key < it.elem[mid + 1].max)
		{
			return mid;
		}
		else if (key < it.elem[mid].max)
		{
			high = mid - 1;
		}
		else if (key >= it.elem[mid + 1].max)
		{
			high = mid + 1;
		}
	}
}
int search_seq(SSTable st,int key,int startaddress)
{
	int temp = st.elem[startaddress - 1];
	st.elem[startaddress - 1] = key;
	int i;
	for (i = startaddress + ss - 1; st.elem[i] != key; i--);
	st.elem[startaddress - 1] = temp;
	return i;
}

int main()
{
	SSTable *st = (SSTable*)malloc(sizeof(SSTable));
	st->elem = (int*)malloc(sizeof(int)*MAXSSLENGTH);
	st->length = 0;
	for (int i = 1; i < MAXSSLENGTH - 1; i++)
	{
		scanf_s("%d", &st->elem[i]);
		st->length++;
	} 
	IndexTable *it = (IndexTable*)malloc(sizeof(IndexTable));
	it->elem = (Index*)malloc(sizeof(Index)*MAXBLOCK);
	for (int i = 1; i <= st->length; i *= PERBLOCKSIZE)
	{
		int endAddress = i*PERBLOCKSIZE - 1;
		it->elem[i%PERBLOCKSIZE].address = i;
		int max = 0;
		for (int j = i; j < endAddress; j++)
		{
			if (st->elem[j]>max)
			{
				max = st->elem[j];
			}
		}
		it->elem[i%PERBLOCKSIZE].max = max;
	}
	int blockNum = search_Index_Bin(*it,5);
	int startAddress = blockNum*PERBLOCKSIZE - 1;
	int x = search_seq(*st, 5, startAddress); 
	while (1)
	{
	}
}