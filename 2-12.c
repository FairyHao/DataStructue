//
//  main.c
//  DataStructure2-12
//
//  Created by Amy on 16/9/13.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

//2-12 对两个顺序表，例如：A和B，当除去最大共同前缀后的子表，比较两个子表的大小。
int Compare(SqList *A,SqList *B)
{
    int i;
    for(i = 0;i<(*A).length&&i<(*B).length;i++)
    {
        if((*A).elem[i]>(*B).elem[i])
        {
            return 0;//0代表A>B
        }else if((*A).elem[i]<(*B).elem[i])
        {
            return 1;//1代表A<B
        }
    }
    if((*A).length==(*B).length)
    {
        return 2;//3代表A＝B
    }else if((*A).length<(*B).length)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main() {
    int lengthA = 3;
    int lengthB = 2;
    SqList *B = InitSqList();
    SqList *A = InitSqList();
    InitValue(A,lengthA);
    InitValue(B,lengthB);
    PrintfSqList(A);
    PrintfSqList(B);
    int result = Compare(A,B);
    if(result==0)
    {
        printf("A>B");
    }else if(result==2)
    {
        printf("A=B");
    }else
    {
        printf("A<B");
    }
    return 0;
}
