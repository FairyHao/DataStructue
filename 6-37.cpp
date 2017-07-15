// 6-37.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct BiTnode
{
	char data;
	struct BiTnode *lchild, *rchild;
}BiTnode,*BiTree;

typedef struct
{
	BiTree *base;//ջ�д�ŵ���ָ��
	BiTree *top;
	int stacksize;
}Sqstack, *ss;

//��ʼ��һ��ջ
ss initStack()
{
	ss s = (ss)malloc(sizeof(Sqstack));
	s->base = (BiTree *)malloc(sizeof(BiTree)*STACK_INIT_SIZE);//ջ�д�ŵ���ָ�룻
	if (!(*s).base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return s;
}
//pushһ���ַ�
Status push(ss s, BiTree x)
{
	if (s->top - s->base == STACK_INIT_SIZE)
	{
		return ERROR;
	}
	*s->top++ = x;
	return OK;
}
BiTree pop(ss s)
{
	if (s->base != s->top)
	{
		return *--(s->top);
	}
	return NULL;
}
int StackEmpty(ss s)
{
	if (s->base == s->top)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int i = 0;
BiTree Create(char s[])
{
	char ch;
	ch = s[i++];
	BiTree t;
	if (ch == ' ')
	{
		t = NULL;
	}
	else
	{
		if (!(t = (BiTree)malloc(sizeof(BiTnode))))
		{
			printf("fail to malloc!\n");
			exit(0);
		}
		else
		{
			t->data = ch;
			t->lchild = Create(s);
			t->rchild = Create(s);
		}
	}
	return t;
}
int printElement(char e)
{
	printf("%c", e);
	return 1;
}
//���������1.���ڵ�2.������3.������..����ԭ�����ô�����������ô�򲻳���
//���Ա������㷨����˼��Ϊ��1. ���ʸ��ڵ�2.�Ը��ڵ������������Ϊ���ڵ����������3.�Խ�������������Ϊ���ڵ����������
//�ǵݹ��㷨�Ľӱ�˼���ǣ�1.���ʸ��ڵ�2.���������������ڵ����������3.���ڵ����������ջ����С�����ǣ����ڵ�Ϊ��&&ջΪ��
Status PreOrderTraverseByStack(BiTree t)
{
	ss s = initStack();
	if (!s)
	{
		return ERROR;
	}
	BiTree p = t;
	while (p || !StackEmpty(s))
	{
		if (p)
		{
			if (!printElement(p->data))
			{
				return ERROR;
			}
			push(s, p->rchild);
			p = p->lchild;//���������������������������ڷ�����������������һ�佫��������ջ
		}
		else
		{
			p = pop(s);
		}
	}
	return OK;
}
int PreOrderTraverse(BiTree t)
{
	if (t)
	{
		if (printElement(t->data))
		{
			  if (PreOrderTraverse(t->lchild))
			{
				if (PreOrderTraverse(t->rchild))
				{
					return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	printf("start");
	char tree[] = "abd g  e  c f  ";
	BiTree bt = Create(tree);
	PreOrderTraverse(bt);
	printf("\n");
	PreOrderTraverseByStack(bt);
	while (1)
	{
	}
	return 0;
}
