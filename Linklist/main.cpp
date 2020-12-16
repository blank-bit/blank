#include <iostream>
#include <cstring>

#include <stdbool.h>
#include <stdlib.h>

using namespace std;
#define MAX_LENGTH 50

#define kinderfisher
#ifdef kinderfisher
typedef struct kingderfisher
{
    char id[MAX_LENGTH];
    int weight;
    int length;
    char name[MAX_LENGTH];
    bool Is_carnivorous;
    bool Is_Marine;
  char coat_color[MAX_LENGTH];
  int age;
} INFO, *INFOPTR;
#endif

#ifdef rabbit
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

} INFO, *INFOPTR;
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
} INFO, *INFOPTR;
#endif

#define MAX_VERTEX_NUM 50
typedef int VertexID;

//定义边结点
typedef struct ArcNode
{
    VertexID adjvex;
    struct ArcNode *nextarc;
} ANode;

//定义端点结点
typedef struct VertexNode
{
    VertexID firstvertex; //端点结点的ID
    INFO info;
    ANode *firstarc;
} VNode;

//定义图
typedef struct XXX_gragh
{
    int arcnum, vertexnum; //图的顶点数和弧数
    VNode vertex[MAX_VERTEX_NUM];
} gragh;

typedef struct queue
{
    int front, rear;
    ANode QueueElem[MAX_VERTEX_NUM];
} RQUEUE;

void init_gragh(gragh *G);                         //初始化图
int locate_vertex(gragh *G, VertexID v);           //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(gragh *G, VertexID v);          //插入节点
bool insert_arc(gragh *G, VertexID v, VertexID w); //插入边
bool create_gragh(gragh *G);                       //用于节点数组
//用于初始化图

#ifdef kinderfisher
INFO new_info_kf(); //用于每个kinderfisher的数据输入
void visit_kf(INFOPTR info);
#endif //kinderfisher
#ifdef rabbit
INFO new_info_rbt(); //用于每个rabbit的信息输入
void visit_rbt(INFOPTR info);
#endif //rabbit
#ifdef hippopotamus
INFO new_info_hpt(); //用于每个hippopotamus的信息输入
void visit_hpt(INFOPTR info);
#endif //hippopotamus

void visit(gragh *G, int target);                                   //访问节点数据
void DFS_VertexID(gragh *G, int src, VertexID *visited);            //以结点编号为关键字的深度优先遍历
void BFS_VertexID(gragh *G, int src, VertexID *visited, RQUEUE *Q); //以结点编号为关键字的广度优先遍历

void InitQueue(RQUEUE *Q); //初始化队列
// bool EnterQueue(RQUEUE* Q, VertexID target);//数据进队
// bool DeleteQueue(RQUEUE* Q, VertexID &target);//数据出队
bool IsEmpty(RQUEUE *Q); //判断队是否空
bool IsFull(RQUEUE *Q);  //判断队是否满

void init_gragh(gragh *G) //初始化图
{
    G->arcnum = G->vertexnum = 0;
}

#ifdef kinderfisher
INFO new_info_kf()//完成结点信息的输入
{
    int i = 0;
    INFO info;
    cout << "输入ID:" << endl;
    cin >> info.id;

    cout << "输入体重:" << endl;
    cin >> info.weight;

    cout << "输入长度:" << endl;
    cin >> info.length;

    cout << "输入姓名:" << endl;
    i = 0;
    cin >> info.name;

    info.Is_carnivorous = 1;
    info.Is_Marine = 0;

    cout << "输入颜色:" << endl;
    cin >> info.coat_color;

    cout << "输入年龄:" << endl;
    i = 0;
    cin >> info.age;

    return info;
}

void visit_kf(INFOPTR info)//输出结点信息
{
    if (info == NULL)
    {
        cout << "结点信息为空" << endl;
        return;
    }
  cout << "id:" << info->id << endl;
  cout << "体重:" << info->weight << endl;
  cout << "长度:" << info->length << endl;
  cout << "姓名:" << info->name << endl;
  cout << "是否肉食:" << (info->Is_carnivorous ? "是" : "否") << endl;
  //“ ？”前面的 info->Is_carnivorous是判断条件，如果info->Is_carnivorous为真-->info->Is_carnivorous==1,则输出“是”；如果info->Is_carnivorous==0，则输出“否”
  cout << "是否水生:" << (info->Is_Marine ? "是" : "否") << endl;
  cout << "颜色:" << info->coat_color << endl;
  cout << "年龄:" << info->age << endl<<endl;
}

void visit(gragh *G, int target)//输出结点信息以及结点对应图编码
{
    int i;
    for (i = 0; i < G->vertexnum; i++)//查找整个图，看是否有顶点的第一条边号为target
        if (G->vertex[i].firstvertex == target)
        {
            cout <<"第"<< target+1 <<"的信息为"<< endl;
            visit_kf(&G->vertex[i].info);
        }
}
#endif //kinderfisher
// #ifdef

// #endif  //
// #ifdef

// #endif  //

int locate_vertex(gragh *G, VertexID v) //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
{
    if (!G->vertexnum)
    {
        cout << "图为空。" << endl;
        return -1;
    }
    int i;
    for (i = 0; i < G->vertexnum; i++)
        if (v == G->vertex[i].firstvertex)
            return i;
    if (i == G->vertexnum)
    {
        cout << "不存在该表头结点" << endl;
        return -1;
    }
}

bool insert_vertex(gragh *G, VertexID v)//数组信息输入
{
    G->vertex[v].firstvertex = v;
    G->vertex[v].firstarc = NULL;
    G->vertex[v].info = new_info_kf();
    return true;
} //仅在创建图时调用！

bool insert_arc(gragh *G, VertexID des1, VertexID des2)//边插入
{
    if (G == NULL || locate_vertex(G, des1) == -1 || locate_vertex(G, des2) == -1)
    {
        cout << "there isn't such vertex in the gragh." << endl;
        return false;
    }
    int a = locate_vertex(G, des1), b = locate_vertex(G, des2);
    ANode *arcdes1 = G->vertex[a].firstarc;
    ANode *arcdes2 = G->vertex[b].firstarc;
    for (; arcdes1 != NULL; arcdes1 = arcdes1->nextarc)
        if (arcdes1->adjvex == des1)
            return false;
    arcdes1 = G->vertex[a].firstarc;
    ANode *ass1 = new ANode;
    ANode *ass2 = new ANode;
    ass1->adjvex = des2, ass1->nextarc = arcdes1;
    G->vertex[a].firstarc = ass1;
    ass2->adjvex = des1, ass2->nextarc = arcdes2;
    G->vertex[b].firstarc = ass2;
}

bool create_gragh(gragh *G)//创建图
{
    if (G->arcnum != 0 && G->vertexnum != 0)
    {
        cout << "图已经创建！！" << endl;
        return false;
    }
    int des1, des2;
    cout << "输入总边数:";
    cin >> G->arcnum;
    cout << "输入总顶点数:";
    cin >> G->vertexnum;
    int i;
    cout << "输入每个顶点的相关信息:" << endl;
    for (i = 0; i < G->vertexnum; i++)
    {
        cout << "第" << i + 1 << "个顶点" << endl;
        insert_vertex(G, i);
        cout << endl;
    } //插入结点

    for (i = 0; i < G->arcnum; i++)
    {
        cout << "请输入每条边的两个端点" << endl;
        cout <<"第"<< i+1 <<"条边"<< endl;
        cout << "第一个端点:" << endl;
        cin >> des1;
        getchar();
        cout << "第二个端点:" << endl;
        cin >> des2;
        insert_arc(G, des1, des2);
    } //插入边
    return true;
}


//从第src个顶点开始遍历
void DFS_VertexID(gragh *G, int src, VertexID *visited)
{
    visit(G, src);
    visited[src] = 1;
    ANode *next = G->vertex[src].firstarc;
    while (next)
    {
        if (!visited[next->adjvex])
            DFS_VertexID(G, next->adjvex, visited);
        next = next->nextarc;
    }
} //递归实现深度优先遍历并输出信息




//BFS部分还未全部完成
/*void BFS_VertexID(gragh *G, int src, VertexID *visited, RQUEUE *Q)
{

} //递归实现广度优先遍历并输出信息

void InitQueue(RQUEUE *Q) //初始化队列
{
    Q->rear = Q->front = 0;
}

bool EnterQueue(RQUEUE *Q, ANode target) //数据进队
{
    ANode a;
    if (IsFull(Q))
    {
        cout << "the queue already full";
        return 0;
    }
    Q->QueueElem[Q->rear] = target;
    Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;
    return 1;
}

bool DeleteQueue(RQUEUE *Q, ANode *target) //数据出队
{
    if (IsEmpty(Q))
    {
        cout << "the queue is empty." << endl;
        return 0;
    }
    *target = Q->QueueElem[Q->front];
    Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
    return 1;
}

bool IsEmpty(RQUEUE *Q) //判断队是否空
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

bool IsFull(RQUEUE *Q) //判断队是否满
{
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front)
        return 1;
    else
        return 0;
}*/

int main()
{
    gragh *G = new gragh;
    create_gragh(G);
    VertexID visited[G->vertexnum];//记录第i个结点是否被遍历过-->是否打印过信息；遍历过则该顶点置1，接下
    int i;
    for (i = 0; i < G->vertexnum; i++)//否则为0；全部初始化为0
        visited[i] = 0;
    DFS_VertexID(G, 2, visited);
    return 0;
}
