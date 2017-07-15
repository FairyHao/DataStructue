//
//  main.c
//  3-29
//
//  Created by Amy on 16/10/14.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 3

typedef struct
{
    int *base;
    int *rear;
    int *front;
    int tag;//0或者1，代表队列空还是队列满，0：空，1:满,
}SqQueue,*Sq;

Sq initQueue()
{
    Sq sq = malloc(sizeof(SqQueue));
    if(!sq)
    {
        exit(0);
    }
    sq->base = malloc(MAXSIZE*sizeof(int));
    if(!sq->base)
    {
        exit(0);
    }
    sq->front = sq->base;
    sq->rear = sq->base;
    sq->tag = 0;
    return sq;
}

int EnQueue(Sq sq,int x)
{
    if(sq->tag == 1&&sq->front == sq->rear)
    {
        printf("Sorry,the stack is full\n");
        return -1;
    }
    *(sq->rear) = x;
    if(sq->rear >= sq->base + MAXSIZE -1)
    {
        sq->rear = sq->base;
    }else
    {
        sq->rear++;
    }
    if(sq->front == sq->rear)
    {
        sq->tag = 1;
    }
    return 0;
}

int DeQueue(Sq sq)
{
    if(sq->tag == 0&&sq->front == sq->rear)
    {
        printf("Sorry,the stack is empty\n");
        return -1;
    }
    int x = *(sq->front);
    if(sq->front >= sq->base + MAXSIZE -1)
    {
        sq->front = sq->base;
    }else
    {
        sq->front++;
    }
    if(sq->front == sq->rear)
    {
        sq->tag = 0;
    }
    return x;
}

void printSq(Sq sq)
{
    int *p = sq->front;
    do
    {
        printf("%d,",*p);
        if(p == sq->base + MAXSIZE -1)
        {
            p = sq->base;
        }else
        {
            p++;
        }
    }
    while(p&&p!=sq->rear);
    printf("\n");
}
int main(int argc, const char * argv[]) {
    Sq sq = initQueue();
    EnQueue(sq, 1);
    printSq(sq);
    EnQueue(sq, 2);
    printSq(sq);
    EnQueue(sq, 3);
    printSq(sq);
    EnQueue(sq, 4);
    DeQueue(sq);
    printSq(sq);
    DeQueue(sq);
    printSq(sq);
    DeQueue(sq);
    printSq(sq);
    DeQueue(sq);
    printSq(sq);
    return 0;
}
