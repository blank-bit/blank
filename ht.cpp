#include <iostream>
using namespace std;
#include <string.h>

#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef char  **HuffmanCode;

typedef  struct
{  int weight;
   int parent, lch, rch;
}HTNode, *HuffmanTree;

void printHT(HuffmanTree HT, int n)//打印哈夫曼树的各结点信息
{
    for (int i = 1; i <= n; ++i)
        printf("%2d:(%4d, %4d, %4d, %4d)\n", i, HT[i].weight, HT[i].parent, HT[i].lch, HT[i].rch);
}

void Select(HuffmanTree ht, int n, int *s1, int *s2)//选择根结点权值最小的两棵二叉树 
{
    int i, min;

    min = -1;
    for (i = 1; i <= n; ++i)
        if (ht[i].parent == 0 && (min == -1 || ht[i].weight < ht[min].weight))
            min = i;
    *s1 = min;

    min = -1;
    for (i = 1; i <= n; ++i)
        if (ht[i].parent == 0 && (min == -1 || ht[i].weight < ht[min].weight) && i != *s1)
            min = i;
    *s2 = min;
}

void PrintHC(HuffmanCode *hc, int n)//输出各字符的哈夫曼编码
{
    for (int i = 1; i <= n; ++i)
        printf("The encoded as %s\n",hc[i]);
    printf("\n");
}

void CreateHuffmanTree(HuffmanTree ht, int *w, int n)
{
    int i, s1, s2;
    int m = 2 * n - 1;

    for (i = 1; i <= m; ++i)
    {
        ht[i].weight = i <= n ? w[i] : 0;
        ht[i].parent = ht[i].LChild = ht[i].RChild = 0;
    }

    for (i = n + 1; i <= m; ++i)
    {
        Select(ht, i - 1, &s1, &s2);
        ht[s1].parent = ht[s2].parent = i;
        ht[i].lch = s1;
        ht[i].rch = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }
}

void CreateHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)
{
    HuffmanCode cd;
    int i, start, c;
    int p;

    cd[n] = '\0'; /*从右向左逐位存放编码，首先存放编码结束符*/
    for (i = 1; i <= n; ++i)   /*求n个叶子结点对应的哈夫曼编码*/
    {
        start = n;   /*初始化编码起始指针*/
        for (c = i, p = ht[i].parent; p != 0; c = p, p = ht[p].parent) /*从叶子到根结点求编码*/
            cd[--start] = ht[p].lch == c ? '0' : '1';
        strcpy(hc[i], &cd[start]);
    }

}

int main()
{
	HuffmanTree HT;
    HT = (*HuffmanTree)malloc(sizeof(HTNode));
	int n = 7;
	HuffmanCode HC;
    char *m[n];
    for(int i = 0;i < n; i++)
        m[i] = (char *)malloc(sizeof(char));
    HC = m;
    int w[7]={5,29,7,8,14,23,3,11};
	CreateHuffmanTree(HT, &w, n);
    CreateHuffmanCodeTable(HT, HC, n);
    printHT(HT, n);
    PrintHC(&HC,n);
	return 0;
}

