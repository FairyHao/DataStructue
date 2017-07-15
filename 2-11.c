//
//  main.c
//  DataStructure2-11
//
//  Created by Amy on 16/9/13.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//2-11Description:顺序表L有序递增，将x插入有序表中的合适位置，使表保持有序
//思想：顺序表增加元素的本质是移动元素。将x放入到顺序表的适当位置，即倒叙移动元素。
Status AddElement(SqList *L,int x)
{
    if(!(*L).elem)
    {
        return INFEASIBLE;
    }else if((*L).length>=LIST_INIT_SIZE)
    {
        L = ReInitSqList(L);
    }
    int length = (*L).length;
    (*L).elem[length] = x;
    /*原本的写法，看了答案之后觉得不够精简
    for(int i = length-1;i>=0;i--)
    {
        if(x>(*L).elem[i])
        {
            break;
        }else
        {
            (*L).elem[i+1] = (*L).elem[i];
            (*L).elem[i] = x;
        }
    }*/
    int i;
    for(i = length-1;i>=0,x<(*L).elem[i];i--)
    {
        (*L).elem[i+1] = (*L).elem[i];
    }
    (*L).elem[i+1] = x;
    (*L).length++;
    return OK;
}

int main() {
    int length = 3;
    SqList *ll = InitSqList();
    InitValue(ll,length);
    PrintfSqList(ll);
    int x = 3;
    AddElement(ll,x);
    PrintfSqList(ll);
    return 0;
}
