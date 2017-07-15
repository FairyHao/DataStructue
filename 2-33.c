//
//  main.c
//  2－33
//
//  Created by Amy on 16/10/7.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    char data;
    struct Lnode *next;
}Lnode,*LinkList;

typedef int Status;
#define INFEASIBLE -1
#define OK 1

//Init LinkList;带头节点的线性列表,
LinkList CreateList_L(int n)
{
    LinkList L = malloc(sizeof(Lnode));//malloc come from stdlib.h;allocates memory and return a pointer to it;variable is a pointer type and means address
    L->next = NULL;
    LinkList q = L;
    for(int i = n;i>0;i--)
    {
        LinkList p = malloc(sizeof(Lnode));
        //p->data = 2*i+1;
        scanf("%c ",&(p->data));
        q->next = p;
        q = p;//将每个节点放在最后一个元素的后面*/
        /*将每个节点放在第一个元素位置；*/
        /*p->next=L->next;
         L->next = p;*/
    }
    return L;
}

//printf the data of the all node;单项循环列表。
void printfL(LinkList L)//parameter：1. the address of the linklist;
{
    LinkList p = L;
    if(p)
    {
        p = p->next;//跳过头节点。
    }else
    {
        printf("It is null");
    }
    while(p&&p!=L)
    {
        int x = p->data;
        printf("%c ",x);
        p = p->next;
    }
    printf("\n");
}
//2-33 已知由一个线性链表表示的线性表中含有三类字符的数据元素（如：字母字符、数字字符和其他字符），试编写算法将该线性表分割为三个//循环链表，其中每个循环链表表示的线性表中均只含一类字符。
Status ListDivideInto3CL(LinkList l,LinkList hn,LinkList ho,LinkList hc)
{
    LinkList p,q;//p遍历链表l上的每一个节点，pn代表数字节点的时候的处理，po代表其他节点，pc代表字符节点。
    if(!l)
    {
        return INFEASIBLE;
    }
    p = l->next;
    if(!hn||!ho||!hc)
    {
        return INFEASIBLE;//若是空，则应该return 三个地址，若作为参数传过来，则应该已经有了地址。
    }
    hn->next = hn;
    ho->next = ho;
    hc->next = hc;
    while(p)
    {
        q = p;
        p = p->next;
        if(q->data>='0'&&q->data<='9')
        {
            q->next = hn->next;
            hn->next = q;
        }else if((q->data>'A'&&q->data<'Z')||(q->data>'a'&&q->data<'z'))
        {
            q->next = hc->next;
            hc->next = q;
        }else
        {
            q->next = ho->next;
            ho->next = q;
        }
    }
    return OK;
}
int main(int argc, const char * argv[]) {
    LinkList l = CreateList_L(10);
    printfL(l);
    LinkList hn = malloc(sizeof(Lnode));
    LinkList ho = malloc(sizeof(Lnode));
    LinkList hc = malloc(sizeof(Lnode));
    ListDivideInto3CL(l,hn,ho,hc);
    printfL(hn);
    printfL(ho);
    printfL(hc);
    return 0;
}
