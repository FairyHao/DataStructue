//
//  main.c
//  3-17
//
//  Created by Amy on 16/10/11.
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

int main(int argc, const char * argv[]) {
    //3-17 start----------------
    s = malloc(sizeof(Sqstack));
    if(!s)
    {
        printf("内存分配失败");
        exit(0);
    }
    initStack(s);
   /* char *str = "a&a@";
    while(*str!='&')
    {
        push(s,*str++);
    }
    str++;
    do
    {
        if(pop(s)!=*str++)
        {
            printf("NO\n");
            return 0;
        }

    }
    while(*str!='@');
    printf("YES\n");
    return 0;*/
    //3-17 end----------------
    
    //3-31 start-----------
    char *str = "abcdba\0";
    char *p = str;
    while(*p!='\0')
    {
        push(s,*p++);
    }
    p = str;
    do
    {
        if(pop(s)!=*str++)
        {
            printf("NO\n");
            return 0;
        }
    }
    while(*str!='\0');
    printf("YES\n");
    return 0;
    //3-32 end
}
