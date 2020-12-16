/*
 * @Author       : Mr.Wang
 * @Date         : 2020-12-11 00:40:21
 * @FilePath     : /Linklist/linklist.h
 * @Description  : message
 */
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<malloc.h>

using namespace std;
#define MAX_LENGTH 50
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

#define kinderfisher
#ifdef kinderfisher
typedef struct kingfisher
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
    char color[MAX_LENGTH];
    int speed;
}INFO, *INFOPTR;
#endif

#ifdef  rabbit
typedef struct rabbit
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
    char coat_color[MAX_LENGTH];
    int age;

}INFO, *INFOPTR;
#endif

#ifdef hippopotamus
typedef struct hippopotamus
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
    int age;
    char living_area[MAX_LENGTH];
}INFO, *INFOPTR;
#endif

typedef struct LNode
{
    INFO data;       //数据域
    struct LNode *next;   //指针域
}LNode,*LinkList;

typedef enum Menu
{
	Exit,Create,Add,Delete,Change,Search,Calculate,Print
}MENU;//用有实际意义的标签来替换数字0-7

void write_kinderfisher(INFO &e);
void read_kinderfisher(INFO e);

void InitList_L(LinkList *L);//初始化
void CreateList_L (LinkList L, int n);//创建链表-->尾插
void AddInfo(LinkList L, int i);//插入数据
void DelInfo(LinkList L, char name[MAX_LENGTH]);//指定数据
void DelLocate(LinkList L, int i);//指定位置
void changeLocate_kinderfisher(LinkList L, int i);//指定位置
void changeInfo_kinderfisher(LinkList L, char name[MAX_LENGTH]);//指定数据
void GetInfo(LinkList L, int i);//返回数据
int LocateELem_L2 (LinkList L,char name[MAX_LENGTH] );//返回数据的位置
int calculate(LinkList L);//统计个数
void Print_L( LinkList L);//输出列表
void MainMenu(LinkList L);
void Head();
int MenuSelect();
void Quit(LinkList L);
bool IsNull(LinkList L);
