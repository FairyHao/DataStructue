#include <iostream>

using namespace std;
typedef int Status;

#define ERROR 0
#define OK 1
#define INFEASIBLE 2

typedef struct BiTnode
{
	char data;
	struct BiTnode *lchild, *rchild;
}BiTnode, *BiTree;

#define MAXSIZE 100

typedef  struct
{
	BiTree *base;
	int rear;
	int front;
	int tag;//标志栈满还是栈空；0：空；1：满
}SqQueue, *Sq;

Sq initQueue()
{
	Sq sq = (Sq)malloc(sizeof(BiTree));
	if (!sq)
	{
		exit(0);
	}
	sq->base = (BiTree *)malloc(MAXSIZE*sizeof(BiTree));
	if (!sq->base)
	{
		exit(0);
	}
	sq->front = 0;
	sq->rear = 0;
	sq->tag = 0;
	return sq;
}

int EnQueue(Sq sq, BiTree x)
{
	if (sq->tag == 1 && sq->front == sq->rear)
	{
		printf("Sorry,the queue is full\n");
		return -1;
	}
	(*sq).base[sq->rear] = x;
	if (sq->rear >= MAXSIZE - 1)
	{
		sq->rear = 0;
	}
	else
	{
		(sq->rear)++;
	}
	if (sq->front == sq->rear)
	{
		sq->tag = 1;
	}
	return 0;
}

BiTree DeQueue(Sq sq)
{
	if (sq->tag == 0 && sq->front == sq->rear)
	{
		printf("Sorry,the queue is empty\n");
		return NULL;
	}
	BiTree x = (*sq).base[sq->front];
	if (sq->front >= MAXSIZE - 1)
	{
		sq->front = 0;
	}
	else
	{
		(sq->front)++;
	}
	if (sq->front == sq->rear)
	{
		sq->tag = 0;
	}
	return x;
}
int queueEmpty(Sq queue)
{
	if (queue->tag == 0 && queue->front == queue->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	return 0;
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
//6-52获取各层中结点数的最大值
int numOfNode(BiTree t)
{
	Sq queue1 = initQueue();
	Sq queue2 = initQueue();
	EnQueue(queue1, t);
	int i = 1;
	int number = 0;
	int max = 0;
	while (!queueEmpty(queue1) || !queueEmpty(queue2))
	{
		if (i % 2 == 1)
		{
			while (!queueEmpty(queue1))
			{
				BiTree p = DeQueue(queue1);
				if (p->lchild)
				{
					EnQueue(queue2, p->lchild);
				}
				if (p->rchild)
				{
					EnQueue(queue2, p->rchild);
				}
				number++;
			}
		}
		else
		{
			while (!queueEmpty(queue2))
			{
				BiTree p = DeQueue(queue2);
				if (p->lchild)
				{
					EnQueue(queue1, p->lchild);
				}
				if (p->rchild)
				{
					EnQueue(queue1, p->rchild);
				}
				number++;
			}
		}
		if (number > max)
		{
			max = number;
			number = 0;
		}
		i++;
	}
	return max;
}
//6-52 section2
int depth(BiTree t)
{
	if (!t)
	{
		return 0;
	}
	int depthL = depth(t->lchild) + 1;
	int depthR = depth(t->rchild) + 1;
	return depthL > depthR ? depthL : depthR;
}

int main()
{
	char tree[] = "abd g  e h  ci  f  ";// abd g  e  c f    ab  c  
	BiTree bt = Create(tree);
	//LevelTraverse(bt);
	//cout << IsAllTree(bt) << endl;
	cout<<depth(bt)*numOfNode(bt)<<endl;
	while (1)
	{
	}
}
