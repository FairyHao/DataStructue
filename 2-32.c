//
//  main.c
//  2-32
//
//  Created by Amy on 16/10/6.
//  Copyright © 2016年 Amy. All rights reserved.
//双向循环列表

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *prior;
    struct Lnode *next;
}Lnode,*LinkList;

typedef int Status;
#define INFEASIBLE -1
#define OK 1

//初始化循环列表，无头节点和头指针
LinkList CreateList_L(int n)
{
    LinkList p;
    LinkList prep;
    int i=0;
    while(i<n)
    {
        if(i!=0)
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

int main(int argc, const char * argv[]) {
    //2-31 start
    LinkList ha = CreateList_L(1);
    printfL(ha);
    DeletePrepNode(ha);
    //2-31 end
    return 0;
}
