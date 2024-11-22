#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "tors.h"

int AddNewElem(NodeStruct* node, const char NewElemName [15], const char ElemName [15], const char Direction[5])
{
    assert(NewElemName);
    assert(ElemName);
    assert(Direction);
    if(!node)
    {
        return 1;
    }

    if(!strcmp(node->data, ElemName))
    {
        if(!strcmp("Left", Direction))
        {
            if(!node->Left)
            {
                node->Left = (NodeStruct*) calloc(1, sizeof(NodeStruct));
                strcpy(node->Left->data, NewElemName);
            }
            else
            {
                printf("Can't add elem %s Left Direction of %s isn't empty\n", NewElemName, node->data);
            }
            return 0;
        }
        else if(!strcmp("Right", Direction))
        {
            if(!node->Right)
            {
                node->Right = (NodeStruct*) calloc(1, sizeof(NodeStruct));
                strcpy(node->Right->data, NewElemName);
            }
            else
            {
                printf("Can't add elem %s Right Direction of %s isn't empty\n", NewElemName, node->data);
            }
            return 0;
        }
        else
        {
            printf("Unknown direction\n");
            printf("%s", node->data);
            return 0;
        }
    }

    if(node->Left)
    {
        AddNewElem(node->Left, NewElemName, ElemName, Direction);
    }
    if(node->Right)
    {
        AddNewElem(node->Right, NewElemName, ElemName, Direction);
    }
    
    return 0;
}

int RemoveElem(NodeStruct* node, const char RemoveElemName [15])
{
    assert(RemoveElemName);
    if(!node)
    {
        return 0;
    }

    if(!strcmp(node->data, RemoveElemName))
    {
        if(!node->Left)
        {
            printf("Can't remove elem %s, left subtree isn't empty\n", RemoveElemName);
            return 1;
        }
        else if(!node->Right)
        {
            printf("Can't remove elem %s, right subtree isn't empty\n", RemoveElemName);
            return 1;
        }
        
        node = {};
    }

    if(node->Left)
    {
        RemoveElem(node->Left, RemoveElemName);
    }
    if(node->Right)
    {
        RemoveElem(node->Right, RemoveElemName);
    }
    
    return 0;
}