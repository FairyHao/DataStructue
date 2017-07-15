//
//  main.c
//  3-24
//
//  Created by Amy on 16/10/11.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>

int func_g(int m,int n)
{
    if(n < 0 || m < 0)
    {
        return -1;
    }
    if(m == 0 && n >= 0)
    {
        return 0;
    }
    if(m > 0 && n >= 0)
    {
        return func_g(m-1,2*n) + n;
    }
    return 0;
}

int func_F(int n)
{
    if(n == 0)
    {
       return 1;
    }else if(n>0)
    {
        return func_F(n/2)*n;
    }else
    {
        return 0;
    }
}
double func_sqrt(double A,double p,double e)
{
    if(p*p-A<e && p*p-A>-e)
    {
        return p;
    }else
    {
        return func_sqrt(A,1.0/2*(p+A/p),e);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //printf("%d",func_g(5, 2));
    //printf("%d",func_F(10));
    //printf("%f",func_sqrt(10000000,0.1,0.0001));
    return 0;
}
