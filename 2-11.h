//
//  header.h
//  DataStructure2-11
//
//  Created by Amy on 16/9/16.
//  Copyright © 2016年 Amy. All rights reserved.
//

#ifndef header_h
#define header_h

#define LIST_INIT_SIZE 1000//Define the Init length of Sequence List
#define LISTINCREMENT 10//Define the Increment size of Sequence List
#define OK 1
#define ERROR 0
#define INFEASIBLE 2
typedef int Status;//Define a new Type

#include <stdio.h>

typedef struct{
    int *elem;
    int length;
    int listsize;
}SqList;//Define Sequence List

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
        printf("请输入第%d个位置的元素",i);
        scanf("%d",&(*L).elem[i]);
        printf(" ");
        (*L).length++;
    }
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
//在存储空间不够时，增加分配空间；
SqList* ReInitSqList(SqList *L)
{
    int *newbase = (int*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(int));
    if(!newbase)
    {
        return L;
    }
    (*L).elem = newbase;
    (*L).listsize += LISTINCREMENT;
    return L;
}


#endif /* header_h */
