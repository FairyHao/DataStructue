//
//  main.c
//  2-31
//
//  Created by Amy on 16/10/6.
//  Copyright © 2016年 Amy. All rights reserved.
//  本页所有内容属于单向循环列表
#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

typedef struct DuLnode
{
    int data;
    struct DuLnode *next;
    struct DuLnode *prior;
}DuLnode,*DuLinkList;

typedef int Status;
#define INFEASIBLE -1
#define OK 1

//初始化单向循环列表，无头节点和头指针
LinkList CreateList_L(int n)
{
    LinkList p;
    LinkList prep;
    int i=0;
    while(i<n)
    {
        if(i!=0)//只声明了节点之后，变量已经存上值了。所以用i!=0这个判断，按照正常的情况，应该是p!=NULL来判断
        {
            LinkList q = malloc(sizeof(Lnode));
            scanf("%d",&(q->data));
            q->next = p;
            prep->next = q;
            prep = q;
        }else
        {
            p = malloc(sizeof(Lnode));
            scanf("%d",&(p->data));
            p->next = p;
            prep = p;
        }
        i++;
    }
    return p;
}
//初始化双向循环列表，无头节点和头指针，但所有prior节点都为空，本质上还是单向循环列表
DuLinkList CreateList_DuL(int n)
{
    DuLinkList p;
    DuLinkList prep;
    int i=0;
    while(i<n)
    {
        if(i!=0)
        {
            DuLinkList q = malloc(sizeof(DuLnode));
            scanf("%d",&(q->data));
            q->next = p;
            prep->next = q;
            q->prior = NULL;
            prep = q;
        }else
        {
            p = malloc(sizeof(DuLnode));
            scanf("%d",&(p->data));
            p->next = p;
            p->prior = NULL;
            prep = p;
        }
        i++;
    }
    return p;
}
//从任何一个节点起输入单项循环列表
void printfL(LinkList L)//parameter：1. the address of the linklist;
{
    LinkList p = L;
    while(p)
    {
        int x = p->data;
        printf("%d ",x);
        if(p->next == L)//如果p的下一节点就是第一个输出的节点，则退出循环
        {
            break;
        }
        p = p->next;
    }
    printf("\n");
}
//从任何一个节点起输入单项循环列表
void printfDuL(DuLinkList L)//parameter：1. the address of the linklist;
{
    DuLinkList p = L;
    while(p)
    {
        int x = p->data;
        printf("%d ",x);
        if(p->prior == L)//如果p的下一节点就是第一个输出的节点，则退出循环
        {
            break;
        }
        p = p->prior;
    }
    printf("\n");
}
//2-31 循环列表中删除某个节点s的前驱节点
Status DeletePrepNode(LinkList s)
{
    LinkList p = s;
    LinkList prep;
    while(p&&p->next!=s)
    {
        prep = p;
        p = p->next;
    }
    if(p==s)
    {
        free(p);
        printf("循环链表长度为1，已删除唯一节点");
    }
    else
    {
        prep->next = s;
        free(p);
        printfL(s);
    }
    return OK;
}
//2-32  对双向链表的所有prior指针域赋值
Status  InitList_DL(DuLinkList dl)
{
    DuLinkList p = dl;
    while(p)
    {
        p->next->prior = p;//因为是循环列表，所以p->next不能为空。
        p = p->next;
        if(p==dl)//当再次循环到开始节点的时候，退出。不能在while处写(p&&p!=dl)，为了保证初次在这个节点也能正常处理。
        {
            break;
        }
    }
    printfDuL(dl);
    return OK;
}

int main(int argc, const char * argv[]) {
    //-------------------------2-31 start-----------------
    /*LinkList ha = CreateList_L(1);
    printfL(ha);
    DeletePrepNode(ha);*/
    //-------------------------2-31 end-----------------
    //-----------------------2-32 start--------------
    DuLinkList da = CreateList_DuL(5);
    //printfDuL(da);
    InitList_DL(da);
    //------------------------2-32 end
    return 0;
}
