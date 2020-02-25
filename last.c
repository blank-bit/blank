#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_NAME 20
#define MAX_ID   20
#define STUDENT_FILE_NAME "student.txt"

typedef struct  //类型首字母大写以和变量区分
{
	char Name[MAX_NAME];
	char Number[MAX_ID];
	int Math;
	int English;
	int Program;
	int Score;
}Student;	

typedef struct _node
{
	Student data;
	struct _node *next;
} node , *nodeptr;

typedef struct 
{
    nodeptr head;//头节点
    size_t size;
} list, *listptr;

int count = 0;

void Init(listptr l);
void MainMenu(listptr l);
void head();
void MenuSelect(listptr l);
void ReadData(listptr l);
void SaveData(listptr l);
void Quit(listptr l);
void Lessons_Information();
void Show_Information(listptr l);
void Add_Information(listptr l);
void Sort_Information(listptr l);
void Change_Information(listptr l);
void Delete_Information(listptr l);
void Search_Information(listptr l);


void Init(listptr l)
{
	l = (listptr)malloc(sizeof(list));
	l->head = NULL;
	l->size = 0;
}

void head()
{
	printf("\n");
	printf("\t\t\t\t\t╭   ╮                   ╭ ```╮  \n");
	printf("\t\t\t\t\t(@^o^@) 学生信息管理系统 (⌒:⌒)\n");
	printf("\t\t\t\t\t(~):(~)                  (~)v(~) \n");
	printf("\n\n\n");
}

void MainMenu(listptr l)
{
	head();
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
	MenuSelect(l);
}

void Quit(listptr l)
{
	char c;
	c = getchar();
	printf("\n\n\t\t\t\t要返回登录界面按任意键\t\t退出并保存数据请按Esc键\n");
	c = getchar();
	if (c == 0x1b)	//esc键按下
	{
		SaveData(l);
		exit(1);
	}
	//重新进入主菜单
	MainMenu(l);

}

void MenuSelect(listptr l)
{
	char c;
	c = getchar();

	switch (c)
	{
	case '0': exit(1);
	case '1': Lessons_Information(l);
		Quit(l);
		break;
	case '2': Show_Information(l);
		Quit(l);
		break;
	case '3': Add_Information(l);
		Quit(l);
		break;
	case '4': Sort_Information(l);
		Quit(l);
		break;
	case '5': Change_Information(l);
		Quit(l);
		break;
	case '6': Delete_Information(l);
		Quit(l);
		break;
	case '7': Search_Information(l);
		Quit(l);
		break;
	default: MainMenu(l);
	}
}

void Lessons_Information()
{
	head();
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║   MONDAY   ║  TUESDAY   ║ WENDNESDAY ║  THURSDAY  ║   FRIDAY   ║\n");
	printf("\t\t\t╚════════════╝════════════╝════════════╝════════════╝════════════╝\n");
	printf("\t\t\t╔════════════╦════════════╦════════════╦════════════╦════════════╗\n");
	printf("\t\t\t║  高等数学  ║  大学英语  ║  高等数学  ║  大学英语  ║  高等数学  ║\n");
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
}

void ReadData(listptr l)
{
	Student stu;
	FILE *fp;
	nodeptr p , q;
	q = l->head;
	if ((fp = fopen(STUDENT_FILE_NAME, "r")) == NULL) {
    if ((fp = fopen(STUDENT_FILE_NAME, "w")) == NULL) {
        printf("文件%s创建失败。", STUDENT_FILE_NAME);
        exit(1);}
    } else {
        while (!feof(fp)) {
            fscanf(fp, "%s", stu.Name);
            fscanf(fp, "\t%s", stu.Number);
            fscanf(fp, "\t%d", &stu.Math);
            fscanf(fp, "\t%d", &stu.English);
            fscanf(fp, "\t%d", &stu.Program);
			fscanf(fp, "\t%d\n", &stu.Score);
            p = (nodeptr)malloc(sizeof(node));
            p->data = stu;
            q->next = p;
            q = p;
            count++;
        }
    }
    fclose(fp);
}

void Show_Information(listptr l)
{
	head();
	ReadData(l);
	nodeptr p ; 
	p = l->head;
	p = p->next;	//指向第一个节点 如果链表为 NULL p为 NULL
	int index = 1;
	printf("\t\t\t**********************本名单共有 %d 名学生*********************\n\n\n", count);
	printf("\t\t\t序号\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
	while (p != NULL)	//遍历输出所有学生
	{
		printf("\t\t\t %d.\t %s\t %s\t %d\t %d\t %d\t\t%d\n", index, p->data.Number, p->data.Name, p->data.Math,
		p->data.English, p->data.Program, p->data.Score);
		p = p->next;	//指向下一个节点
		index++;	//下标加加
	}
	printf("\n\n\n");	
}

void Add_Information(listptr l)
{
	head();
	nodeptr pNew , q;
	// q = l->head;
	/************添加学生信息***********/
	pNew = (nodeptr)malloc(sizeof(node));
	if(!l)//链表为空
		l->head = pNew;
	else
	{
		q = l->head;
		while(q->next)
	 		q = q->next;

	 	q->next = pNew;
	}
	printf("\t\t\t\t\t\t添加学生信息:\n\n\n\n\t\t\t\t\t\t学号:");
	scanf("%s", pNew->data.Number);
	printf("\n\t\t\t\t\t\t姓名:");
	scanf("%s", pNew->data.Name);
	printf("\n\t\t\t\t\t\t高等数学:");
	scanf("%d", &pNew->data.Math);
	printf("\n\t\t\t\t\t\t大学英语:");
	scanf("%d", &pNew->data.English);
	printf("\n\t\t\t\t\t\t程序设计:");
	scanf("%d", &pNew->data.Program);
	pNew->data.Score = pNew->data.English + pNew->data.Math + pNew->data.Program;
	SaveData(l);
}

void SaveData(listptr l)
{
	FILE *fp;
	if ((fp = fopen(STUDENT_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(STUDENT_FILE_NAME, "w")) == NULL) 
	{
		printf("文件%s创建失败。",STUDENT_FILE_NAME);
		exit(1);
	}
	}
	nodeptr p;
	p = l->head;
	while(p != NULL)
	{
		fprintf(fp, "%s", p->data.Name);
        fprintf(fp, "\t%s", p->data.Number);
        fprintf(fp, "\t%d", p->data.Math);
        fprintf(fp, "\t%d", p->data.English);
        fprintf(fp, "\t%d", p->data.Program);
        fprintf(fp, "\t%d\n", p->data.Score);
		p = p->next;
	}
	fclose(fp);	
}

void Sort_Information(listptr l)
{
	nodeptr p , q;
	p = l->head;
	if(!l)
		printf("\n\n\n\n\n\t\t\t\t没有数据！！");
	else {
		for(; p->next != NULL;p = p->next)
			for(q = p->next ; q->next != NULL ; q = q->next)
			{
				Student st;
				if(p->data.Score < q->data.Score)
				{
					st = p->data;
					p->data = q->data;
					q->data = st;
				}
			}
	}
	Show_Information(l);
}

void Change_Information(listptr l)
{
	head();
	char ID[MAX_ID];
	char operate;
	printf("\t\t\t\t\t\t修改学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	nodeptr p = l->head;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (p != NULL)	//遍历所有学生
	{
		if (strcmp(p->data.Number, ID) == 0)
		{
			printf("\n\n\n\t\t\t\t\t要修改的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n", p->data.Number,p->data.Name, p->data.Math, p->data.English,
			p->data.Program,p->data.Score);
			printf("\n\n\n\t\t\t\t\t是否修改该学生信息(y/n):");
			operate = getchar();
			if (operate == 'y' || operate == 'Y')
			{
				//这里又可以做一个菜单单独修改某一个变量，为了方便，直接修改全部变量
				printf("\n\n\t\t\t\t\t重新输入学生信息:\n\n\t\t\t\t\t\t学号:");
				scanf("%s", p->data.Number);
				printf("\n\t\t\t\t\t\t姓名:");
				scanf("%s", p->data.Name);
				printf("\n\t\t\t\t\t\t高等数学:");
				scanf("%d", &p->data.Math);
				printf("\n\t\t\t\t\t\t大学英语:");
				scanf("%d", &p->data.English);
				printf("\n\t\t\t\t\t\t程序设计:");
				scanf("%d", &p->data.Program);
				p->data.Score = p->data.English + p->data.Math + p->data.Program;
				printf("\n\n\n\t\t\t\t\t修改成功...\n\n");
				return;
			}
			else {
				printf("\n\n\n\t\t\t\t\t修改失败...\n\n");
				return;
			}
			return;
		}
		p = p->next;	//指向下一个节点
	}
	printf("\n\n\n\n\t\t\t\t\t   没有找到要查询的学生信息......\n\n");
}

void Delete_Information(listptr l)
{
	head();
	char ID[MAX_ID];
	char operate;
	printf("\t\t\t\t\t\t删除学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	nodeptr p = l->head;	//指向头结点 
	while (p->next != NULL)	//遍历输出所有学生
	{
		nodeptr q = p->next;
		if (strcmp(q->data.Number, ID) == 0)
		{
			//信息库里面有要删除的学生信息
			printf("\n\n\n\t\t\t\t\t要删除的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n",q->data.Number,q->data.Name, q->data.Math, q->data.English,
			q->data.Program,q->data.Score);
			printf("\n\n\n\t\t\t\t\t是否删除该学生信息(y/n):");
			operate = getchar();
			if (operate == 'y' || operate == 'Y')
			{
				//删除学生信息
				p->next = q->next;	
				free(q);
				count--;
				printf("\n\n\n\t\t\t\t\t删除成功...\n\n");
				return;
			}
			else{
				printf("\n\n\n\t\t\t\t\t删除失败...\n\n");
				return;
			}
		}
		p = p->next;	//指向下一个节点
	}
	printf("\n\n\n\n\t\t\t\t\t   没有找到要删除的学生信息......\n\n");
}

void Search_Information(listptr l)
{
	head();
	char ID[MAX_ID];
	char operate;
	printf("\t\t\t\t\t\t查询学生信息：\n\n\n");
	printf("\t\t\t\t\t\t请输入学生学号：");
	scanf("%s", ID);
	//遍历学生信息
	nodeptr p = l->head;	//指向第一个节点 如果链表为 NULL pCurrent为 NULL
	while (p != NULL)	//遍历所有学生
	{
		if (strcmp(p->data.Number, ID) == 0)
		{
			printf("\n\n\n\t\t\t\t\t要查询的学生信息...\n\n");
			printf("\n\n\t\t\t\t\t学号\t姓名\t高数\t英语\t程序设计\t总分\n\n");
			printf("\t\t\t\t\t %s\t %s\t %d\t %d\t %d\t\t%d\n", p->data.Number,p->data.Name, p->data.Math, p->data.English,
			p->data.Program,p->data.Score);
			return;}
		else {
			printf("\n\n\n\t\t\t\t\t修改失败...\n\n");
			return;
		}
		p = p->next;	//指向下一个节点
	}
	printf("\n\n\n\n\t\t\t\t\t   没有找到要查询的学生信息......\n\n");	
}

int main()
{
	list l;
	Init(&l);
	MainMenu(&l);
	return 0;
}