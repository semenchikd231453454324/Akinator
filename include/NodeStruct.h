#ifndef NODESTRUCT_H
#define NODESTRUCT_H

#include <stdlib.h>

#define NAMELENGTH 20

struct NodeStruct
{
    char data[NAMELENGTH];

    NodeStruct* Left;
    NodeStruct* Right;
    NodeStruct* Parrent;
};

#define CREATENODE(pointer)                                 \
    pointer = (NodeStruct*) calloc(1, sizeof(NodeStruct));  \
    if(!pointer)                                            \
    {                                                       \
        printf("Pizdec with calloc pointer\n");             \
        return 1;                                           \
    }                                                       \

#endif