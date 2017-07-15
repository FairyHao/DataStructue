#include <iostream>

using namespace std;
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct BiTnode
{
	int data;
	struct BiTnode *lchild, *rchild;
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
		}
	}
	return t;
}
int j = 0;
BiTree Create(int s[])
{
	int ch;
	ch = s[j++];
	BiTree t;
	if (ch == 0)
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
//判断一颗树是不是排序二叉树?
//排序二叉树的中序遍历序列是从小到大的。
int last = 0;
bool IsBinarySortTree(BiTree bt)
{
	if (!bt)
	{
		return true;
	}
	if (!IsBinarySortTree(bt->lchild))
	{
		return false;
	}
	if (bt->data<last)
	{
		return false;
	}
	last = bt->data;
	if (!IsBinarySortTree(bt->rchild))
	{
		return false;
	}
	return true;
}
//9-32 
int max = 10;
int prepNum = -max;
void searchBinaryTree(BiTree t,int x)
{
	if (t->lchild)
	{
		searchBinaryTree(t->lchild, x);
	}
	if (x > prepNum && t->data > x)
	{
		cout << prepNum<<endl;
		cout << x<<endl;
		cout << t->data << endl;
		exit;
	}
	prepNum = t->data;
	if (t->rchild)
	{
		searchBinaryTree(t->rchild, x);
	}
}
int main()
{
	//char tree[] = "eca b  d  f g  ";// abd g  e  c f    ab  c     eca b  d  f g  
	//BiTree bt = Create(tree);
	//bool flag = IsBinarySortTree(bt);
	int tree1[] = {7,3,-13,0,0,5,0,6,0,0,10,8,0,0,12,0,13,0,0};
	BiTree bt = Create(tree1);
	searchBinaryTree(bt,4);
	while (1)
	{
	}
}