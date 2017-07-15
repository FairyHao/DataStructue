// 6-37.cpp : 定义控制台应用程序的入口点。
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
	BiTree *base;//栈中存放的是指针
	BiTree *top;
	int stacksize;
}Sqstack, *ss;

//初始化一个栈
ss initStack()
{
	ss s = (ss)malloc(sizeof(Sqstack));
	s->base = (BiTree *)malloc(sizeof(BiTree)*STACK_INIT_SIZE);//栈中存放的是指针；
	if (!(*s).base)
	{
		exit(0);
	}
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return s;
}
//push一个字符
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
//先序遍历：1.根节点2.左子树3.右子树..不是原创，好聪明啊，我怎么悟不出来
//所以遍历的算法基本思想为：1. 访问根节点2.以根节点的左子树域作为根节点访问左子树3.以结点的右子树域作为根节点访问右子树
//非递归算法的接本思想是：1.访问根节点2.访问左子树（根节点的左子树域）3.根节点的右子树入栈；最小问题是：根节点为空&&栈为空
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
			p = p->lchild;//访问左子树，访问完左子树后，在访问右子树，所以下一句将右子树入栈
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
