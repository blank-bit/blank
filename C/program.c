#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct PolyNode{
int expn;  //指数
double coef;//系数
struct PolyNode *next;
}LNode,*LinkList;
//2．几个基本操作的函数
    LNode *MakeNode (double coef,int expn)//制造节点
    {
        LNode *p;
        p=(LNode*)malloc(sizeof(LNode));
        p->coef=coef;
        p->expn=expn;
        p->next=NULL;
        return p;
    }

//LNode *MakeNode(double coef, int exp)  //通过传入指数和系数创建一个节点，返回该节点的地址。
void InitList(LinkList &L) //初始化，带头节点
void PrintPolyn (LinkList L)// 传入链表的指针，打印该链表
LinkList CreatPolyn(void)//输入m项的系数和指数，建立表示一元多项式的有序链表L
double SumPolyn(LinkList L,double x) //传入链表的指针及x值，求多项式的值。
void DestroyPolyn (LinkList &L) //销毁多项式，去掉头节点
void ClearPolyn (LinkList &L) //清空多项式，保留节点
void CopyPolyn (LinkList La, LinkList &Lb) //将La位置的多项式复制到Lb位置
void AddPolyn(LinkList  L,LinkList J ,LinkList &K) //将a和b多项式相加存到c
void MultiplyPolyn(LinkList L,LinkList J,LinkList &K) //将a和b相减存到c
void MultiplyPolyn(LinkList L,LinkList J,LinkList &K) //将a和b多项式相乘存到c
void OrderInsert(LinkList L,LNode *r){  //根据链表的expn指数域，对链表进行升序插入。
void DifferentialPolyn(LinkList L,LinkList &L2) //对L1求导存到L2
void IntegralPolyn(LinkList L,LinkList &L2)   // 对L1积分存到L2

void OrderInsert(LinkList L,LNode *r){  //根据链表的expn指数域，对链表进行升序插入
if(!L)
printf("error");
LNode *p,*q;
p=L;
while(p->next&&p->next->expn<r->expn) p=p->next;
if(p->next&&p->next->expn==r->expn)
{
p->next->coef+=r->coef;
if(p->next->coef==0){
q=p->next;
p->next=q->next;
free(q);
}
free(r);
}
else{
r->next=p->next;
p->next=r;
}
}

void AddPolyn(LinkList L,LinkList J,LinkList &K){//多项式相加
if(!L||!J){
printf("error\n");
return;}
LNode *p,*q,*m;
p=L->next;
q=J->next;
InitList(K);
while(p)
{
m=MakeNode(p->coef,p->expn);
OrderInsert(K,m);
p=p->next;
}
while(q) {
m=MakeNode(q->coef,q->expn);
OrderInsert(K,m);
q=q->next;
}
}

void MultiplyPolyn(LinkList L,LinkList J,LinkList &K){//多项式相乘
if(!L||!J) {
printf("error");
return;
}
LNode *p,*q,*m;
p=L->next;
InitList(K);
while(p){
q=J->next;
while(q){
m=MakeNode(p->coef*q->coef,p->expn+q->expn);
OrderInsert(K,m);
q=q->next;
}
p=p->next;
}
}

LinkList CreatPolyn(void)//输入m项的系数和指数，建立表示一元多项式的有序链表L
{ 
LNode *p;
LinkList head;
double c;
int e;
InitList(head);
printf("输入系数、指数，系数为0时结束");
while(1){
scanf("%lf",&c);
if(c==0) break;
scanf("%d",&e);
p=MakeNode(c,e);
OrderInsert(head,p);
}
return head;
}

void DifferentialPolyn(LinkList L,LinkList &L2){ //求导
LNode *p,*r;
if(!L) return;
InitList(L2);
r=L2;
p=L->next;
while(p){
if(p->expn==0)
r->next=MakeNode(0,0);
else
r->next=MakeNode(p->coef*p->expn,p->expn-1);
r=r->next;
p=p->next;
}
r->next=NULL;
}

#define N 12

void main()
{
    LinkList P[N]={NULL};
    int menu,i,j,l;
    double k,sum;
    while(1)
    {
    printf("\n");
    printf("          多项式计算器 \n");
    printf("======================================\n");
    printf("    新建--1    打印--2    复制--3\n");
    printf("    求值--4    相加--5    相减--6\n");
    printf("    微分--7    销毁--8    清空--9\n");
    printf("    积分--10  相乘--11  退出--0\n");
    printf("======================================\n");
    printf(" 请选择：\n");
    scanf("%d",&menu);
    switch(menu){
        case 0:return;
        case 1:
            printf("输入新多项式的下标(0--%d):",N-1);
            scanf("%d",&i);
            P[i]=CreatPolyn();
            break;
        case 2:for(i=0;i<N;i++)
        {
        printf("  P[%d] = ",i);
        printPolyn(P[i]);
        }
        break;
        case 3:
        printf("输入被复制的多项式和新多项式的下标(0--%d): ",N-1);
        scanf("%d%d",&i,&j);
CopyPolyn(P[i],P[j]);
break;
case 4:
printf("输入要求值多项式的下标(0--%d)和X值:",N-1);
scanf("%d%lf",&i,&k);
sum=SumPolyn(P[i],k);
printf("多项式值为%lf",sum);
break;
case 5:
printf("输入相加两项的多项式和新多项式的下标(0--%d): ",N-1);
scanf("%d%d%d",&i,&j,&l);
AddPolyn(P[i],P[j],P[l]);
break;
case 6:
printf("输入减两项的多项式和新多项式的下标(0--%d): ",N-1);
scanf("%d%d%d",&i,&j,&l);
MinusPolyn(P[i],P[j],P[l]);
break;
case 7:
printf("输入求导的多项式的下标(0--%d)和新多项式的下标(0--%d): ",N-1,N-1);
scanf("%d%d",&i,&j);
DifferentialPolyn(P[i],P[j]);
break;
case 8:
printf("输入被销毁多项式的下标(0--%d): ",N-1);
scanf("%d",&i);
DestroyPolyn(P[i]);
break;
case 9:
printf("输入被清空多项式的下标(0--%d): ",N-1);
scanf("%d",&i);
ClearPolyn(P[i]);
break;
case 10:
printf("输入求积分的多项式的下标(0--%d)和新多项式的下标(0--%d): ",N-1,N-1);
scanf("%d%d",&i,&j);
IntegralPolyn(P[i],P[j]);
break;       
case 11:
printf("输入相乘两项的多项式和新多项式的下标(0--%d): ",N-1);
scanf("%d%d%d",&i,&j,&l);
MultiplyPolyn(P[i],P[j],P[l]);
break;
}
}
}