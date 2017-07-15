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
	int flag;//0����Ӧ��������1����Ӧ�������ң�2������ʸýڵ�
	struct BiTnode *parent;
}BiTnode, *BiTree;
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
			t->flag = 0;
			t->lchild ? t->lchild->parent = t : NULL;
			t->rchild ? t->rchild->parent = t: NULL;
			t->parent = NULL;
		} 
	}
	return t;
}
int printElement(char e)
{
	printf("%c", e);
	return 1;
}
//���������1.������2.������3.���ڵ�
//�ǵݹ���㷨�Ļ���˼���ǣ�1.���ڵ��ջ2.����������3.��������ջ��
Status LastOrderTraverse(BiTree t)
{
	if (t)
	{
		LastOrderTraverse(t->lchild);
		LastOrderTraverse(t->rchild);
		printElement(t->data);
	}
	return OK;
}
//��������ĵ����㷨��
//�㷨�Ļ���˼�룺1.flag==0��1������flag���µ���2.flag==2������ĸ���ơ���������Ϊ����������ϣ�ָ��parent��parent��Ϊ�գ�
Status LastOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	while (p!=NULL)
	{
		if (p->flag == 0)
		{
			if (p->lchild)
			{
				p->flag = 1;
				p = p->lchild;
			}
			else if (p->rchild)
			{
				p->flag = 2;
				p = p->rchild;
			}
			else
			{
				p->flag = 2;
			}
		}
		else if (p->flag == 1)
		{
			if (p->rchild)
			{
				p->flag = 2;
				p = p->rchild;
			}
			else
			{
				p->flag = 2;
			}
		}
		else if (p->flag == 2)
		{
			printElement(p->data);
			p->flag = 0;
			p = p->parent;
		}
	}
	return OK;
}
int main()
{
	char tree[] = "abd g  e  c f   ";// abd g  e  c f    ab  c  
	BiTree bt = Create(tree);
	LastOrderTraverse(bt);
	printf("\n");
	LastOrderTraverseByIterative(bt);
	while (1)
	{
	}
	return 0;
}