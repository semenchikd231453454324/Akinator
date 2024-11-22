#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "write.h"

#define FILENAMESIZE 25

static int WriteBypass(NodeStruct* node, FILE* OutputText, size_t* depth);

int Write(NodeStruct* Root)
{
    if(!Root)
    {
        printf("Pizdec with root in Write\n");
        return 1;
    }

    char FileName[FILENAMESIZE] = {};

    printf("Enter the name of file\n");
    scanf("%s", FileName);

    FILE* OutputText = fopen(FileName, "w");
    if(!OutputText)
    {
        printf("Pizdec with OutputText Pointer\n");
        return 1;
    }

    size_t depth = 0;

    WriteBypass(Root, OutputText, &depth);

    fclose(OutputText);
    
    return 0;
}

static int WriteBypass(NodeStruct* node, FILE* OutputText, size_t* depth)
{
    assert(depth);
    assert(OutputText);
    if(!node)
    {
        printf("Pizdec with OutputText\n");
        return 1;
    }

    *depth += 1;

    fprintf(OutputText, "{\n");

    for(size_t i = 0; i < *depth - 1; i++)
    {
        fprintf(OutputText ,"    ");
    }

    fprintf(OutputText, "%s\n", node->data);

    if(node->Left)
    {
        for(size_t i = 0; i < *depth; i++)
        {
            fprintf(OutputText ,"    ");
        }
        WriteBypass(node->Left, OutputText, depth);
    }
    if(node->Right)
    {
        for(size_t i = 0; i < *depth; i++)
        {
            fprintf(OutputText ,"    ");
        }
        WriteBypass(node->Right, OutputText, depth);
    }

    for(size_t i = 0; i < *depth - 1; i++)
    {
        fprintf(OutputText ,"    ");
    }

    fprintf(OutputText, "}\n");

    *depth -= 1;

    return 0;
}