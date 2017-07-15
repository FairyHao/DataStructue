//
//  main.c
//  DataStructure2-13
//
//  Created by Amy on 16/9/15.
//  Copyright © 2016年 Amy. All rights reserved.
// Desc：在带头节点的单链表结构上实现线性表操作LOCATE(L,X);

#include <stdio.h>//defines three variable type,several macros?(NULL),and various functions for performing input and output;
#include <stdlib.h>//define for variable type,serval macros,and various function for performing general functions;
/*1.define a node;
2.typedef create new names for another data types;create alias name for Lnode,*LinkList:pefix asterisk to each variable to designate it as a pointer;
 Same as
 struct Lnode
 {
 int data;
 struct Lnode *next;
 };
 typedef struct Lnode Lnode,*LinkList;
 */
typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode,*LinkList;

typedef int Status;
#define INFEASIBLE -1
#define OK 1

//Init LinkList;
LinkList CreateList_L(int n)
{
    LinkList L = malloc(sizeof(Lnode));//malloc come from stdlib.h;allocates memory and return a pointer to it;variable is a pointer type and means address
    L->next = NULL;
    LinkList q = L;
    for(int i = n;i>0;i--)
    {
        LinkList p = malloc(sizeof(Lnode));
        //p->data = 2*i+1;
        scanf("%d",&(p->data));
        q->next = p;
        q = p;//将每个节点放在最后一个元素的后面*/
        /*将每个节点放在第一个元素位置；*/
        /*p->next=L->next;
        L->next = p;*/
    }
    return L;
}
//Init LinkList without header node
LinkList CreateList_LWithoutHeader(int n)
{
    LinkList L = malloc(sizeof(Lnode));
    LinkList p = L;
    scanf("%d",&(p->data));
    LinkList q;
    for(int i = 1;i<n;i++)
    {
        q = malloc(sizeof(Lnode));
        //p->data = 2*i+1;
        scanf("%d",&(q->data));
        p->next = q;
        p = q ;//将每个节点放在最后一个元素的后面*/
        /*将每个节点放在第一个元素位置；*/
        /*p->next=L->next;
         L->next = p;*/
    }
    return L;
}
//printf the data of the all node;
void printfL(LinkList L)//parameter：1. the address of the linklist;
{
    LinkList p = L;
    if(p)
    {
        p = p->next;//跳过头节点。
    }else
    {
        printf("It is null");
    }
    while(p)
    {
        int x = p->data;
        printf("%d ",x);
        p = p->next;
    }
    printf("\n");
}
//printf the data of the all node;without header
void printfLWithoutHeader(LinkList L)//parameter：1. the address of the linklist;
{
    LinkList p = L;
    while(p)
    {
        int x = p->data;
        printf("%d ",x);
        p = p->next;
    }
    printf("\n");
}
//2-13 在带头节点的单链表结构上实现线性表操作LOCATE(L,X);z
int Locate(LinkList L,int x)//parameter：1. address of the linklist,
{
    LinkList p = L?L->next:L;//三目运算符优先级高于赋值优先级
    //因为头节点中的元素不确定，为了避免出现后面的元素和头节点元素一致导致结果错误的情况，应该向后移。
    int i = 0;
    while(p&&p->data!=x)
    {
        i++;
        p = p->next;
    }
    if(!p)//搜索到最后，代表没有找到
    {
        return 0;
    }
    return i;
}
//2-14 在带头节点的单链表结构上实现线性表操作Length(L);
int Length(LinkList L)//包括头节点的链表长度
{
    LinkList p = L;
    int i = 0;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}

//2-15 将两个单向链表链接在一起。返回新的单链表的头地址
LinkList MergeList(LinkList A,LinkList B)
{
    /*V1，这样写太过繁琐，时间复杂度为O(n)(n>m)或者O(m)(n<m)
    if(!A||!(A->next))//如果链表A为空，则不用连接，直接返回B的头节点的地址
    {
        return B;
    }
    if(!B||!(B->next))//如果链表B为空，则不用连接，直接返回A的头节点的地址
    {
        return A;
    }//接下来的代码必须满足：A!=NULL && B!=NULL;
    int length_a = Length(A);
    int length_b = Length(B);
     LinkList C;
    if(length_a<length_b)
    {
        C = A;
        LinkList p = A;
        while(p->next)
        {
            p=p->next;
        }
        p->next = B->next;//将A的末尾连接到B除头节点外的第一个元素；
    }else
    {
        C = B;
        LinkList p = B;
        while(p->next)
        {
            p=p->next;
        }
        p->next = A->next;//将B的末尾连接到A除头节点外的第一个元素；
    }*/
    //V2 算法的时间复杂度为O(n)当m>n 或者为O(m)当m<n。所以比上述算法更优
    if(!A||!(A->next))//如果链表A为空，则不用连接，直接返回B的头节点的地址
    {
        return B;
    }
    if(!B||!(B->next))//如果链表B为空，则不用连接，直接返回A的头节点的地址
    {
        return A;
    }
    //A,B 都不为空
    LinkList pa = A;
    LinkList pb = B;
    while(pa->next&&pb->next)
    {
        pa = pa->next;
        pb = pb->next;
    }
    LinkList C;
    if(!pa->next)
    {
        C = A;
        pa->next = B->next;
    }else
    {
        C = B;
        pb->next = A->next;
    }
    return C;
}
//2-16 从表la中删除自第i个元素起共len个元素后，将他们插入到表lb中第j个元素之前；
Status DeleteAndInsertSub(LinkList a,LinkList b,int i,int j,int len)//i,j代表元素下标，从1开始
{
    if(i<1||j<1||len<0)
    {
        return INFEASIBLE;
    }
    LinkList pi,pl,prep;//pi代表la中第i个元素，pl代表la中i＋len－1个元素，即要删除的最后一个节点。prep代表第i－1个节点
    //找到prep 和 pi start
    pi = a; int k = 1;
    while(pi&&k<i)
    {
        prep = pi;
        pi = pi->next;
        k++;
    }
    //找到prep 和 pi end
    //找到pl start
    pl = pi;k=1;
    while(pl&&k<len)
    {
        pl = pl->next;
        k++;
    }
    //找到pl end
    if(!pi||!pl)
    {
        return INFEASIBLE;
    }
    //删除第i个元素起len个元素
    if(!prep)
    {
        a = pl->next;
    }else
    {
        prep->next = pl->next;
    }
    if(j==1)
    {
        pl->next=b;
        b = pi;
    }else
    {
        LinkList prepPj=b;//b表中第j个元素的前一个元素
        k = 2;//j从2开始
        while(k<j)
        {
            k++;
            prepPj = prepPj->next;
        }
        pl->next = prepPj->next;
        prepPj ->next = pi;
    }
    printfLWithoutHeader(a);
    printfLWithoutHeader(b);
    return OK;
}
//2-17 在无头节点的动态单链表上实现线性表操作INSERT(L,i,b);和带头节点
LinkList INSERT(LinkList L,int i,int b)
{
    if(i<0||!L)
    {
        return L;
    }
    LinkList newNode = malloc(sizeof(Lnode));
    newNode->data = b;
    if(i==0)
    {
        newNode->next = L;
        L = newNode;
    }else
    {
        LinkList p = L;
        int k=1;
        while(p&&k<i)
        {
            p = p->next;
            k++;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    return L;
}
//2-18 实现线性表操作DELETE(L,i)
LinkList DELETE(LinkList L,int i)
{
    if(i<0||!L)
    {
        return L;
    }
    if(i==0)
    {
        L = L->next;
    }else
    {
        LinkList p = L;
        int k = 1;
        while(p&&k<i)
        {
            p = p->next;
        }
        p->next = p->next->next;
    }
    return L;
}
//2-19 试写一个高效的算法，删除表中所有的介于两参数之间的数，并释放删除节点空间。时间复杂度:O(n)
Status DeleteBetween(LinkList l,int mink,int maxk)
{
    LinkList p;
    LinkList prep;
    if(l)
    {
        p = l->next;
        prep = l;
    }else
    {
        return INFEASIBLE;
    }
    while(p)
    {
        if((p->data)>=mink&&(p->data)<=maxk)
        {
            prep->next = p->next;
            free(p);
            p = prep->next;
        }else
        {
            prep = p;
            p = p->next;
        }
    }
    return OK;
}
//2-20 对于递增的线性链表，删除表中多余元素。同时释放被删节点空间。时间复杂度:
Status DeleteEqualEle(LinkList l)
{
    LinkList p;
    LinkList prep;
    if(l)
    {
        p = l->next;
        prep = l;
    }else
    {
        return INFEASIBLE;
    }
    while(p)
    {
        prep = p;
        p = p->next;
        if(p&&p->data == prep->data)//若是第一个元素，则是和头节点进行比较，这样是否有问题？
        {
            prep->next = p->next;
            free(p);
            p = prep;
        }
    }
    return OK;
}
//2-22 对单链表实现就地逆置
Status OppositeLocation(LinkList L)
{
    /*
    if(!L)
    {
        return INFEASIBLE;
    }
    LinkList prep = L->next;
    if(!prep)
    {
        return OK;
    }
    LinkList p = prep->next;
    prep->next = NULL;
    LinkList q = p==NULL?NULL:p->next;
    while(p&&q)
    {
        p->next = prep;
        prep = p;
        p = q;
        q= q->next;
    }
    if(p&&!q)
    {
        p->next = prep;
    }
    L->next = p;*/
    LinkList p,q;
    p=L;
    p=p->next;
    L->next=NULL;
    //这他妈的是什么
    while(p){
        q=p;
        p=p->next;
        q->next=L->next;
        L->next=q;
    }
    return OK;
}
//2-23 将两个线性表按照一定的规则合并为C
LinkList MergeListByRule(LinkList A,LinkList B)
{
    LinkList pa = A;
    LinkList pb = B;
    if(!pa||!pb)
    {
        return NULL;
    }
    pa = pa->next;
    pb = pb->next;
    LinkList tempPa,tempPb;
    while(pa&&pb)
    {
        tempPa = pa->next;
        tempPb = pb->next;
        if(tempPa)
        {
            pb->next = tempPa;
        }
        pa->next = pb;
        pa = tempPa;
        pb = tempPb;
    }
    free(B);
    return A;
}
//2-24  将两个递增的线性表合并为一个递增的线性表，要求不重新占用空间。算法思想：定义个LinkList c，将LinkList A和LinkList B 每个值比较，小的就插入到C列表中。
LinkList MergeListAsc(LinkList A,LinkList B)
{
    if(!A)
    {
        return B;
    }else if(!B)
    {
        return A;
    }
    LinkList pc = A;
    LinkList C = pc;
    LinkList pa = A -> next;
    LinkList pb = B -> next;
    while(pa&&pb)
    {
        if(pa->data>pb->data)
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }else
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
    }
    //pc->next = (pa==NULL?pb:pa);
    pc->next = pa?pa:pb;//等同于(pa==NULL?pb:pa)
    return C;
}
//2-26对两个递增的单链表，求两个集合的交集并重新分配地址存储
LinkList Mix(LinkList a,LinkList b)
{
    if(!a||!b)
    {
        return NULL;
    }
    LinkList c = malloc(sizeof(Lnode));
    LinkList pa = a->next;
    LinkList pb = b->next;
    LinkList pc = c;
    while(pa&&pb)
    {
        if(pa->data<pb->data)
        {
            pa = pa->next;
        }else if(pa->data > pb->data)
        {
            pb = pb->next;
        }else
        {
            LinkList temp = malloc(sizeof(Lnode));
            temp->data = pa->data;
            temp->next = NULL;
            pc->next = temp;
            pc = temp;
            pa = pa->next;
            pb = pb->next;
        }
    }
    return c;
}
//2-28 对两个递增的单链表，对两个集合求交集并不分配空间，直接占用A表的空间，并删除A中废弃的节点
LinkList OldMix(LinkList a,LinkList b)
{
    if(!a||!b)
    {
        return NULL;
    }
    LinkList pa = a->next;
    LinkList pb = b->next;
    LinkList prepA = a;
    LinkList prepB = b;
    LinkList temp;
    while(pa&&pb)
    {
        if(pa->data<pb->data)//即pa中的元素不可能是交集，删除即可
        {
            temp = pa;
            //删除pa节点
            pa = pa->next;
            prepA->next = pa;
            free(temp);
        }else if(pa->data>pb->data)
        {
            prepB = pb;
            pb = pb->next;
        }else
        {   //如果两个元素相等
            prepA = pa;
            prepB = pb;
            pa = pa->next;
            pb = pb->next;
        }
    }
    LinkList temp1;
    if(pa)
    {
        prepA->next = NULL;
    }
    while(pa)
    {
        temp1 = pa;
        pa = pa->next;
        free(temp1);
    }
    pb = b->next;
    while(pb)
    {
        temp1 = pb;
        pb = pb->next;
        free(temp1);
    }
    free(b);
    printfL(a);
    printfL(b);
    return a;
}
int main() {
    /*printf("-----------2-13---------\n");
    LinkList ll = CreateList_L(3);
    //----------2-13 start-----------
    int i = Locate(ll, 0);
    printf("位置为%d\n",i);
    printfL(ll);*/
    //-------2-13 end-------
    /*
    //-------2-14 start-------
    printf("-----------2-14---------\n");
    printf("链表的长度为%d\n",Length(ll));
    //-------2-14 end-------*/
    // ------------2-15 start--------------
    /*printf("-----------2-15---------\n");
    LinkList ha = CreateList_L(4);
    LinkList hb = CreateList_L(6);
    LinkList hc = MergeList(ha,hb);
    printfL(hc);*/
    //------------2-15 end--------------
    //------------2-16 start------------
    /*LinkList ha = CreateList_LWithoutHeader(4);
    LinkList hb = CreateList_LWithoutHeader(6);
    printfLWithoutHeader(ha);
    printfLWithoutHeader(hb);
    DeleteAndInsertSub(ha, hb, 2, 1, 2);*/
    //------------2-16 end------------
    /*
    //------------------2-17 start--------------
    LinkList lll =CreateList_L(3);
    printfL(lll);
    lll = INSERT(lll,0,5);
    printfL(lll);
    lll = INSERT(lll,1,6);
    printfL(lll);
    //------------------2-17 end ---------------
    //------------------2-18 start ---------------
    lll = DELETE(lll,0);
    printfL(lll);
    lll = DELETE(lll,1);
    printfL(lll);
    //------------------2-18 end ---------------*/
    /*
    //------------------2-19 start---------------
    LinkList llll = CreateList_L(10);
    printfL(llll);
    DeleteBetween(llll,3,10);
    printfL(llll);
    //------------------2-19 end-----------------*/
    //------------------2-20 start---------------
    /*LinkList lllll = CreateList_L(10);
    printfL(lllll);
    DeleteEqualEle(lllll);//printf status????
    printfL(lllll);*/
    //-----------------2-20 end
    /*
    //-----------------2-22 Start--------------
    LinkList lllll = CreateList_L(5);
    printfL(lllll);
    OppositeLocation(lllll);
    printfL(lllll);
    //-----------------2-22 end ---------------*/
    //-----------------2-23 Start--------------
    /*LinkList A = CreateList_L(2);
    LinkList B = CreateList_L(2);
    printfL(A);
    printfL(B);
    LinkList C = MergeListByRule(A,B);
    printfL(C);*/
    //-----------------2-23 End--------------
    //-----------------2-24 Start--------------
    /*LinkList A = CreateList_L(4);
    LinkList B = CreateList_L(3);
    printfL(A);
    printfL(B);
    LinkList C = MergeListAsc(A,B);
    OppositeLocation(C);
    printfL(C);*/
    //-----------------2-24 end--------------
    //-----------------2-26 Start--------------
    /*LinkList a = CreateList_L(10);
    LinkList b = CreateList_L(8);
    printfL(a);
    printfL(b);
    LinkList c = Mix(a,b);
    printfL(c);*/
    //-----------------2-26 end--------------
    //------------------2-28 Start-------------
    /*LinkList a = CreateList_L(5);
    LinkList b = CreateList_L(3);
    printf("a本来的元素");
    printfL(a);
    DeleteEqualEle(a);
    printf("a去重后的元素");
    printfL(a);
    printf("b本来的元素");
    printfL(b);
    DeleteEqualEle(b);
    printf("b去重后的元素");
    printfL(b);
    OldMix(a,b);
    printf("求交集之后的元素a");
    printfL(a);*/
    //------------------2-28 end
    return 0;
}
