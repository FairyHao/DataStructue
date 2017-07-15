//
//  main.c
//  3-21
//
//  Created by Amy on 16/10/12.
//  Copyright © 2016年 Amy. All rights reserved.
//  假设表达式有单字母变量和双目四则运算符构成。试写一个算法，将一个通常书写形式且书写正确的表达式转换为逆波兰表达式。
/*
    算法描述：对每个运算符，和他之前的每个运算符比较，1.若是优先级高，则代表两个操作数没有找全，
    2. 若是优先级低，则代表之前的那个运算符两个操作数已经找到了。
    注：双目四则运算：即＋－ * /，很容易知道他只有两个等级(*&/)和(+&-)。
 */

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
Status push(ss s,int x)
{
    if(s->top - s->base == STACK_INIT_SIZE)
    {
        return ERROR;
    }
    *s->top++ = x;
    return OK;
}
int pop(ss s)
{
    if(s->base!=s->top)
    {
        return *--(s->top);
    }
    return '\0';
}
int getTop(ss s)
{
    if(s->base!=s->top)
    {
        int *p = s->top-1;
        return *p;
    }
    return '\0';
}

int IsOperater(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    {
        return 1;
    }else
    {
        return 0;
    }
}

int prior(char c1,char c2)
{
    if(c1 == '\0'||c2 == '\0')
    {
        return 0;
    }
    if(c2 == '#')
    {
        return 1;
    }
    if((c1=='*'||c1=='/')&&(c2=='+'||c2=='-'))
    {
        return 1;
    }
    return 0;
}

int StackEmpty(ss s)
{
    if(s->base == s->top)
    {
        return 1;
    }else
    {
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    s = malloc(sizeof(Sqstack));
    if(!s)
    {
        printf("内存分配失败");
        exit(0);
    }
    initStack(s);//
    /*//start 3-21-------------------------------------
    push(s,'#');
    char polandExpression[] = {'#'};
    int i = 1;
    char *str = "#a+b+c-d#\0";
    char *p = ++str;
    while(p && *p!='#')
    {
        if(IsOperater(*p))
        {
            if(prior(*p,getTop(s)))
            {
                    push(s,*p);
            }else
            {
                while(!prior(*p,getTop(s)))
                {
                    polandExpression[i++] = pop(s);
                }
                push(s,*p);
            }
        }else
        {
            polandExpression[i++] = *p;
        }
        p++;
    }
    while(!StackEmpty(s))
    {
        polandExpression[i++] = pop(s);
    }
    polandExpression[i] = '\0';
    printf("%s",polandExpression);*/
    /*end 3-21-------------------------------------*/
    
    //start 3-22------------------------------------
    char *str = "#abc*+da/-#\0";
    s->top = s->base;
    char *p = ++str;
    while(p && *p!='#')
    {
        if(IsOperater(*p))
        {
            int a1 = pop(s);
            printf("pop出来的%d\n",a1);
            int a2 = pop(s);
            printf("pop出来的%d\n",a2);
            if(*p == '+')
            {
                push(s,a1+a2);
            }else if(*p == '-')
            {
                push(s,a2-a1);
            }else if(*p == '*')
            {
                push(s,a1*a2);
            }else if(*p == '/')
            {
                push(s,a2/a1);
            }
        }else
        {
            printf("push进去的%d",*p);
            push(s,*p);
        }
        p++;
    }
    printf("%d\n",pop(s));
    printf("%d",97+98*99-100/97);
    //end 3-22 -------------------------------------
    
    
    return 0;
}
