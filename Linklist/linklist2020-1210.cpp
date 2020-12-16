#include<iostream>
using namespace std;
#include<cstring>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	char id[20];
	char name[50];
	float length;
	float weight;
	char color[20];
	bool is_Carnivore;
	bool is_Marine;	
} ElemType;
	
typedef struct LNode
{
     ElemType   data;       //数据域
     struct LNode  *next;   //指针域
}LNode,*LinkList;

void write_fish(ElemType &e)
{
	cout<<"输入id"<<endl;
	cin>>e.id; 
	cout<<"输入name"<<endl; 
	cin>>e.name;
	cout<<"输入length"<<endl; 
	cin>>e.length;
	cout<<"输入weight"<<endl; 
	cin>>e.weight;
	cout<<"输入color"<<endl; 
	cin>>e.color;
	cout<<"输入is_Carnivore"<<endl; 
	cin>>e.is_Carnivore;
	cout<<"输入is_Marine"<<endl; 
	cin>>e.is_Marine;
}
void read_fish(ElemType e)
{
	cout<<e.id<<endl;
	cout<<e.name<<endl;
	cout<<e.length<<endl;
	cout<<e.weight<<endl;
	cout<<e.color<<endl;
	cout<<e.is_Carnivore<<endl;
	cout<<e.is_Marine<<endl;
}
void evaluate(ElemType &e1,ElemType e2)
{
	strcpy(e1.id,e2.id);
	strcpy(e1.name,e2.name);
	e1.length=e2.length;
	e1.weight=e2.weight;
	strcpy(e1.color,e2.color);
	e1.is_Carnivore=e2.is_Carnivore;
	e1.is_Marine=e2.is_Marine;
}
Status InitList_L(LinkList &L){ 
   L=new LNode;
   L->next=NULL;
   return OK; 
} 
//Status DestroyList_L(LinkList &L)
//{
//    LinkList p;
//    while(L)
//    {
//        p=L;  
//        L=L->next;
//        delete p;  
//     }
//     return OK;
// }
//Status GetElem_L(LinkList L, int i, ElemType &e){ 
//    LinkList p;
//	int j;
//	p=L->next; j=1; //初始化
//     while(p && j<i){	//向后扫描，直到p指向第i个元素或p为空 
//       p=p->next; ++j; 
//     } 
//     if(!p || j>i) return ERROR; //第i个元素不存在 
//     e=p->data; //取第i个元素 
//     return OK; 
//}//GetElem_L
//LNode *LocateELem_L1(LinkList L, ElemType e) { //返回L中值为e的数据元素的地址，查找失败返回NULL
//  LinkList p;
//  p=L->next;
//  while(p && p->data!=e)  
//        p=p->next;                		
//  return p; 	
//} 
//int LocateELem_L2 (LinkList L,ElemType e) {
// //返回L中值为e的数据元素的位置序号，查找失败返回0 
//  LinkList p=L->next; 
//  int j=1;
//  while(p &&p->data!=e)  
//        {p=p->next;  j++;}          		
//  if (p)   return j; 
//  else return 0;
//} 
Status ListInsert_L(LinkList &L, int i, ElemType e){ 
     LinkList p=L,s; int j=0; 
      while( p && j<i-1 ){ p=p->next; ++j; }	//寻找第i-1个结点 
      if(!p || j>i-1)   return ERROR;	//i大于表长+1或者小于1  
      s=new LNode;			//生成新结点s 
      //s->data=e;      		           //将结点s的数据域置为e 
      evaluate(s->data,e);
	  s->next=p->next;	   	          //将结点s插入L中 
      p->next=s; 
      return OK; 
}//ListInsert_L 
//void CreateList_F ( LinkList &L, int n) { 
//     L=new LNode; 
//     L->next=NULL; //先建立一个带头结点的空单链表 
//     for(int i=n; i>0 ;--i){ 
//     LinkList  p=new LNode; //生成新结点 
//     cin>>p->data; //输入元素值 
//     p->next=L->next; 
//	 L->next=p; 	//插入到表头 
//     } 
//}//CreateList_F 
void CreateList_L(LinkList &L,int n){ 
      //正位序输入n个元素的值，建立带表头结点的单链表L 
      L=new LNode; 
      L->next=NULL; 	
      LinkList r=L; 	                                //尾指针r指向头结点 
      cout<<"输入"<<n<<"个数据元素"<<endl;
	  for(int i=0;i<n;++i){
		LinkList p=new LNode;      //生成新结点 
		//cin>>p->data;   		       //输入元素值 
		write_fish(p->data);
        p->next=NULL; r->next=p;       //插入到表尾 
        r=p; 	                                  //r指向新的尾结点 
      } 
}//CreateList_L 

//Status ListDelete_L( LinkList &L, int i, ElemType &e) {
//    LinkList p=L; int j=0; 
//    while( p->next && j<i-1) {                  //寻找第i-1个结点，并令p指向它 
//        p=p->next; ++j; 
//    } 
//    if( !(p->next) || j>i-1 ) return  ERROR; //删除位置不合理 
//    LinkList q=p->next;                                        //临时保存被删结点的地址以备释放 
//    p->next=q->next; 	                  //改变删除结点前驱结点的指针域 
//    e=q->data; 	                                //保存删除结点的数据域 
//    delete q; 	                                //释放删除结点的空间 
// return OK; 
//}//ListDelete_L 

void Print_L( LinkList L)
{
	LinkList p=L->next;
	while(p)
	{
		//cout<<p->data<<" ";
		read_fish(p->data);
		p=p->next;
	}
	cout<<endl;

}

void print_menu()
{
	cout<<"Fish管理系统功能菜单"<<endl;
	cout<<"1.增加Fish;"<<endl;
	cout<<"2.删除Fish;"<<endl;
	cout<<"3.修改Fish;"<<endl;
	cout<<"4.查询Fish信息;"<<endl;
	cout<<"5.统计Fish个数;"<<endl;
	cout<<"6.输出Fish列表;"<<endl;
	cout<<"7.退出;"<<endl;
	cout<<"请输入你的选择（1-7）："<<endl;
	
} 
int main()
{
	LinkList list;
	ElemType e;
	int n,flag,i,state;
	InitList_L(list);
	cout<<"尾插几个数据元素？"<<endl;
	cin>>n;
	CreateList_L(list,n); 
	cout<<"尾插法建非空单链表"<<endl;
	while(1)
	{
		print_menu();
		cin>>flag;
		switch(flag)
		{
			case 1:{
				cout<<"待插入的位置"<<endl;
				cin>>i; 
				cout<<"待插入的数据"<<endl;
				//cin>>e;
				write_fish(e);
				state=ListInsert_L(list, i, e);
				if(state==OK) cout<<"插入成功"<<endl;
				else cout<<"插入失败"<<endl; 
				break;
			}
			case 2:{
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				break;
			}
			case 5:{
				break;
			}
			case 6:{
				Print_L( list);
				break;
			}
			default: return 0;
			
		}
	}
//	cout<<"尾插几个数据元素？"<<endl;
//	cin>>n;
//	CreateList_L(list,n); 
//	cout<<"尾插法建非空单链表"<<endl;
//	cout<<"遍历单链表"<<endl;
//	Print_L(list);
//	ListDelete_L(list,1, e);
//	cout<<"删除第一个元素"<<endl;
//	cout<<"遍历单链表"<<endl;
//	Print_L(list);
//	DestroyList_L(list);
//	cout<<"销毁单链表"<<endl;
	return 0;

}
