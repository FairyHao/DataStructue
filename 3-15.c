#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2
//构造一个双向栈，即共享存储空间。
typedef struct
{
    int *base1;//栈1的基址
    int *base2;//栈2的基址
    int *top1;//栈1的top指针
    int *top2;//栈2的top指针
    int stacksize;
}Sqstack,*ss;

//初始化栈
Status initStack(ss s)
{
    (*s).base1= malloc(STACK_INIT_SIZE*sizeof(int));
    if (!s->base1)
    {
        exit(0);
    }
    s->base2 = s->base1 + STACK_INIT_SIZE-1;
    s->top1 = s->base1;
    s->top2 = s->base2;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
//push data into stack,i only equals 1 or 2,means which stack;
Status push(ss s,int i,int x)
{
    if (s->top1>s->top2)//双向栈栈满了
    {
        return ERROR;
    }
    if (i==1)
    {
        *s->top1++ = x;
    }
    else if (i==2)
    {
        *s->top2-- = x;
    }
    else
    {
        return INFEASIBLE;
    }
    return OK;
}
//pop data of stack,i only for 1 or 2，pop出栈并不会将栈的存储内容改变
int pop(ss s, int i)
{
    int e;
    if (i == 1)
    {
        if (s->top1==s->base1)
        {
            return -1;
        }
        e = *--(s->top1);
    }
    else if (i==2)
    {
        if (s->top2 == s->base2)
        {
            return -1;
        }
        e = *++(s->top2);
    }
    else
    {
        return -1;
    }
    return e;
}
//打印出栈中的所有元素
void printfS(ss s)
{
    int *p = s->base1;
    while (p != s->base2+1)
    {
        printf("%d ",*p);
        p++;
    }
    printf("\n");
}

int main()
{
    ss s = malloc(sizeof(Sqstack));
    initStack(s);
    printfS(s);
    for(int i= 0;i<6;i++)
    {
        push(s,1,i);
    }
    printfS(s);
    for(int i= 0;i<6;i++)
    {
        push(s,2,i);
    }
    printfS(s);
    for(int i = 0;i<10;i++)
    {
        printf("%d\n",pop(s,1));
    }
    printfS(s);
    for(int i = 0;i<10;i++)
    {
        printf("%d\n",pop(s,2));
    }
    printfS(s);
    return 0;
}







