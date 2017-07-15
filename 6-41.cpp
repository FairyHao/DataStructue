#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct BiTnode
{
	char data;
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
int printElement(char e)
{
	printf("%c", e);
	return 1;
}

char prepOrderTraverse(BiTree t,int i,int k)//i代表当前是第几个元素，k代表要寻找的结点的位置
{
	if (t)
	{
		i++;
		if (i==k)
		{
			return t->data;
		}
		char x = prepOrderTraverse(t->lchild, i, k);
		if (x != '\0')
		{
			return x;
		}
		return prepOrderTraverse(t->rchild,i,k);
	}
	return '\0';
}
//6-42
int NodeNumber(BiTree t)//叶子结点的数目
{
	if (!t)
	{
		return 0;
	}
	if (!t->lchild&&!t->rchild)
	{
		return 1;
	}
	return NodeNumber(t->lchild)+NodeNumber(t->rchild);
}
//6-43
Status ChangeChild(BiTree t)
{
	if (t)
	{
		BiTree temp = t->lchild;
		t->lchild = t->rchild;
		t->rchild = temp;
		ChangeChild(t->lchild);
		ChangeChild(t->rchild);
	}
	return OK;
}
//6-44 section1
BiTree prepOrderTraverse(BiTree t, char x)
{
	if (t)
	{
		if (t->data == x)
		{
			return t;
		}
		BiTree xt = prepOrderTraverse(t->lchild,x);
		if (xt)
		{
			return xt;
		}
		return 	prepOrderTraverse(t->rchild,x);

	}
	return NULL;
}
//6-44 section2
int depth(BiTree t)
{
	if (!t)
	{
		return 0;
	}
	int depthL = depth(t->lchild)+1;
	int depthR = depth(t->rchild)+1;
	return depthL > depthR ? depthL : depthR;
}
int main()
{
	char tree[] = "abd g  e  c f  ";// abd g  e  c f    ab  c  
	BiTree bt = Create(tree);
	/*int i = 0;
	char x = prepOrderTraverse(bt, i, 4);
	cout << x << endl;
	int num = NodeNumber(bt);
	cout << num << endl;*/
	//ChangeChild(bt);
	BiTree t = prepOrderTraverse(bt,' ');
	int x = depth(t);
	cout << x << endl; 
	while (1)
	{
	}
	return 0;
}