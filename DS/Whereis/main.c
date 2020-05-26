#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "BiTree.h"

#define EOL putchar('\n')

void print(DataType e)
{
    printf("%2c", e);
}

BiTree WhereIs(BiTree root, char node);
BiTree MySiblings(BiTree root, char node);

int main(int argc, char *argv[]) //char **argv
{
    if (argc < 2)
    {
        printf("Usage: where <node-name>\n");
        return 1;
    }

    char *const nodes = "ABDHL..M...E.I..CF.JN...G.K.O..";
    char *p = nodes;
    char node;
    BiTree BiRoot = NULL, t;

    BiRoot = CreateBiTree(&p);

    PreOrder(BiRoot, print);
    EOL;

    node = argv[1][0];
    // t = WhereIs(BiRoot, node);
    // if (t != NULL)
    //     printf("Found node %c\n", node);
    // else
    //     printf("Cannot find node %c\n", node);

    t = MySiblings(BiRoot, node);
    if (t != NULL)
        printf("The sibling of the node %c is %c\n", node, t->data);
    else
        printf("The node %c doesn't have any sibling\n", node);

    DestroyBiTree(BiRoot);

    return 0;
}

BiTree WhereIs(BiTree root, char node)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    BiTree t = WhereIs(root->LChild, node);
    return t != NULL ? t : WhereIs(root->RChild, node);
}

BiTree MySiblings(BiTree root, char node)
{
    if (root == NULL)
        return NULL;

    DataType l = 0, r = 0;

    if (root->LChild != NULL)
        l = root->LChild->data;
    if (root->RChild != NULL)
        r = root->RChild->data;

    if (l == node)
        return root->RChild;
    if (r == node)
        return root->LChild;

    BiTree t = MySiblings(root->LChild, node);
    return t != NULL ? t : MySiblings(root->RChild, node);
}