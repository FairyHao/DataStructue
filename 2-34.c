//
//  main.c
//  2-34
//
//  Created by Amy on 16/10/7.
//  Copyright © 2016年 Amy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct XorNode{
    char data;
    struct XorNode *LRptr;
}XorNode,*Xorpoiter;

typedef struct
{
    Xorpoiter Left,Right;
}XorLinkedList;

Xorpoiter Xorp(Xorpoiter p,Xorpoiter q);

//2-34 从左向右或从右向左遍历此双向链表的操作。这道题无法验证，因为不明确Xorp的算法。
int TraversingLinkList(XorLinkedList l,char direction)//direction参数代表从左向右，或者从右向左
{
    Xorpoiter p,left,right,q;
    if(direction=='L'||direction=='l')//代表从左向右
    {
        p = l.Left;
        left = NULL;
        while(p)
        {
            //和答案不一样。我认为这样是正确的。答案为left=p;p=XorP(left,p->LRPtr);
            printf("%d",p->data);
            q = p;
            p = Xorp(left, p->LRptr);
            left = q;
        }
    }else if(direction=='R'||direction=='r')
    {
        p = l.Right;
        right = NULL;
        while(p)
        {
            printf("%d",p->data);
            q = p;
            p = Xorp(p->LRptr,right);
            right = q;
        }
    }
    return 0;
}
//2-35在第i个节点之前插入一个节点的算法。
int InsertNode(XorLinkedList l,int i)
{
    Xorpoiter newNode= malloc(sizeof(XorNode));//新增一个节点。
    if(i==1)//若在第一个节点之前插入节点。
    {
        newNode->LRptr = Xorp(NULL, l.Left);
        l.Left->LRptr =Xorp(newNode, Xorp(NULL,l.Left->LRptr));
        l.Left = newNode;
    }else//在第二个节点之前插入节点
    {
        int k = 1;
        Xorpoiter p,left,q,pi,after;//用p遍历双向列表，最终指向i－1的位置；pi为i个位置上的指针，after代表i＋1位置的指针。
        p = l.Left;
        left = NULL;
        while(p&&k!=i-1)
        {
            q = p;
            p = Xorp(left, p->LRptr);
            left = q;
            k++;
        }
        pi = Xorp(left,p->LRptr);
        p->LRptr = Xorp(left,newNode);
        newNode->LRptr = Xorp(p,pi);
        after = Xorp(p, pi->LRptr);
        pi->LRptr = Xorp(newNode, after);
    }
    return 0;
}
//2-36 删除第i个节点
int DeleteNode(XorLinkedList l,int i)
{
    if(i==1)
    {
        Xorpoiter p = Xorp(NULL,l.Left->LRptr);
        Xorpoiter q = Xorp(l.Left,p);
        p->LRptr = Xorp(NULL,q);
        l.Left = p;
    }else
    {
        int k = 1;
        Xorpoiter p,left,q,pi,after,after2;//用p遍历双向列表，最终指向i－1的位置；pi为i个位置上的指针，after代表i＋1位置的指针;after2 代表i+2位置的指针
        p = l.Left;
        left = NULL;
        while(p&&k!=i-1)
        {
            q = p;
            p = Xorp(left, p->LRptr);
            left = q;
            k++;
        }
        pi = Xorp(left,p->LRptr);
        after = Xorp(p, pi->LRptr);
        after2 = Xorp(p, after2->LRptr);
        p->LRptr = Xorp(left,after);
        after->LRptr = Xorp(p,after2);
    }
    return 0;
}
//2-37
int main(int argc, const char * argv[]) {
    XorLinkedList l;
    TraversingLinkList(l,'r');
    return 0;
}
