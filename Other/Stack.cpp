#include "StdAfx.h"
#include "Stack.h"
#include "iostream"
using namespace std;

Stack::Stack(void)
{
	top=-1;
}

Stack::~Stack(void)
{
}

int Stack::StackEmpty(){
	if(-1==top)
		return 1;
	else
		return 0;
}

void Stack::Push(int x){
	top++;
	base[top]=x;
}

int Stack::Pop(){
	int c;
	if(-1!=top)
		c=base[top];
	top--;
	return c;
}