//
//  main.c
//  3-16
//
//  Created by Amy on 16/10/10.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define TRAINLENGTH 10
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2
//构造一个双向栈，即共享存储空间。
typedef struct
{
    int *base;//栈1的基址
    int *top;//栈2的top指针
    int stacksize;
}Sqstack,*ss;

ss s;//全局变量
//初始化一个栈
Status initStack(ss s)
{
    s->base = malloc(sizeof(int)*STACK_INIT_SIZE);
    if(!(*s).base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
//push一个字符
Status push(ss s,char x)
{
    if(s->top - s->base == STACK_INIT_SIZE)
    {
        return ERROR;
    }
    *s->top++ = x;
    return OK;
}
char pop(ss s)
{
    if(s->base!=s->top)
    {
        return *--(s->top);
    }
    return -1;
}
//3-1算法
char* dispatchTrain(char oldTrain[])
{
    char newTrain[TRAINLENGTH];
    int j = 0;
    printf("%s",oldTrain);
    printf("\n");
    for(int i = 0;i<TRAINLENGTH;i++)
    {
        printf("%c",oldTrain[i]);
        if(oldTrain[i]  =='S')
        {
            newTrain[j++] = 'S';
        }else if(oldTrain[i]=='H')
        {
            push(s,'H');
        }
    }
    while(j<TRAINLENGTH-1)
    {
        newTrain[j++] = pop(s);
    }
    printf("\n");
    newTrain[j] = '\0';
    printf("%s",newTrain);
    printf("\n");
    printf("%p",newTrain);
    printf("\n");
    return newTrain;
}

int main(int argc, const char * argv[]) {
    s = malloc(sizeof(Sqstack));
    if(!s)
    {
        printf("内存分配失败");
        exit(0);
    }
    initStack(s);
    char oldTrain[TRAINLENGTH] = {'S','H','H','H','S','S','H','S','H','\0'};
    //char oldTrain[TRAINLENGTH] = "SSHHHHSSH";
    //参数要是取(&oldTrain[TRAINLENGTH]),则答案完全不正确。参数写（&oldTrain）或者是(oldTrain)则正确。
    char* train = dispatchTrain(&oldTrain);
    printf("%p",train);//调试正确，不能正确输出，这个地址和上述newtrain地址相同。
    //printf("%s",train);//调试正确，不能正确输出,不知道原因。
    printf("\n");
    return 0;
}
