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

int CSqStack::StackEmpty()  //�ж�ջ�Ƿ�Ϊ��
{
	if(-1 == top)
		return 1;
	else return 0;
}



void CSqStack::Push(int x)  //��ջ
{
	top++;
	base[top]=x;
}


void CSqStack::Pop()      //��ջ
{
	if(-1 != top)
		top--;
}


int CSqStack::GetTop()
{                        //ȡջ��Ԫ��
	int c;
	if(-1 != top)
		c=base[top]; 
	return c;
}