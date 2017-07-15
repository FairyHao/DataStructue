#pragma once

#define MAX_VERTEX_NUM 20

class Stack
{
private:
	int base[MAX_VERTEX_NUM];
	int top;
public:
	Stack(void);
	~Stack(void);
	int  StackEmpty();
	void Push(int);
	int Pop();	
};
