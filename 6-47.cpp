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
	int tag;//��־ջ������ջ�գ�0���գ�1����
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
//6-47��α���
Status LevelTraverse(BiTree t)
{
	Sq queue = initQueue();
	EnQueue(queue, t);
	while (!queueEmpty(queue))
	{
		BiTree p = DeQueue(queue);
		printElement(p->data);
		if (p->lchild)
		{
			EnQueue(queue,p->lchild);
		}
		if (p->rchild)
		{
			EnQueue(queue, p->rchild);
		}
	}
	return OK;
}
//6-49
int  IsAllTree(BiTree t)
{
	Sq queue = initQueue();
	int flag = 0;
	EnQueue(queue, t);
	while (!queueEmpty(queue))
	{
		BiTree p = DeQueue(queue);
		if (flag ==0 &&p->lchild)
		{
			EnQueue(queue, p->lchild);
		}
		else if (flag == 1 && p->lchild)
		{
			return 0;
		}
		else
		{
			flag = 1;
		}
		if (flag == 0 && p->rchild)
		{
			EnQueue(queue, p->rchild);
		}
		else if (flag == 1 && p->rchild)
		{
			return 0;
		}
		else
		{
			flag = 1;
		}
	}
	return 1; 
}

int main()
{
	char tree[] = "a  ";// abd g  e  c f    ab  c  
	BiTree bt = Create(tree);
	//LevelTraverse(bt);
	cout<<IsAllTree(bt)<<endl;
	while (1)
	{
	}
}
