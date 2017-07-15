#pragma once

const int Size=25;

class CSqStack
{
public:
	int base[Size];
	int top;
public:
	CSqStack(void);
	~CSqStack(void);
	int  StackEmpty();
	void Push(int);
	void Pop();
	int GetTop();	
};
