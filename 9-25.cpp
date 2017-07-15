#include <stdio.h>
#include <stdlib.h>
#define MAXSSLENGTH 7
typedef struct
{
	int *elem;
	int length;
}SSTable;
//哨兵在高下标处的顺序查找算法。
int search(SSTable st,int key)
{
	if (st.length>=MAXSSLENGTH)
	{
		return -1;
	}
	st.elem[st.length] = key;//哨兵在高下标端
	int i;
	for (i = 0; key != st.elem[i]; ++i);
	if (i==st.length)
	{
		return -1;
	}
	else
	{
		return i;
	}
}
//折半查找的算法思想：查找中间位置的元素是否==key，若中间位置的元素小于key，则在前半段查找，若中间位置的元素大于key，则在后半段查找。直至low>high.
int search_bin(SSTable st, int key, int low, int high)
{
	if (low > high)
	{
		return -1;
	}
	int mid = (low + high) / 2;
	if (key == st.elem[mid])
	{
		return mid;
	}
	if (key < st.elem[mid])
	{
		return search_bin(st, key, low, mid - 1);
	}
	return search_bin(st, key, mid + 1, high);
}
//折半查找
int search_bin(SSTable st,int key)
{
	if (key < st.elem[1])
	{
		return 0;
	}
	if (key>=st.elem[st.length])
	{
		return st.length;
	}
	int low = 1;
	int high = st.length;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key<st.elem[mid+1]&&key>=st.elem[mid])
		{
			return mid;
		}
		if (key>=st.elem[mid+1])
		{
			low = mid + 1;
		}
		else if (key < st.elem[mid])
		{
			high = mid - 1;
		}
	}                                                                                             
}

int main()
{
	SSTable *st = (SSTable*)malloc(sizeof(SSTable));
	st->elem = (int*)malloc(sizeof(int)*MAXSSLENGTH);
	st->length = 0;
	for (int i = 1; i < MAXSSLENGTH-1; i++)
	{
		scanf_s("%d",&st->elem[i]);
		st->length++; 
	}
	//int x = search(*st, 3);
	//int x = search_bin(*st,3,0,st->length);
	int x = search_bin(*st, 3);
	while (1)
	{
	}	
}