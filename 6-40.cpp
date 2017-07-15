#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

//�������֤��������һ����ĸ�򣬲���ջ�Ϳ���ʵ�����ֱ����ĵ����㷨��
typedef struct BiTnode
{
	char data;
	struct BiTnode *lchild, *rchild;
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
			t->lchild ? t->lchild->parent = t :NULL;
			t->rchild ? t->rchild->parent = t :NULL;
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
Status InOrderTraverse(BiTree t)
{
	if (t)
	{
		InOrderTraverse(t->lchild);
		printElement(t->data);
		InOrderTraverse(t->rchild);
	}
	return OK;
}
//��������ĵ����㷨�������㷨������ջ���㷨��
//�㷨�Ļ���˼�룺�ڽṹ��������һ��parentָ�����ڳ���������һ��ָ�����֮ǰ���ʵĵ㣻��������֮ǰ��ָ������ڵ�ָ�����ƶϳ���������������Ժ���һ�����������ָ������һ���ġ�
//��ǰ�����·����ǰһ����������ֹ�ϵ��ͷ���ٶ���NULLָ��ĺ��ӡ�
Status InOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	BiTree prep = NULL;
	while (p)
	{
		if (p->parent == prep)//prep�����p�ĸ�ĸ
		{
			prep = p;
			if (p->lchild)
			{
				p = p->lchild;
			}
			else
			{
				printElement(p->data);
				if (p->rchild)
				{
					p = p->rchild;
				}
				else
				{
					p = p->parent;
				}
			}
		}
		else if (prep == p->lchild)//prep�����p�ĺ���
		{
			prep = p;
			printElement(p->data);
			if (p->rchild)
			{
				p = p->rchild;
			}
			else
			{
				p = p->parent;
			}
		}
		else if (prep == p->rchild)
		{
			prep = p;
			p = p->parent;
		}
		
	}
	return OK;
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
//��������ĵ����㷨�������㷨������ջ���㷨��
//�㷨�Ļ���˼�룺�ڽṹ��������һ��parentָ�����ڳ���������һ��ָ�����֮ǰ���ʵĵ㣻��������֮ǰ��ָ������ڵ�ָ�����ƶϳ���������������Ժ���һ�����������ָ������һ���ġ�
//��ǰ�����·����ǰһ����������ֹ�ϵ��ͷ���ٶ���NULLָ��ĺ��ӡ�
Status LastOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	BiTree prep = NULL;
	while (p)
	{
		if (p->parent == prep)//prep�����p�ĸ�ĸ
		{
			prep = p;
			if (p->lchild)
			{
				p = p->lchild;
			}
			else
			{
				if (p->rchild)
				{
					p = p->rchild;
				}
				else
				{
					printElement(p->data);
					p = p->parent;
				}
			}
		}
		else if (prep == p->lchild)//prep�����p�ĺ���
		{
			prep = p;
			if (p->rchild)
			{
				p = p->rchild;
			}
			else
			{
				printElement(p->data);
				p = p->parent;
			}
		}
		else if (prep == p->rchild)
		{
			prep = p;
			printElement(p->data);
			p = p->parent;
		}

	}
	return OK;
}
//���������1.������2.������3.���ڵ�
//�ǵݹ���㷨�Ļ���˼���ǣ�1.���ڵ��ջ2.����������3.��������ջ��
Status prepOrderTraverse(BiTree t)
{
	if (t)
	{
		printElement(t->data);
		prepOrderTraverse(t->lchild);
		prepOrderTraverse(t->rchild);
	}
	return OK;
}
//��������ĵ����㷨�������㷨������ջ���㷨��
//�㷨�Ļ���˼�룺�ڽṹ��������һ��parentָ�����ڳ���������һ��ָ�����֮ǰ���ʵĵ㣻��������֮ǰ��ָ������ڵ�ָ�����ƶϳ���������������Ժ���һ�����������ָ������һ���ġ�
//��ǰ�����·����ǰһ����������ֹ�ϵ��ͷ���ٶ���NULLָ��ĺ��ӡ�
Status prepOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	BiTree prep = NULL;
	while (p)
	{
		if (p->parent == prep)//prep�����p�ĸ�ĸ
		{
			printElement(p->data);
			prep = p;
			if (p->lchild)
			{
				p = p->lchild;
			}
			else
			{
				if (p->rchild)
				{
					p = p->rchild;
				}
				else
				{
					p = p->parent;
				}
			}
		}
		else if (prep == p->lchild)//prep�����p�ĺ���
		{
			prep = p;
			if (p->rchild)
			{
				p = p->rchild;
			}
			else
			{
				p = p->parent;
			}
		}
		else if (prep == p->rchild)
		{
			prep = p;
			p = p->parent;
		}

	}
	return OK;
}
int main()
{
	char tree[] = "abd g  e  c f  ";// abd g  e  c f    ab  c  
	BiTree bt = Create(tree);
	/*InOrderTraverse(bt);
	printf("\n");
	InOrderTraverseByIterative(bt);*/
	/*LastOrderTraverse(bt);
	printf("\n");
	LastOrderTraverseByIterative(bt);*/
	prepOrderTraverse(bt);
	printf("\n");
	prepOrderTraverseByIterative(bt);
	while (1)
	{
	}
	return 0;
}