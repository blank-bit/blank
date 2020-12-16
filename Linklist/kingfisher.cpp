#include <iostream>
#include <cstring>

using namespace std;

#define MAX_LENGTH 50

bool flag = true;

//定义kingfisher结构体
typedef struct kingfisher
{
  char id[MAX_LENGTH];
  int weight;
  int length;
  char name[MAX_LENGTH];
  bool Is_carnivorous;
  bool Is_Marine;
  char coat_color[MAX_LENGTH];
  int age;
} INFO;

//定义结点
typedef struct LNode
{
  INFO data;          //数据域
  struct LNode *next; //指针域
} LNode, *LinkList;

//函数声明
void write_kingfisher(LinkList L, INFO &e);                    //创建kingfisher结构体并赋值
void read_kingfisher(INFO e);                                  //输出kingfisher结构体的内容
void InitList(LinkList *L);                                    //初始化链表
void Createlist_kingfisher(LinkList L, int n);                 //尾插法创建链表
void AddInfo_kingfisher(LinkList L, int i);                    //增加kingfisher结点
void DelInfo_kingfisher(LinkList L, char name[MAX_LENGTH]);    //删除指定ID的kingfisher结点
void DelLocate_kingfisher(LinkList L, int i);                  //删除指定位置的kingfisher结点
void changeLocate_kingfisher(LinkList L, int i);               //修改指定位置的kingfisher结点
void changeInfo_kingfisher(LinkList L, char name[MAX_LENGTH]); //修改指定ID的kingfisher结点
void GetInfo_kingfisher(LinkList L, int i);                    //输入结点位置，输出kingfisher结点信息
int GetLocate_kingfisher(LinkList L, char name[MAX_LENGTH]);   //输入指定ID，输出kingfisher结点的位置
int calculate_kingfisher(LinkList L);                          //统计kingfisher结点个数
void Print_kingfisher(LinkList L);                             //输出kingfisher列表
void MainMenu(LinkList L);                                     //主菜单
void Head();                                                   //主界面的头图案，美观
int MenuSelect();                                              //菜单选择界面
void Quit(LinkList L);                                         //退出程序
bool IsNull(LinkList L);                                       //判断是否还未创建链表
bool IsExit(LinkList L, char id[MAX_LENGTH]);                  //判断该ID的对象是否已经创建过

//创建kingfisher结构体并赋值
void write_kingfisher(LinkList L, INFO &e)
{
  cout << "输入id: ";
  cin >> e.id;

  if (IsExit(L, e.id) && flag) //如果该ID的对象已经添加过，需要重新输入ID，确保ID不会重复
  {
    cout << "该ID已存在，请重新输入！！！" << endl;
    write_kingfisher(L, e); //重新调用 write_kingfisher函数，输入要创建的kingfisher对象的值
    return;
  }

  cout << "输入体重: ";
  cin >> e.weight;
  cout << "输入长度: ";
  cin >> e.length;
  cout << "输入姓名: ";
  cin >> e.name;
  cout << "输入是否肉食(1/0): ";

  char x; //防止输入其他数据导致程序错误,输入非0值则视为真
  cin >> x;
  if (x != '0')
    e.Is_carnivorous = 1;
  else
    e.Is_carnivorous = 0;
  cout << "输入是否水生(1/0): ";

  cin >> x;
  if (x != '0')
    e.Is_Marine = 1;
  else
    e.Is_Marine = 0;

  cout << "输入颜色: ";
  cin >> e.coat_color;
  cout << "输入年龄: ";
  cin >> e.age;
  cout << endl;
}

//输出kingfisher结构体的内容
void read_kingfisher(INFO e)
{
  cout << "id:" << e.id << endl;
  cout << "体重:" << e.weight << endl;
  cout << "长度:" << e.length << endl;
  cout << "姓名:" << e.name << endl;
  cout << "是否肉食:" << (e.Is_carnivorous ? "是" : "否") << endl;
  //“ ？”前面的 e.Is_carnivorous是判断条件，如果e.Is_carnivorous为真-->e.Is_carnivorous==1,则输出“是”；如果e.Is_carnivorous==0，则输出“否”
  cout << "是否水生:" << (e.Is_Marine ? "是" : "否") << endl;
  cout << "颜色:" << e.coat_color << endl;
  cout << "年龄:" << e.age << endl;
}

//初始化链表
void InitList(LinkList *L)
{
  (*L) = new LNode; //创建头结点
  (*L)->next = NULL;
}

//尾插法创建链表，n为个数
void Createlist_kingfisher(LinkList L, int n)
{
  if (n < 1) //判断输入的n是否小于0
    cout << "创建的实例不能少于1个！！！" << endl;

  int i = 0;
  LinkList q;
  for (i = 0; i < n; i++) //循环添加kingfisher结点
  {
    LinkList p = new LNode;
    write_kingfisher(L, p->data); //写入kingfisher结点的值
    p->next = NULL;
    q = L;

    while (q->next) //循环到达链表的尾部
      q = q->next;

    q->next = p; //在尾部插入新结点
  }
  cout << "\t\t创建成功！！！" << endl;
}

//统计kingfisher结点个数
int calculate_kingfisher(LinkList L)
{
  int iCount = 0; //设置计数器
  LinkList q = L;

  while (q->next) //循环一次加1，直到到达链表尾部
  {
    iCount++;
    q = q->next;
  }
  return iCount;
}

//增加kingfisher结点，i为要添加的位置
void AddInfo_kingfisher(LinkList L, int i)
{
  if (i < 0) //位置不合理
  {
    cout << "插入位置必须大于0。" << endl;
    return;
  }

  LinkList q = L;
  LinkList p;
  int j = 0;
  while (q && j < i - 1) //循环到达第i-1个结点的位置或者链表长度小于i
  {
    q = q->next;
    j++;
  }

  if (!q) //链表到达尾部,还未找到第i-1个结点-->链表长度小于i
  {
    cout << "链表长度为" << calculate_kingfisher(L) << "，插入的位置不合理。" << endl;
    return;
  }

  p = new LNode;                //创建新结点
  write_kingfisher(L, p->data); //给新结点赋值
  p->next = q->next;            //插入到第i位
  q->next = p;

  cout << "\t\t插入成功！！！" << endl;
}

//删除指定ID的kingfisher结点
void DelInfo_kingfisher(LinkList L, char id[MAX_LENGTH])
{
  LinkList p, s, t;
  p = L;
  while ((strcmp(p->next->data.id, id) != 0) && p->next) // strcmp(a,b);如果a == b,返回0；如果不等，返回非0值。
  {                                                      //用p->next->data的原因：如果p的下一个结点的ID和寻找的ID相同，便可以将下一个结点单独取出并删除，保证链表不会断裂
    p = p->next;                                         //用p->data:自身的ID和寻找的ID相同，无法将自身单独取出，链表会断裂
  }

  if (!p->next) //到达链表尾部，还未找到该ID，要找的ID不存在
  {
    cout << "未找到该数据。" << endl;
    return;
  }

  s = p->next; //删除该结点
  p->next = s->next;
  free(s);

  cout << "\t\t删除成功！！！" << endl;
}

//删除指定位置的kingfisher结点
void DelLocate_kingfisher(LinkList L, int i)
{
  if (i < 0)
  {
    cout << "删除位置必须大于0。" << endl;
    return;
  }
  LinkList q = L;
  LinkList p;
  int j = 0;

  while (q && j < i - 1) //循环到达第i-1个结点的位置或者链表长度小于i
  {
    q = q->next;
    j++;
  }

  if (!q) //链表到达尾部,还未找到第i-1个结点-->链表长度小于i
  {
    cout << "链表长度为" << calculate_kingfisher(L) << "，删除的位置不合理。" << endl;
    return;
  }

  p = q->next; //删除该结点
  q->next = p->next;
  free(p);

  cout << "\t\t删除成功！！！" << endl;
}

//修改指定位置i的kingfisher结点
void changeLocate_kingfisher(LinkList L, int i)
{
  if (i < 0)
  {
    cout << "修改位置必须大于0。" << endl;
    return;
  }

  LinkList q = L;
  LinkList p;
  int j = 0;
  while (q && j < i - 1) //循环到达第i-1个结点的位置或者链表长度小于i
  {
    q = q->next;
    j++;
  }

  if (!q) //链表到达尾部,还未找到第i-1个结点-->链表长度小于i
  {
    cout << "链表长度为" << calculate_kingfisher(L) << "，删除的位置不合理。" << endl;
    return;
  }

  p = q->next;
  write_kingfisher(L, p->data); //重新给该结点赋值
  q->next = p;

  cout << "\t\t修改成功！！！" << endl;
}

//修改指定ID的kingfisher结点
void changeInfo_kingfisher(LinkList L, char id[MAX_LENGTH])
{
  LinkList p, s;
  p = L;
  while ((strcmp(p->next->data.id, id) != 0) && p->next) //用p->next->data的原因：如果p的下一个结点的ID和寻找的ID相同，便可以将下一个结点单独取出并删除，保证链表不会断裂
  {
    p = p->next;
  }

  if (!p->next) //到达链表尾部，还未找到该ID，要找的ID不存在
  {
    cout << "未找到该数据。" << endl;
    return;
  }

  s = p->next;
  write_kingfisher(L, s->data); //重新给该结点赋值
  p->next = s;

  cout << "\t\t修改成功！！！" << endl;
}

//输入结点位置i，输出kingfisher结点信息
void GetInfo_kingfisher(LinkList L, int i)
{
  if (i < 0)
  {
    cout << "查询位置必须大于0。" << endl;
    return;
  }
  LinkList q = L;
  LinkList p;
  int j = 0;
  while (q && j < i - 1) //同上
  {
    q = q->next;
    j++;
  }

  if (!q) //同上
  {
    cout << "链表长度为" << calculate_kingfisher(L) << "，查询的位置不合理。" << endl;
    return;
  }

  p = q->next;
  read_kingfisher(p->data);
}

//输入指定ID，输出kingfisher结点的位置
int GetLocate_kingfisher(LinkList L, char id[MAX_LENGTH])
{
  LinkList p, s;
  int locate = 1;
  p = L;
  while (p->next && (strcmp(p->next->data.id, id) != 0)) //同上
  {
    locate++;
    p = p->next;
  }

  if (!p->next) //同上
  {
    cout << "未找到该数据。" << endl;
    return -1;
  }

  cout << id << "的位置：" << locate << endl; //输出结点位置
  return locate;
}

//输出kingfisher列表
void Print_kingfisher(LinkList L)
{
  LinkList p = L->next;
  while (p) //循环打印，直到链表为空
  {
    read_kingfisher(p->data);
    cout << endl;
    p = p->next;
  }
}

//主菜单
void MainMenu(LinkList list)
{
  int n, i, s;
  char id[MAX_LENGTH];
  switch (MenuSelect()) //菜单选择
  {
  case 0: //退出程序
    cout << "\n\t\t\t\t\t\t  欢迎下次使用！\n"
         << endl;
    exit(0); //退出或返回主菜单
    break;
  case 1: //创建链表
    cout << "请输入创建的链表包含几个数据：";
    cin >> n;
    Createlist_kingfisher(list, n); //创建链表-->尾插
    Quit(list);
    break;
  case 2:             //添加结点
    if (IsNull(list)) //判断是否为创建链表实例，下同
    {
      cout << "还未创建链表，请先创建！！！" << endl;
      Quit(list);
      break;
    }
    else
    {
      cout << "请输入添加的位置：";
      cin >> i;
      AddInfo_kingfisher(list, i); //插入数据
      Quit(list);
      break;
    }
  case 3: //删除结点
    if (IsNull(list))
    {
      cout << "还未创建链表，请先创建！！！" << endl;
      Quit(list);
      break;
    }
    else
    {
      cout << "请选择删除方式(1:删除指定位置,0:删除指定关键字)";
      cin >> s;
      if (s == 1)
      {
        cout << "请输入删除的位置：";
        cin >> i;
        DelLocate_kingfisher(list, i); //指定位置
      }
      else if (s == 0)
      {
        cout << "请输入删除的ID：";
        cin >> id;
        DelInfo_kingfisher(list, id); //指定数据
      }
      Quit(list);
      break;
    }
  case 4: //修改结点
    if (IsNull(list))
    {
      cout << "还未创建链表，请先创建！！！" << endl;
      Quit(list);
      break;
    }
    else
    {
      flag = false;
      cout << "请选择修改方式(1:修改指定位置,0:修改指定关键字)";
      cin >> s;
      if (s == 1)
      {
        cout << "请输入修改的位置：";
        cin >> i;
        changeLocate_kingfisher(list, i); //指定位置
      }
      else if (s == 0)
      {
        cout << "请输入修改的ID：";
        cin >> id;
        changeInfo_kingfisher(list, id); //指定数据
      }
      flag = true;
      Quit(list);
      break;
    }
  case 5: //查询结点
    if (IsNull(list))
    {
      cout << "还未创建链表，请先创建！！！" << endl;
      Quit(list);
      break;
    }
    else
    {
      cout << "请选择查询方式(1:查询指定位置,0:查询指定关键字)";
      cin >> s;
      if (s == 1)
      {
        cout << "请输入查找的位置：";
        cin >> i;
        GetInfo_kingfisher(list, i); //返回数据
      }
      else if (s == 0)
      {
        cout << "请输入查找的ID：";
        cin >> id;
        GetLocate_kingfisher(list, id);
      }
      Quit(list);
      break;
    }
  case 6: //统计结点个数
    if (IsNull(list))
    {
      cout << "还未创建链表，请先创建！！！" << endl;
      Quit(list);
      break;
    }
    else
    {
      cout << "链表总共包含" << calculate_kingfisher(list) << "个数据。" << endl; //统计个数
      Quit(list);
      break;
    }
  case 7: //输出链表
    if (IsNull(list))
    {
      cout << "还未创建链表，请先创建！！！" << endl;
      Quit(list);
      break;
    }
    else
    {
      cout << "链表包含数据如下：" << endl;
      Print_kingfisher(list);
      Quit(list);
      break;
    }
  }
}

//头界面
void Head()
{
  cout << endl;
  cout << "\t\t\t\t\t╭   ╮                   ╭ ```╮  " << endl;
  cout << "\t\t\t\t\t(@^o^@)   管理信息系统   (⌒:⌒)" << endl;
  cout << "\t\t\t\t\t(~):(~)                  (~)v(~) " << endl;
  cout << "\n\n\n";
}

int MenuSelect()
{
  char c;
  do
  {
    Head();
    cout << "\t\t\t\t   ╭═════════════════════════════════○●○●═══╮" << endl;
    cout << "\t\t\t\t   │               管理信息系统                │" << endl;
    cout << "\t\t\t\t   ╰═══○●○●═════════════════════════════════╯" << endl;
    cout << "\t\t\t\t   ┌───────────────────────────────────────────-┐" << endl;
    cout << "\t\t\t\t   │                                            │" << endl;
    cout << "\t\t\t\t   │ 1. 创建实例                    2. 增加实例 │" << endl;
    cout << "\t\t\t\t   │                                            │" << endl;
    cout << "\t\t\t\t   │ 3. 删除实例                    4. 修改实例 │" << endl;
    cout << "\t\t\t\t   │                                            │" << endl;
    cout << "\t\t\t\t   │ 5. 查询实例                    6. 统计实例 │" << endl;
    cout << "\t\t\t\t   │                                            │" << endl;
    cout << "\t\t\t\t   │ 7. 输出实例                    0. 退出程序 │" << endl;
    cout << "\t\t\t\t   │                                            │" << endl;
    cout << "\t\t\t\t   └────────────────────────────────────────────┘" << endl;
    cout << "\t\t\t\t\t\t  请您选择(0-7):";
    cin >> c;
  } while (c < '0' || c > '7');
  return c - '0'; //ASCII码的0-7不是数字0-7，char转换成int
}

void Quit(LinkList list)
{
  char ch;
  cout << "\n\t ";

  cout << "\n\n\t\t\t\t要返回登录界面按任意键\t\t退出请按Q键" << endl;
  cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
  cin >> ch;
  if (ch == 'q' || ch == 'Q') //Q键按下
  {
    exit(0);
  }
  else
    MainMenu(list); //重新进入主菜单
}

//判断是否未创建链表
bool IsNull(LinkList L)
{
  if (L->next == NULL)
    return true;

  return false;
}

//判断是否已经存在
bool IsExit(LinkList L, char id[MAX_LENGTH])
{
  LinkList p;
  p = L;
  while (p && (strcmp(p->data.id, id) != 0)) //循环链表判断该ID是否存在
  {
    p = p->next;
  }

  if (!p) //遍历结束，该ID不存在
    return false;

  //否则该ID存在
  return true;
}

//主函数
int main()
{
  LinkList list;
  InitList(&list); //初始化
  MainMenu(list);  //进入菜单
  return 0;
}