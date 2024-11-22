#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "read.h"
#include "graphicdump.h"

#define FILENAMESIZE 25

//static int ReadBypass(NodeStruct* node, char* Text, size_t* CurrentNum, bool* IsLeft);
static NodeStruct* ReadBypass(NodeStruct* Senior, char* Text, size_t* CurrentNum);


NodeStruct* Read(NodeStruct* Root)
{
    if(!Root)
    {
        printf("Pizdec with root in Read\n");
        return nullptr;
    }

    char FileName[FILENAMESIZE] = {};

    printf("Enter the name of Load file\n");
    scanf("%s", FileName);

    FILE* InputText = fopen(FileName, "r");
    if(!InputText)
    {
        printf("Pizdec with InputText Pointer\n");
        return nullptr;
    }

    struct stat FileInf = {};
    stat(FileName, &FileInf);

    size_t BufferSize = FileInf.st_size;

    char* Buffer = (char*) calloc(BufferSize, sizeof(char));
    if(!Buffer)
    {
        printf("Pizdec with pointer in calloc buffer\n");
        return nullptr;
    }
    char* Text = (char*) calloc(BufferSize, sizeof(char));
    if(!Text)
    {
        printf("Pizdec with pointer in calloc buffer\n");
        return nullptr;
    }

    fread(Buffer, sizeof(char), BufferSize, InputText);

    size_t CurrentTextElem = 0;
    for(size_t CurrentElem = 0; CurrentElem < BufferSize; CurrentElem++)
    {
        if(Buffer[CurrentElem] == '\n' || Buffer[CurrentElem] == ' ')
        {}
        else
        {
            Text[CurrentTextElem] = Buffer[CurrentElem];
            CurrentTextElem++;
        }
    }

    for(size_t i = 0; i < CurrentTextElem; i++)
    {
        printf("%c", Text[i]);
    }

    printf("\n");

    size_t CurrentNum = 1;
    //bool IsLeft = 1;

    //printf("huynya = %s\n", ReadBypass(0, Text, &CurrentNum)->Left->data);

    return ReadBypass(0, Text, &CurrentNum);

    //GraphicDump(Root);

    return 0;
}

static NodeStruct* ReadBypass(NodeStruct* Senior, char* Text, size_t* CurrentNum)
{
    assert(Text);
    assert(CurrentNum);

    if(Text[*CurrentNum] == '\0')
    {
        return nullptr;
    }

    //NodeStruct* CREATENODE(node);


    NodeStruct* node = (NodeStruct*) calloc(1, sizeof(NodeStruct));
    if(!node)
    {
        printf("Pizdec wih pointer in calloc");
        return node;
    }

    node->Parrent = Senior;

    int NodeDataElem = 0;

    while ((Text[*CurrentNum] != '{') && (Text[*CurrentNum] != '}'))
    {
        node->data[NodeDataElem] = Text[*CurrentNum];

        *CurrentNum += 1;
        NodeDataElem++;
    }

    if(Text[*CurrentNum] == '{')
    {
        *CurrentNum += 1;
        node->Left = ReadBypass(node, Text, CurrentNum);
        *CurrentNum += 1;
    }
    if(Text[*CurrentNum] == '{')
    {
        *CurrentNum += 1;
        node->Right = ReadBypass(node, Text, CurrentNum);
        *CurrentNum += 1;
    }

    return node;
}


/* static int ReadBypass(NodeStruct* node, char* Text, size_t* CurrentNum, bool* IsLeft)
{
    assert(Text);
    assert(CurrentNum);
    printf("%ld\n", *CurrentNum);
    if(Text[*CurrentNum])
    {
        if(Text[*CurrentNum] == '{')
        {
            *CurrentNum += 1;

            CREATENODE(node);

            printf("%ld\n", *CurrentNum);

            int NodeDataElem = 0;
            do
            {
                printf("%d\n", NodeDataElem);
                node->data[NodeDataElem] = Text[*CurrentNum];
                printf("%d\n", NodeDataElem);

                *CurrentNum += 1;
                NodeDataElem++;
            } while ((Text[*CurrentNum] != '{') && (Text[*CurrentNum] != '}'));
            
            printf("penis\n");

            if(*IsLeft)
            {
                ReadBypass(node->Left, Text, CurrentNum, IsLeft);
            }
            else
            {
                ReadBypass(node->Right, Text, CurrentNum, IsLeft);
            }
        }
        else if(Text[*CurrentNum] == '}')
        {
            *CurrentNum += 1;
            *IsLeft = !(*IsLeft);
            return 0;
        }
    }

    return 0;
}*/