#pragma once
const int VERTEX_NUM=20;

class CQueue
{
public:
	int Que[VERTEX_NUM];
	int front;
	int rear;
public:
	CQueue(void);
	~CQueue(void);
	int QueueEmpty();
	void EnQueue(int);
	int DeQueue();
};
