//
//  main.c
//  3-30
//
//  Created by Amy on 16/10/14.
//  Copyright © 2016年 Amy. All rights reserved.
//
#define MAXSIZE 3

typedef struct
{
    int *base;
    int rear;
    int lengths;
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
    sq->rear = 0;
    sq->lengths = 0;
    return sq;
}

int EnQueue(Sq sq,int x)
{
    if(sq->lengths == MAXSIZE)
    {
        printf("Sorry,the stack is full\n");
        return -1;
    }
    (*sq).base[sq->rear] = x;
    sq->lengths++;
    if(sq->rear >= sq->base + MAXSIZE -1)
    {
        sq->rear = 0;
    }else
    {
        sq->rear++;
    }
    return 0;
}

int DeQueue(Sq sq)
{
    if(sq->lengths == 0)
    {
        printf("Sorry,the stack is empty\n");
        return -1;
    }
    int x = (*sq).base[((sq->rear+MAXSIZE-sq->lengths)%MAXSIZE)];
    sq->lengths--;
    return x;
}

void printSq(Sq sq)
{
    int *p = sq->base;
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
    while(p&&p!=sq->base);
    printf("\n");
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
