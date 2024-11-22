#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "graphicdump.h"

struct ArrowStruct
{
    char ParentName[15];
    char ChildName[15];
    bool Direction;
};

struct GraphicStruct
{
    ArrowStruct ArrowArray[40];
    size_t ArrowsQuantity;
};

static int GraphicBypass(NodeStruct* node, GraphicStruct* Arrows, FILE* dumppicture);

int GraphicDump(NodeStruct* Root)
{
    if(!Root)
    {
        printf("Bad root given to GraphicDump\n");

        return 1;
    }

    FILE* dumppicture = fopen("dumppicture.gv", "w");
    if(!dumppicture)
    {
        printf("pizdec to dumpicturepointer\n");
    }

    fprintf(dumppicture, "digraph G\n{\nnode [shape=\"record\"];\n");

    GraphicStruct Arrows = {};

    GraphicBypass(Root, &Arrows, dumppicture);

    if(Arrows.ArrowsQuantity)
    {
    for(size_t CurrentArrow = 0; CurrentArrow < Arrows.ArrowsQuantity; CurrentArrow++)
        {
            fprintf(dumppicture, "\"%s\"->\"%s\"[label =", Arrows.ArrowArray[CurrentArrow].ParentName, Arrows.ArrowArray[CurrentArrow].ChildName);
            if(Arrows.ArrowArray[CurrentArrow].Direction)
            {
                fprintf(dumppicture, "\"Yes\"]\n");
            }
            else
            {
                fprintf(dumppicture, "\"No\"]\n");
            }
        }
    }
    else
    {
        fprintf(dumppicture, "\"%s\"", Root->data);
    }
    
    fprintf(dumppicture, "}");

    fclose(dumppicture);

    system("dot -Tpng dumppicture.gv -o irpenis.png");

    return 0;
}

static int GraphicBypass(NodeStruct* node, GraphicStruct* Arrows, FILE* dumppicture)
{
    assert(Arrows);
    if(!node)
    {
        printf("Bad pointer given to Bypass\n");
        return 1;
    }

    fprintf(dumppicture, "\"%s\" [label = \"{%p | %s | {%p | %p}}\" ];\n", node->data, node, node->data, node->Left, node->Right);

    if(node->Left)
    {
        strcpy(Arrows->ArrowArray[Arrows->ArrowsQuantity].ParentName, node->data);
        strcpy(Arrows->ArrowArray[Arrows->ArrowsQuantity].ChildName, node->Left->data);
        Arrows->ArrowArray[Arrows->ArrowsQuantity].Direction = 1;
    
        Arrows->ArrowsQuantity += 1;

        GraphicBypass(node->Left, Arrows, dumppicture);
    }
    if(node->Right)
    {
        strcpy(Arrows->ArrowArray[Arrows->ArrowsQuantity].ParentName, node->data);
        strcpy(Arrows->ArrowArray[Arrows->ArrowsQuantity].ChildName, node->Right->data);
        Arrows->ArrowArray[Arrows->ArrowsQuantity].Direction = 0;

        Arrows->ArrowsQuantity += 1;

        GraphicBypass(node->Right, Arrows, dumppicture);
    }

    system("dot -Tpng dumppicture.gv -o irpenis.png");

    return 0;
}