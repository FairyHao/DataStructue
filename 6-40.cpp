#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 10
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

//这道题充分证明：增加一个父母域，不用栈就可以实现三种遍历的递推算法；
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
//中序遍历：1.左子树2.右子树3.根节点
//非递归的算法的基本思想是：1.根节点进栈2.访问左子树3.右子树进栈。
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
//中序遍历的递推算法；递推算法即不设栈的算法；
//算法的基本思想：在结构体中增加一个parent指针域；在程序中增加一个指针代表之前访问的点；这样根据之前的指针和现在的指针能推断出，方向是哪里，所以和上一题的增加两个指针域是一样的。
//当前结点与路径的前一个结点有三种关系。头结点假定是NULL指针的孩子。
Status InOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	BiTree prep = NULL;
	while (p)
	{
		if (p->parent == prep)//prep结点是p的父母
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
		else if (prep == p->lchild)//prep结点是p的孩子
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
//后序遍历：1.左子树2.右子树3.根节点
//非递归的算法的基本思想是：1.根节点进栈2.访问左子树3.右子树进栈。
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
//后序遍历的递推算法；递推算法即不设栈的算法；
//算法的基本思想：在结构体中增加一个parent指针域；在程序中增加一个指针代表之前访问的点；这样根据之前的指针和现在的指针能推断出，方向是哪里，所以和上一题的增加两个指针域是一样的。
//当前结点与路径的前一个结点有三种关系。头结点假定是NULL指针的孩子。
Status LastOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	BiTree prep = NULL;
	while (p)
	{
		if (p->parent == prep)//prep结点是p的父母
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
		else if (prep == p->lchild)//prep结点是p的孩子
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
//后序遍历：1.左子树2.右子树3.根节点
//非递归的算法的基本思想是：1.根节点进栈2.访问左子树3.右子树进栈。
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
//后序遍历的递推算法；递推算法即不设栈的算法；
//算法的基本思想：在结构体中增加一个parent指针域；在程序中增加一个指针代表之前访问的点；这样根据之前的指针和现在的指针能推断出，方向是哪里，所以和上一题的增加两个指针域是一样的。
//当前结点与路径的前一个结点有三种关系。头结点假定是NULL指针的孩子。
Status prepOrderTraverseByIterative(BiTree t)
{
	BiTree p = t;
	BiTree prep = NULL;
	while (p)
	{
		if (p->parent == prep)//prep结点是p的父母
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
		else if (prep == p->lchild)//prep结点是p的孩子
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