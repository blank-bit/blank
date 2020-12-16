#include <iostream>
#include <cstring>

#include <stdbool.h>
#include <stdlib.h>

using namespace std;
#define MAX_LENGTH 50

int vCount = 0;

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

#define MAX_VERTEX_NUM 50
typedef int VertexID;
static VertexID visit_seq[MAX_VERTEX_NUM];
static VertexID seq;
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
typedef struct hippopotamus_gragh
{
    int arcnum, vertexnum; //图的顶点数和弧数
    VNode vertex[MAX_VERTEX_NUM];
} gragh;

typedef struct queue
{
    int front, rear;
    VertexID QueueElem[MAX_VERTEX_NUM];
} RQUEUE;

void init_gragh(gragh *G);                         //初始化图
int locate_vertex(gragh *G, VertexID v);           //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(gragh *G, VertexID v);          //插入节点
bool insert_arc(gragh *G, VertexID v, VertexID w); //插入边
bool create_gragh(gragh *G);                       //用于创建图
INFO new_info_hp();                                //用于每个hippopotamus的数据输入
void visit_hp(INFOPTR info);                       //被DFS_VertexID调用后输出遍历过的顶点号
void visit(gragh *G, int target);                  //访问节点数据

void DFS_VertexID(gragh *G, int src, VertexID *visited); //以结点编号为关键字的深度优先遍历
void DFS(gragh *G, int src, VertexID *visited);
void BFS_VertexID(gragh *G, int src, VertexID *visited, RQUEUE *Q); //以结点编号为关键字的广度优先遍历
void BFS(gragh *G, int src, VertexID *visited, RQUEUE *Q);

void InitQueue(RQUEUE *Q);                     //初始化队列
bool EnterQueue(RQUEUE *Q, VertexID target);   //数据进队
bool DeleteQueue(RQUEUE *Q, VertexID *target); //数据出队
bool IsEmpty(RQUEUE *Q);                       //判断队是否空
bool IsFull(RQUEUE *Q);                        //判断队是否满

void init_gragh(gragh *G) //初始化图
{
    G->arcnum = G->vertexnum = 0;
}

INFO new_info_hp() //完成结点信息的输入
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

    cout << "输入年龄:" << endl;
    cin >> info.age;

    cout << "输入生活地区:" << endl;
    i = 0;
    cin >> info.living_area;

    return info;
}

void visit_hp(INFOPTR info) //输出结点信息
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
    cout << "年龄:" << info->age << endl;
    cout << "生活地区:" << info->living_area << endl;
}

void visit(gragh *G, int target)
{
    int i;
    for (i = 0; i < G->vertexnum; i++)
        if (G->vertex[i].firstvertex == target)
        {
            cout << endl;
            cout << "第" << target + 1 << "个结点的信息为：" << endl;
            visit_hp(&G->vertex[i].info);
        }
}

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

bool insert_vertex(gragh *G, VertexID v) //数组信息输入
{
    G->vertex[v].firstvertex = v;
    G->vertex[v].firstarc = NULL;
    G->vertex[v].info = new_info_hp();
    return true;
} //仅在创建图时调用！

bool insert_arc(gragh *G, VertexID des1, VertexID des2) //边插入
{
    if (G == NULL || locate_vertex(G, des1) == -1 || locate_vertex(G, des2) == -1)
    {
        cout << "图中没有该顶点" << endl;
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

bool create_gragh(gragh *G) //创建图
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
    cout << endl;
    int i;
    cout << "输入每个顶点的相关信息:" << endl;
    for (i = 0; i < G->vertexnum; i++)
    {
        cout << "第" << i + 1 << "个顶点" << endl;
        insert_vertex(G, i);
        cout << endl;
    } //插入结点

    cout << "请输入每条边的两个顶点" << endl;
    for (i = 0; i < G->arcnum; i++)
    {
        cout << "\n第 " << i + 1 << " 条边的第一个顶点:";
        cin >> des1;
        cout << "第 " << i + 1 << " 条边的第二个顶点:";
        cin >> des2;
        insert_arc(G, des1 - 1, des2 - 1);
    } //插入边
    return true;
}

void DFS_VertexID(gragh *G, int src, VertexID *visited)
{
    visit(G, src);
    visited[src] = 1;
    visit_seq[seq++] = src;
    ANode *next = G->vertex[src].firstarc;
    while (next)
    {
        if (!visited[next->adjvex])
            DFS_VertexID(G, next->adjvex, visited);
        next = next->nextarc;
    }
} //递归实现深度优先遍历并输出信息

void DFS(gragh *G, int src, VertexID *visited)
{
    int i;
    seq = 0;
    for (i = 0; i < G->vertexnum; i++)
        visited[i] = 0;
    DFS_VertexID(G, src, visited);
    cout << endl;
    cout << "深度遍历结果为：" << endl;
    for (i = 0; i < seq; i++)
    {
        if (i != seq - 1)
            cout << visit_seq[i] + 1 << "-->";
        else
            cout << visit_seq[i] + 1 << endl;
    }
}

void BFS_VertexID(gragh *G, int src, VertexID *visited, RQUEUE *Q)
{
    VertexID visiting;
    visit(G, src);
    visited[src] = 1;
    visit_seq[seq++] = src;
    InitQueue(Q);
    EnterQueue(Q, src);
    ANode *W = NULL;
    while (!IsEmpty(Q))
    {
        DeleteQueue(Q, &visiting);
        W = G->vertex[visiting].firstarc;
        while (W)
        {
            if (!visited[W->adjvex])
            {
                visit(G, W->adjvex);
                visit_seq[seq++] = W->adjvex;
                visited[W->adjvex] = 1;
                EnterQueue(Q, W->adjvex);
            }
            W = W->nextarc;
        }
    }

} //递归实现广度优先遍历并输出信息

void BFS(gragh *G, int src, VertexID *visited, RQUEUE *Q) //按广度优先输出遍历顺序并按该顺序输出信息
{
    int i;
    seq = 0;
    for (i = 0; i < G->vertexnum; i++)
        visited[i] = 0;
    BFS_VertexID(G, src, visited, Q);
    cout << endl;
    cout << "广度遍历结果为：" << endl;
    for (i = 0; i < seq; i++)
    {
        if (i != seq - 1)
            cout << visit_seq[i] + 1 << "-->";
        else
            cout << visit_seq[i] + 1 << endl;
    }
}

void InitQueue(RQUEUE *Q) //初始化队列
{
    Q->rear = Q->front = 0;
}

bool EnterQueue(RQUEUE *Q, VertexID target) //数据进队
{
    ANode a;
    if (IsFull(Q))
    {
        cout << "队列已满。";
        return 0;
    }
    Q->QueueElem[Q->rear] = target;
    Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM;
    return 1;
}

bool DeleteQueue(RQUEUE *Q, VertexID *target) //数据出队
{
    if (IsEmpty(Q))
    {
        cout << "队列为空。" << endl;
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
}

int main()
{
    RQUEUE Q;
    gragh *G = new gragh;
    create_gragh(G);
    VertexID visited[G->vertexnum]; //记录第i个结点是否被遍历过-->是否打印过信息；遍历过则该顶点置1，接下
    int i, n;
    for (i = 0; i < G->vertexnum; i++) //否则为0；全部初始化为0
        visited[i] = 0;

    cout << endl;
    cout << "从第几个结点开始深度搜索(1--" << G->vertexnum << "):" << endl;
    cin >> n;
    cout << "深度遍历结果(含数据)为：";
    DFS(G, n - 1, visited);
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "广度遍历结果(含数据)为：";
    BFS(G, n - 1, visited, &Q);
    return 0;
}
