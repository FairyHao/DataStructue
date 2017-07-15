/*
 Created By Hao Yuanxiao on 2016/9/16
 Description:对于顺序表，删除从i开始的k个元素
 */

#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define ERROR 0
#define INFEASIBLE 2
typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;

typedef int Status;//typedef create alias name for data type;

SqList* InitSqList()//给一个顺序线性表分配空间
{
    SqList *L = malloc(sizeof(SqList));
    (*L).elem = (int*)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!(*L).elem)
    {
        return NULL;
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return L;
}
void InitValue(SqList *L,int length)//给一个顺序线性表给值
{
    for(int i=0;i<length;i++)
    {
        scanf("%d",&(*L).elem[i]);
        printf(" ");
        (*L).length++;
    }
}
//2-10删除从i开始的k个元素,i从1开始。顺序表删除元素的本质是：将被删除元素之后的所有元素向前移动。
Status DeleteK(SqList *a,int i,int k)
{
    //参数不合法的情况；
    if(i<1||i+k>(*a).length||k<0)
    {
        return INFEASIBLE;
    }else
    {
        //思路：将i+k－1之后的元素，全部向前移动k个位置。
        for(int j=i+k-1;j<(*a).length;j++)
        {
            (*a).elem[j-k] = (*a).elem[j];
        }
        /*这个是下载的答案里的，思想是：移动k次；我认为不正确，因为删除k个元素并不是要移动k次。
        for(int j=0;j<=k;j++)
            (*a).elem[j+i-1]=(*a).elem[j+i+k-1];*/
        (*a).length-=k;
    }
    return OK;
}

void PrintfSqList(SqList *L)
{
    for(int i=0;i<(*L).length;i++)
    {
        printf("%d ",(*L).elem[i]);
    }
    printf("\n");
    return;
}

int main()
{
    /*SqList *L = InitSqList();
    int length = 0;
    printf("Please Enter the length of SqList:");
    scanf("%d",&length);
    printf("\n");
    InitValue(L,length);
    PrintfSqList(L);
    DeleteK(L,1,1);
    PrintfSqList(L);*/
    //以下代码的原理；scanf的原理
    int a[4],num = 0;
    char k;
    do
    {
        scanf("%d",&a[num]);
        num++;
        k = getchar();
    }while(k!='\n'&&num<4);
    for(int i=0;i<4;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
