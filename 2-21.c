//
//  main.c
//  2-21
//
//  Created by Amy on 16/9/19.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100
#define INFEASIBLE 0
#define OK 1

typedef struct sqList
{
    int *elem;
    int length;
    int listsize;
}sqList;

typedef int Status;


//2-21 实现顺序表的就地逆置
Status OppositeLocation(sqList *s)
{
    if(!s)
    {
        return INFEASIBLE;
    }
    int x = (int)floor((s->length-1)/2.0);
    for(int i=0;i<=x;i++)
    {
        int temp;
        temp = (*s).elem[i];
        (*s).elem[i] = (*s).elem[s->length-1-i];
        (*s).elem[s->length-1-i] = temp;
    }
    return OK;
}
sqList* InitSqList()//给一个顺序线性表分配空间
{
    sqList *L = malloc(sizeof(sqList));
    (*L).elem = (int*)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!(*L).elem)
    {
        return NULL;
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return L;
}
void InitValue(sqList *L,int length)//给一个顺序线性表给值
{
    for(int i=0;i<length;i++)
    {
        printf("请输入第%d个位置的元素",i);
        scanf("%d",&(*L).elem[i]);
        printf(" ");
        (*L).length++;
    }
}

void PrintfSqList(sqList *L)
{
    for(int i=0;i<(*L).length;i++)
    {
        printf("%d ",(*L).elem[i]);
    }
    printf("\n");
    return;
}
//2-25求两个顺序表的交集，并另辟空间存储。
sqList*  Mix(sqList *A,sqList *B)
{
    int lengthA = (*A).length;
    int lengthB = (*B).length;
    int i,j = 0;
    sqList *C = InitSqList();
    while(i<lengthA&&j<lengthB)
    {
        if((*A).elem[i]<(*B).elem[j])
        {
            i++;
        }else if(((*A).elem[i] == (*B).elem[j]))
        {
            (*C).elem[(*C).length] = (*A).elem[i];
            (*C).length++;
            i++;
            j++;
        }else
        {
            j++;
        }
    }
    return C;
}
// 顺序表去重的算法
sqList* DeleteEqualEle(sqList *a)
{
    int length = a->length;
    for(int i = length-1;i>=0;i--)
    {
        if(a->elem[i]==a->elem[i-1])
        {
            for(int j = i+1;j<a->length;j++)
            {
                a->elem[j-1] = a->elem[j];
            }
            (a->length)--;
        }
    }
    return a;
}
//2-27 对两个顺序表求交集，并利用A表空间存储；两个线性表内容不重复
sqList* OldMix(sqList *a,sqList *b)
{
    int lengthA = (*a).length;
    int lengthB = (*b).length;
    int i = lengthA-1;
    int j = lengthB-1;
    while(i>0&&j>0)
    {
        if((*a).elem[i]>(*b).elem[j])
        {
            //删掉A中i位置的元素
            for(int k = i+1;k<a->length;k++)
            {
                a->elem[k-1] = a->elem[k];
            }
            (a->length)--;
            i--;
        }else if((*a).elem[i] == (*b).elem[j])
        {
            i--;
            j--;
        }else
        {
            j--;
        }
    }
    free(b);
    return a;
}

int main(int argc, const char * argv[]) {
    //2-21 start----------------------------------
    /*sqList *s = InitSqList();
    InitValue(s, 4);
    PrintfSqList(s);
    OppositeLocation(s);
    PrintfSqList(s);*/
    //2-21 end----------------------------------
    //2-25 start-------------------------------
    /*sqList *A = InitSqList();
    InitValue(A,10);
    PrintfSqList(A);
    sqList *B = InitSqList();
    InitValue(B,8);
    PrintfSqList(B);
    sqList *C = Mix(A,B);
    PrintfSqList(C);*/
    //2-25 end---------------------------------
    //2-27 start-------------------------------
    sqList *A = InitSqList();
    InitValue(A,5);
    PrintfSqList(A);
    DeleteEqualEle(A);
    PrintfSqList(A);
    sqList *B = InitSqList();
    InitValue(B,4);
    PrintfSqList(B);
    DeleteEqualEle(B);
    PrintfSqList(B);
    OldMix(A,B);
    PrintfSqList(A);
    //2-27 end-------------------------------
    
    return 0;
}
