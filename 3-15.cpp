#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

//����һ��˫��ջ������һά����Ĵ洢�ռ��д���������ջ�����ǵ�ջ�׷ֱ���������������˵㡣
typedef struct  
{
	int *base1;//ջ1�Ļ�ַ
	int *base2;//ջ2�Ļ�ַ
	int *top1;
	int *top2;
	int stacksize;
}Sqstack,*ss;

Status initStack(ss s)
{
	s = malloc(sizeof(Sqstack));
	
	if (!s->base1)
	{
		exit(0);
	}
	s->base2 = s->base1 + STACK_INIT_SIZE;
	s->top1 = s->base1;
	s->top2 = s->base2;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
//i����push��ջ1����ջ2��iֻ����1����2
Status push(ss s,int i,int x)
{
	if (s->top1==s->top2)
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
//pop data of stack,i only for 1 or 2
Status pop(ss s, int i)
{
	int e;
	if (i == 1)
	{
		if (s->top1==s->base1)
		{
			return ERROR;
		}
		e = *--s->top1;
	}
	else if (i==2)
	{
		if (s->top2 == s->base2)
		{
			return ERROR;
		}
		e = *--s->top2;
	}
	else
	{
		return INFEASIBLE;
	}
	return OK;
}
void printfS(ss s)
{
	int *p = s->base1;
	while (p != s->base2)
	{
		printf("%d ",*p);
		p++;
	}
}

int main()
{
	printf("start");
	ss s = NULL;
	initStack(s);
	printfS(s);
	push(s,1,3);
	printfS(s);
	push(s,2,1);
	printfS(s);
	return 0;
}







   