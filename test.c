void DFS_VertexID(gragh*G, int src, VertexID* visited)
{   
    visit(G, src);visited[src] = 1;
    visit_seq[seq++] = src;
    ANode* next = G->vertex[src].firstarc;
    while(next)
    {
        if (!visited[next->adjvex]) 
            DFS_VertexID(G, next->adjvex, visited);
        next = next->nextarc;
    }
}//递归实现深度优先遍历并输出信息

void DFS(gragh*G, int src, VertexID* visited)
{
    int i;
    seq = 0;
    for (i = 0; i < G->vertexnum; i++)
        visited[i] = 0;
    DFS_VertexID(G, src, visited);
    for (i = 0; i < seq; i++)
    {
        if(i != seq - 1) printf("%d-->",visit_seq[i]);
        else printf("%d\n", visit_seq[i]); 
    }
}

void BFS_VertexID(gragh*G, int src, VertexID* visited, RQUEUE* Q)
{
    VertexID visiting;
    visit(G, src);
    visited[src] = 1;
    visit_seq[seq++] = src;
    InitQueue(Q);
    EnterQueue(Q, src);
    ANode* W = NULL;
    while(!IsEmpty(Q))
    {
        DeleteQueue(Q, &visiting);
        W = G->vertex[visiting].firstarc;
        while(W)
        {
            if(!visited[W->adjvex])
            {
                visit(G, W->adjvex);
                visit_seq[seq++] = W->adjvex;
                visited[W->adjvex] = 1;
                EnterQueue(Q, W->adjvex);
            }
            W = W->nextarc;
        }
    }
    
}//递归实现广度优先遍历并输出信息

void BFS(gragh*G, int src, VertexID* visited, RQUEUE* Q)//按广度优先输出遍历顺序并按该顺序输出信息
{
    int i;
    seq = 0;
    for (i = 0; i < G->vertexnum; i++)
        visited[i] = 0;
    BFS_VertexID(G, src, visited, Q);
    for (i = 0; i < seq; i++)
    {
        if(i != seq - 1) printf("%d-->",visit_seq[i]);
        else printf("%d\n", visit_seq[i]); 
    }
}

void InitQueue(RQUEUE* Q)//初始化队列
{
    Q->rear = Q->front = 0;
}

bool EnterQueue(RQUEUE* Q, VertexID target)//数据进队
{
    ANode a;
    if (IsFull(Q)) {printf("the queue already full"); return 0;}
    Q->QueueElem[Q->rear] = target;
    Q->rear = (Q->rear+1) % MAX_VERTEX_NUM;
    return 1;
}

bool DeleteQueue(RQUEUE* Q, VertexID *target)//数据出队
{
    if (IsEmpty(Q)){printf("the queue is empty.\n"); return 0;}
    *target = Q->QueueElem[Q->front];
    Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
    return 1;
}

bool IsEmpty(RQUEUE* Q)//判断队是否空
{
    if (Q->front == Q->rear) return 1;
    else return 0;
}

bool IsFull(RQUEUE* Q)//判断队是否满
{
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front) return 1;
    else return 0;
}
