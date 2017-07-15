//
//  main.c
//  3-28
//
//  Created by Amy on 16/10/14.
//  Copyright © 2016年 Amy. All rights reserved.
/* 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），试编写相应的队列初始化、入队列、出队列的算法。*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode,*LinkQueue;

typedef struct
{
    LinkQueue rear;
}Queue;
Queue* initQueue()
{
    LinkQueue header = malloc(sizeof(Lnode));
    if(!header)
    {
        exit(0);
    }
    header->next = header;
    Queue *q = malloc(sizeof(Queue));
    q->rear = header;
    return q;
}

int EnQueue(Queue *q,int x)
{
    LinkQueue newNode = malloc(sizeof(Lnode));
    newNode->data = x;
    newNode->next = q->rear->next;
    q->rear->next = newNode;
    q->rear = newNode;
    return 0;
}

int Dequeue(Queue *q)
{
    LinkQueue header;
    if(q->rear->next->next == q->rear)
    {
        q->rear->next->next =  q->rear->next;
        q->rear = q->rear->next;
    }else
    {
        LinkQueue p = q->rear->next->next;
        q->rear->next->next=p->next;
    }
    return 0;
}

int printfQueue(Queue *q)
{
    int flag = 1;
    LinkQueue p = q->rear;
    while(p&&flag)
    {
        printf("%d,",p->data);
        p = p->next;
        if(p==q->rear)
        {
            flag = 0;
        }
    }
    printf("\n");
    return 0;
}
int main(int argc, const char * argv[]) {
    Queue *lq = initQueue();
    printfQueue(lq);
    EnQueue(lq, 5);
    printfQueue(lq);
    EnQueue(lq, 6);
    printfQueue(lq);
    EnQueue(lq, 10);
    printfQueue(lq);
    Dequeue(lq);
    printfQueue(lq);
    Dequeue(lq);
    printfQueue(lq);
    Dequeue(lq);
    printfQueue(lq);
    return 0;
}
