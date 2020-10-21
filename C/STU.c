/******************************************************************************
* 文 件 名   : STU.c
* 版 本 号   : 终稿
* 作    者   : 心向共产党
* 生成日期   : 2019年12月28日
* 功能描述   : 学生信息管理系统
* 函数列表   :
*
*       1.                Add_Information		添加学生信息	
*       2.                Change_Information	修改学生信息
*       3.                Delete_Information	删除学生信息
*       4.                Head					学生信息管理系统字符图标
*       5.                Init					学生信息管理系统初始化字符图标
*       6.                Lessons_Information	课程信息
*       7.                main					主函数
*       8.                MainMenu				主菜单界面
*       9.                MenuSelect			菜单选择
*       10.               Quit					退出程序或重新进入主菜单
*       11.               Search_Information	查询学生信息
*       12.               Show_Information		显示所有学生信息
*       13.               Sort_Information		对学生信息进行排序	
*       14.               Swap					交换两个学生信息
*       15.               ReadData				读取"student.dat"文件
*       16.               SaveData				将链表中的数据存储在"student.dat"文件
*
******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_ID   20
#define STUDENT_FILE_NAME "student.dat"

typedef enum Menu
{
	Exit,Lessons,Show,Add,Sort,Change,Delete,Search
}MENU;//用有实际意义的标签来替换数字0-7

typedef struct Student //类型首字母大写以和变量区分
{
	char cName[MAX_NAME];
	char cNumber[MAX_ID];
	int iMath;
	int iEnglish;
	int iProgram;
	int iScore;
	struct Student  *pNext;
}STU,*PSTU;	

PSTU pHead = NULL;	//信息学生头结点
PSTU pNew = NULL;	//待添加学生信息
size_t iCount = 0;	//学生总数

void Init();
void MainMenu();
void Head();

int MenuSelect();
void ReadData();
void SaveData();
void Quit();
void Lessons_Information();
void Show_Information();
void Add_Information();
void Sort_Information();
void Change_Information();
void Delete_Information();
void Search_Information();
void Swap(PSTU stu1,PSTU stu2);

/*****************************************************************************
 函 数 名  : MainMenu
 功能描述  : 主菜单界面
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void

*****************************************************************************/
void MainMenu()
{
		switch (MenuSelect())	//菜单选择
		{
		case Exit:		//退出程序
			printf("\n\t\t\t\t\t\t  欢迎下次使用！\n\n");
			SaveData();
			exit(0);	//退出或返回主菜单
			break;
		case Lessons:	//课程信息
			Lessons_Information();
			Quit();
			break;
		case Show:		//显示所有学生信息
			Show_Information();
			Quit();
			break;
		case Add:		//添加学生信息
			Add_Information();
			Quit();
			break;
		case Sort:		//对学生信息总分进行排序
			Sort_Information();
			Show_Information();
			Quit();
			break;
		case Change:	//修改学生信息
			Change_Information();
			Quit();
			break;
		case Delete:	//删除学生信息
			Delete_Information();
			Quit();
			break;
		case Search:	//查询学生信息
			Search_Information();
			Quit();
			break;
	}
}

/*****************************************************************************
 函 数 名  : Init
 功能描述  : 学生信息管理系统初始化字符图标
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void

*****************************************************************************/
void Init()
{
	/****************初始化数据****************/
	pHead = (PSTU)malloc(sizeof(STU));
	pHead->pNext = NULL;
	ReadData();
}

//学生信息管理系统字符图标
void Head()
{
	printf("\n");
	printf("\t\t\t\t\t╭   ╮                   ╭ ```╮  \n");
	printf("\t\t\t\t\t(@^o^@) 学生信息管理系统 (⌒:⌒)\n");
	printf("\t\t\t\t\t(~):(~)                  (~)v(~) \n");
	printf("\n\n\n");
}

/*****************************************************************************
 函 数 名  : MenuSelect
 功能描述  : 菜单选择
 输入参数  : 无
 输出参数  : 无
 返 回 值  : int

*****************************************************************************/
int MenuSelect()
{
	char c;
	do
	{
		Head();
		printf("\t\t\t\t   ╭═════════════════════════════════○●○●═══╮\n");
		printf("\t\t\t\t   │              学生信息管理系统              │\n");
		printf("\t\t\t\t   ╰═══○●○●═════════════════════════════════╯\n");
		printf("\t\t\t\t   ┌───────────────────────────────────────────-┐\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 1. 课程安排                    2. 显示数据 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 3. 添加数据                    4. 数据排名 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 5. 修改数据                    6. 删除数据 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   │ 7. 查询数据                    0. 退出程序 │\n");
		printf("\t\t\t\t   │                                            │\n");
		printf("\t\t\t\t   └────────────────────────────────────────────┘\n");
		printf("\t\t\t\t\t\t  请您选择(0-7):");
		c = getchar();
	} while (c < '0' || c > '7' );
	return c - '0';//ASCII码的0-7不是数字0-7，char转换成int
}

/*****************************************************************************
函 数 名  : ReadData
功能描述  : 读取文件信息
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

*****************************************************************************/
void ReadData()
{
	FILE* fRead = fopen(STUDENT_FILE_NAME, "rt");
	if (fRead == NULL)
	{
		SaveData();	//文件不存在就创建文件
		return;
	}
	rewind(fRead);	//将文件内部指针移回文件开头
	while (1)
	{
		pNew = (PSTU)malloc(sizeof(STU));	//申请一块内存
		fread(pNew, sizeof(STU), 1, fRead);	//1 表示读取一个STU字节大小单元
		if (feof(fRead)) break;				//文件末尾退出
		//头插法插入数据，可用尾插法
		pNew->pNext = pHead->pNext;			
		pHead->pNext = pNew;
		pNew = NULL;
		iCount++;
	}
	Sort_Information();
	fclose(fRead);
}

/*****************************************************************************
函 数 名  : SaveData
功能描述  : 写入文件信息
输入参数  : 无
输出参数  : 无
返 回 值  : void
调用函数  :
被调函数  :

*****************************************************************************/
void SaveData()
{
	FILE* fWrite = fopen(STUDENT_FILE_NAME, "wt");
	if (fWrite == NULL)//文件创建失败
	{
		
		printf("保存失败...\n");
		exit(0);
	}
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (pCurrent != NULL)		//遍历所有学生信息	
	{
		fwrite(pCurrent, sizeof(STU), 1, fWrite);
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	pCurrent = NULL;
	fclose(fWrite);
}

/*****************************************************************************
 函 数 名  : Lessons_Information
 功能描述  : 课程信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void

*****************************************************************************/
void Lessons_Information()
{
	Head();
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║   MONDAY   ║  TUESDAY   ║ WENDNESDAY ║  THURSDAY  ║   FRIDAY   ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║  线性代数  ║  通用英语  ║  微积分上  ║  通用英语  ║  线性代数  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║  离散数学  ║  大学物理  ║  离散数学  ║  大学物理  ║  离散数学  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║            ║            ║            ║            ║            ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║  程序设计  ║  离散数学  ║  程序设计  ║            ║  程序设计  ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║            ║            ║            ║            ║            ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
}//暂不支持更改课程表

/*****************************************************************************
 函 数 名  : Quit
 功能描述  : 退出程序或重新进入主菜单
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void

*****************************************************************************/
void Quit()
{
	char ch;
	printf("\n\t ");

	printf("\n\n\t\t\t\t要返回登录界面按任意键\t\t退出并保存数据请按Q键\n");
	while(getchar() == '\n') 
		;
	ch = getchar();
	if (ch == 'q' || ch == 'Q')	//Q键按下
	{
		SaveData();
		exit(0);
	}
	else MainMenu();//重新进入主菜单
}

/*****************************************************************************
 函 数 名  : Show_Information
 功能描述  : 显示所有学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 
*****************************************************************************/
void Show_Information()
{
	Head();
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	int index = 1;
	printf("\t\t\t**********************本名单共有 %ld 名学生*********************\n\n\n", iCount);
	printf("\t\t\t序号\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
	while (pCurrent != NULL)	//遍历输出所有学生
	{
		printf("\t\t\t %d\t %s\t %s\t %d\t %d\t %d\t\t%d\n", index, pCurrent->cNumber, pCurrent->cName, pCurrent->iMath
			, pCurrent->iEnglish, pCurrent->iProgram, pCurrent->iScore);
		pCurrent = pCurrent->pNext;	//指向下一个节点
		index++;	//下标加加
	}
	pCurrent = NULL;
	printf("\n\n\n");
}

/*****************************************************************************
 函 数 名  : Add_Information
 功能描述  : 添加学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 
*****************************************************************************/
void Add_Information()
{
	Head();
	/************添加学生信息***********/
	pNew = (PSTU)malloc(sizeof(STU));
	printf("\t\t\t\t\t\t添加学生信息:\n\n\n\n\t\t\t\t\t\t学号:");
	scanf("%s", pNew->cNumber);
	printf("\n\t\t\t\t\t\t姓名:");
	scanf("%s", pNew->cName);
	printf("\n\t\t\t\t\t\t高等数学:");
	scanf("%d", &pNew->iMath);
	printf("\n\t\t\t\t\t\t大学英语:");
	scanf("%d", &pNew->iEnglish);
	printf("\n\t\t\t\t\t\t程序设计:");
	scanf("%d", &pNew->iProgram);
	pNew->iScore = pNew->iEnglish + pNew->iMath + pNew->iProgram;
	pNew->pNext = pHead->pNext;
	pHead->pNext = pNew;
	pNew = NULL;
	iCount++;
}

/*****************************************************************************
 函 数 名  : Sort_Information
 功能描述  : 对学生信息进行排序
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 
*****************************************************************************/
void Sort_Information()
{
	if (iCount < 2)		//一个学生不需要排序
	{
		return;	
	}
	//从大到小排序 冒泡排序
	PSTU pCurrent,pTemp;
	STU Temp;
	for (pCurrent = pHead->pNext; pCurrent != NULL; pCurrent = pCurrent->pNext)
	{
		for (pTemp = pCurrent->pNext; pTemp != NULL; pTemp = pTemp->pNext)
		{
			if (pCurrent->iScore < pTemp->iScore)
			{
				Swap(&Temp, pCurrent);
				Swap(pCurrent, pTemp);
				Swap(pTemp, &Temp);
			}
		}
	}
}

/*****************************************************************************
 函 数 名  : Change_Information
 功能描述  : 修改学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void
 
*****************************************************************************/
void Change_Information()
{
	Head();
	char ID[MAX_ID];
	char operate;
	printf("\t\t\t\t\t\t修改学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (pCurrent != NULL)	//遍历所有学生
	{
		if (strcmp(pCurrent->cNumber, ID) == 0)
		{
			printf("\n\n\n\t\t\t\t\t要修改的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n", pCurrent->cNumber,
				pCurrent->cName, pCurrent->iMath
				, pCurrent->iEnglish, pCurrent->iProgram,pCurrent->iScore);
			printf("\n\n\n\t\t\t\t\t是否修改该学生信息(y/n):");
			if((operate = getchar()) == '\n')
				operate = getchar();
			if (operate == 'y' || operate == 'Y')
			{
				//这里又可以做一个菜单单独修改某一个变量，为了方便，直接修改全部变量
				printf("\n\n\t\t\t\t\t重新输入学生信息:\n\n\t\t\t\t\t\t学号:");
				scanf("%s", pCurrent->cNumber);
				printf("\n\t\t\t\t\t\t姓名:");
				scanf("%s", pCurrent->cName);
				printf("\n\t\t\t\t\t\t高等数学:");
				scanf("%d", &pCurrent->iMath);
				printf("\n\t\t\t\t\t\t大学英语:");
				scanf("%d", &pCurrent->iEnglish);
				printf("\n\t\t\t\t\t\t程序设计:");
				scanf("%d", &pCurrent->iProgram);
				pCurrent->iScore = pCurrent->iEnglish + pCurrent->iMath + pCurrent->iProgram;
				printf("\n\n\n\t\t\t\t\t修改成功...\n\n");
				pCurrent = NULL;
				return;
			}
			else {
				printf("\n\n\n\t\t\t\t\t修改失败...\n\n");
				return;
			}
			return;
		}
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	pCurrent = NULL;
	printf("\n\n\n\n\t\t\t\t\t   没有找到要查询的学生信息......\n\n");
}

/*****************************************************************************
 函 数 名  : Delete_Information
 功能描述  : 删除学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void

*****************************************************************************/
void Delete_Information()
{
	Head();
	char ID[MAX_ID];
	char operate;
	printf("\t\t\t\t\t\t删除学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	PSTU pCurrent = pHead;	//指向头结点 
	
	while (pCurrent->pNext != NULL)	//遍历输出所有学生
	{
		if (strcmp(pCurrent->pNext->cNumber, ID) == 0)
		{
			//信息库里面有要删除的学生信息
			printf("\n\n\n\t\t\t\t\t要删除的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n",pCurrent->pNext->cNumber, 
				pCurrent->pNext->cName, pCurrent->pNext->iMath, pCurrent->pNext->iEnglish
				, pCurrent->pNext->iProgram,pCurrent->pNext->iScore);
			printf("\n\n\n\t\t\t\t\t是否删除该学生信息(y/n):");
			if((operate = getchar()) == '\n')
				operate = getchar();
			if (operate == 'y' || operate == 'Y')
			{
				//删除学生信息
				PSTU pTemp = pCurrent->pNext;	//定义PSTU指针 pTemp 指向要删除的节点
				pCurrent->pNext = pTemp->pNext;	
				free(pTemp);
				iCount--;
				printf("\n\n\n\t\t\t\t\t删除成功...\n\n");
				return;
			}
			else{
				printf("\n\n\n\t\t\t\t\t删除失败...\n\n");
				return;
			}
		}
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	printf("\n\n\n\n\t\t\t\t\t   没有找到要删除的学生信息......\n\n");
}

/*****************************************************************************
 函 数 名  : Search_Information
 功能描述  : 查询学生信息
 输入参数  : 无
 输出参数  : 无
 返 回 值  : void

*****************************************************************************/
void Search_Information()
{
	Head();
	char ID[MAX_ID];
	printf("\t\t\t\t\t\t查询学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	PSTU pCurrent = pHead->pNext;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (pCurrent != NULL)		//遍历所有学生
	{
		if (strcmp(pCurrent->cNumber, ID) == 0)
		{
			printf("\n\n\n\t\t\t\t\t要查询的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n", pCurrent->cNumber,
				pCurrent->cName, pCurrent->iMath
				, pCurrent->iEnglish, pCurrent->iProgram,pCurrent->iScore);
			return;
		}
		pCurrent = pCurrent->pNext;	//指向下一个节点
	}
	pCurrent = NULL;
	printf("\n\n\n\n\t\t\t\t\t   没有找到要查询的学生信息......\n\n");
}

/*****************************************************************************
 函 数 名  : Swap
 功能描述  : 交换两个学生信息
 输入参数  : PSTU stu1  
             PSTU stu2  
 输出参数  : 无
 返 回 值  : void
 调用函数  : 
 被调函数  :

*****************************************************************************/
void Swap(PSTU stu1, PSTU stu2)
{
	strcpy(stu1->cName, stu2->cName);
	strcpy(stu1->cNumber, stu2->cNumber);
	stu1->iEnglish = stu2->iEnglish;
	stu1->iMath = stu2->iMath;
	stu1->iProgram = stu2->iProgram;
	stu1->iScore = stu2->iScore;
}

/*****************************************************************************
 函 数 名  : main
 功能描述  : 主函数(测试代码)
 输入参数  : 无  
 输出参数  : 无
 返 回 值  : int
 调用函数  : 
 被调函数  :

*****************************************************************************/
int main()
{
	Init();
	MainMenu();
	return 0;
}
