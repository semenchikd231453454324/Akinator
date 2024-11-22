#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "subtreerem.h"

int subtreerem(NodeStruct* node, const char subtreeName [15])
{
    if(!node)
    {
        return 0;
    }

    if(!strcmp(node->data, subtreeName))
    {
        treerem(node);
    }

    if(node->Left)
    {
        subtreerem(node->Left, subtreeName);
    }
    if(node->Right)
    {
        subtreerem(node->Right, subtreeName);
    }
    
    return 0;
}

int treerem(NodeStruct* node)
{
    if(!node)
    {
        return 0;
    }

    if(!node->Left && !node->Right)
    {
        free(node);
        return 1;
    }

    if(node->Left)
    {
        treerem(node->Left);
        node->Left = nullptr;
    }
    if(node->Right)
    {
        treerem(node->Right);
        node->Right = nullptr;
    }

    return 0;
}
