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
}BiTnode, *BiTree;
typedef struct BiTreeAndFlag
{
	BiTree bi;
	bool IsRoot;
}BiTreeAndFlag;
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
//算法的基本思想：递：1. 访问左子树，即将指针移至左子树2.右子树入栈3.根节点入栈。
//归：即最小问题是：左右子树都为空，或者左右子树都已经访问过了。
//因为右子树和根节点都在栈中，当他们pop出来时1.根节点只需要访问此节点。2.非根节点需要把此当作后序遍历来访问
Status LastOrderTraverseByStack(BiTree t)
{
	ss s = initStack();
	BiTree p = t;
	bool isRoot = false;
	//利用了一个循环来实现递归。
	while (p||!StackEmpty(s))
	{
		if (p&&!isRoot)//当p代表一颗树；则1.根节点入栈2.右子树入栈(我认为这一步代表递的过程)
		{
			//存放根节点到栈中
			BiTreeAndFlag *bf = (BiTreeAndFlag*)malloc(sizeof(BiTreeAndFlag));
			bf->bi = p;
			bf->IsRoot = true;
			push(s, *bf);
			//存放右子树到栈中
			BiTreeAndFlag *rightChildbf = (BiTreeAndFlag*)malloc(sizeof(BiTreeAndFlag));
			rightChildbf->bi = (p->rchild);
			rightChildbf->IsRoot = false;
			push(s, *rightChildbf);
			p = p->lchild;
		}
		/*当p代表一个结点时，则代表左右子树都已经访问完了，则访问跟结点；（我认为这是最小问题，是一个归的过程）
			访问完了之后要继续访问别的，所以要pop*/
		else if (p&&isRoot)
		{
			if (!printElement(p->data))
			{
				return ERROR;
			}
			if (!StackEmpty(s))
			{
				BiTreeAndFlag bf = pop(s);
				p = bf.bi;
				isRoot = bf.IsRoot;
			}
			else
			{
				p = NULL;
			}
		}
		else//p为空，则表示右子树为空；则再次pop一个，pop出来的应该是根节点；
		{
			BiTreeAndFlag bf = pop(s);
			p = bf.bi;
			isRoot = bf.IsRoot;
		}
	}
	return OK;
}
//6-46
BiTree CopyTree(BiTree t)
{
	BiTree newT = NULL;
	ss s = initStack();
	BiTree p = t;
	BiTree q = (BiTree)malloc(sizeof(BiTnode));//先假定有一个头结点
	//int flag = 0;
	bool flag = true;
	while (p||!StackEmpty(s))
	{
		if (p)
		{
			//BiTree temp=(BiTree)malloc(sizeof(BiTnode));
			push(s,p);
			push(s,p->rchild);
			p = p->lchild;
		}
		else
		{
			p = pop(s);
			flag = true;
		}
	}
}
int main()
{
	char tree[] = "abd g  e  c f  ";
	BiTree bt = Create(tree);
	LastOrderTraverse(bt);
	printf("\n");
	LastOrderTraverseByStack(bt);
	while(1)
	{
	}
	return 0;
}