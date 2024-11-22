#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "accession.h"

int accession(NodeStruct* node, char* Thing, char* difference)
{
    assert(Thing);
    if(!node)
    {
        printf("Error with node pointer in accession\n");
        return 1;
    }

    char NameBuffer[15] = {};

    strcpy(NameBuffer, node->data);
    strcpy(node->data, difference);

    node->Left = (NodeStruct*) calloc(1, sizeof(NodeStruct));
    if(!node->Left)
    {
        printf("Pizdec with calloc left in accession\n");
        return 1;
    }
    node->Right = (NodeStruct*) calloc(1, sizeof(NodeStruct));
    if(!node->Right)
    {
        printf("Pizdec with calloc Right in accession\n");
        return 1;
    }

    strcpy(node->Left->data, Thing);
    strcpy(node->Right->data, NameBuffer);

    return 0;
}