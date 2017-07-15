#include "StdAfx.h"
#include "CSqStack.h"
#include "iostream"
using namespace std;

CSqStack::CSqStack(void)
{
	top = -1;
}

CSqStack::~CSqStack(void)
{
}

int CSqStack::StackEmpty()  //判断栈是否为空
{
	if(-1 == top)
		return 1;
	else return 0;
}



void CSqStack::Push(int x)  //入栈
{
	top++;
	base[top]=x;
}


void CSqStack::Pop()      //出栈
{
	if(-1 != top)
		top--;
}


int CSqStack::GetTop()
{                        //取栈顶元素
	int c;
	if(-1 != top)
		c=base[top]; 
	return c;
}