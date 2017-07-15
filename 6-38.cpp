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
//�㷨�Ļ���˼�룺�ݣ�1. ����������������ָ������������2.��������ջ3.���ڵ���ջ��
//�飺����С�����ǣ�����������Ϊ�գ����������������Ѿ����ʹ��ˡ�
//��Ϊ�������͸��ڵ㶼��ջ�У�������pop����ʱ1.���ڵ�ֻ��Ҫ���ʴ˽ڵ㡣2.�Ǹ��ڵ���Ҫ�Ѵ˵����������������
Status LastOrderTraverseByStack(BiTree t)
{
	ss s = initStack();
	BiTree p = t;
	bool isRoot = false;
	//������һ��ѭ����ʵ�ֵݹ顣
	while (p||!StackEmpty(s))
	{
		if (p&&!isRoot)//��p����һ��������1.���ڵ���ջ2.��������ջ(����Ϊ��һ������ݵĹ���)
		{
			//��Ÿ��ڵ㵽ջ��
			BiTreeAndFlag *bf = (BiTreeAndFlag*)malloc(sizeof(BiTreeAndFlag));
			bf->bi = p;
			bf->IsRoot = true;
			push(s, *bf);
			//�����������ջ��
			BiTreeAndFlag *rightChildbf = (BiTreeAndFlag*)malloc(sizeof(BiTreeAndFlag));
			rightChildbf->bi = (p->rchild);
			rightChildbf->IsRoot = false;
			push(s, *rightChildbf);
			p = p->lchild;
		}
		/*��p����һ�����ʱ������������������Ѿ��������ˣ�����ʸ���㣻������Ϊ������С���⣬��һ����Ĺ��̣�
			��������֮��Ҫ�������ʱ�ģ�����Ҫpop*/
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
		else//pΪ�գ����ʾ������Ϊ�գ����ٴ�popһ����pop������Ӧ���Ǹ��ڵ㣻
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
	BiTree q = (BiTree)malloc(sizeof(BiTnode));//�ȼٶ���һ��ͷ���
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