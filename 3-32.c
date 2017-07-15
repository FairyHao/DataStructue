//
//  main.c
//  3-32
//
//  Created by Amy on 16/10/15.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef  struct
{
    int *base;
    int rear;
    int front;
    int tag;//标志栈满还是栈空；0：空；1：满
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
    sq->front = 0;
    sq->rear = 0;
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
    (*sq).base[sq->rear] = x;
    if(sq->rear >= MAXSIZE -1)
    {
        sq->rear = 0;
    }else
    {
        (sq->rear)++;
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
    int x = (*sq).base[sq->front];
    if(sq->front >=  MAXSIZE -1)
    {
        sq->front = 0;
    }else
    {
        (sq->front)++;
    }
    if(sq->front == sq->rear)
    {
        sq->tag = 0;
    }
    return x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Sq sq = initQueue();
    int k = 10;
    for(int i =0 ;i<k-1;i++)
    {
        EnQueue(sq, 0);
    }
    EnQueue(sq, 1);
    int sum = 0;
    int p = sq->front;
    int max = 100;
    while(1)
    {
        do
        {
            sum += (sq->base)[p];
            if(sum>max)
            {
                break;
            }
            if(sq->front == MAXSIZE -1)
            {
                p = 0;
            }else
            {
                p++;
            }
        }while(p&&p!=sq->rear);
        DeQueue(sq);
        EnQueue(sq,sum);
    }
    return 0;
}
