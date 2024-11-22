#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "searche.h"

struct Paths
{
    char* Path[100];
    char* CurrentPath[100];
    bool CurrentIsRight[100];
    bool IsRight[100];
    size_t CurrentPathLen;
};

static int searchElem(NodeStruct* node, const char ElemName[15], Paths* SearchPaths);

int search(NodeStruct* root, const char ElemName[15])
{
    assert(ElemName);
    if(!root)
    {
        printf("pizdec wih root pointer in serach\n");
        return 1;
    }
    
    Paths SearchPaths = {};
    Paths A[10];
    
    searchElem(root, ElemName, &SearchPaths);

    int i = 1;
    do 
    {
        if(SearchPaths.IsRight[i])
        {
            printf("NE ");
        }
        printf("%s ", SearchPaths.Path[i]);
        i++;
    } while(SearchPaths.Path[i]);

    printf("\n\nEnter anything to continue\n");

    char WTF[2] = {};
    scanf("%s", WTF);
    
    
    return 0;
}

int difference(NodeStruct* root, const char FirstElemName[15], const char SecondElemName[15])
{
    assert(FirstElemName);
    assert(SecondElemName);
    if(!root)
    {
        printf("pizdec wih root pointer in difer\n");
        return 1;
    }

    Paths FirstSearchPaths = {};
    Paths SecondSearchPaths = {};

    searchElem(root, FirstElemName, &FirstSearchPaths);
    searchElem(root, SecondElemName, &SecondSearchPaths);

    printf("They're same with: ");

    int FeatureNum = 1;
    while(!strcmp(FirstSearchPaths.Path[FeatureNum], SecondSearchPaths.Path[FeatureNum]) && FirstSearchPaths.IsRight[FeatureNum] == SecondSearchPaths.IsRight[FeatureNum])
    {
        if(FirstSearchPaths.IsRight[FeatureNum])
        {
            printf("NE ");
        }
        printf("%s ", FirstSearchPaths.Path[FeatureNum]);
        FeatureNum++;
    }

    int FirstFeatureNum = FeatureNum, SecondFeatureNum = FeatureNum;

    printf("\n\nThey're different in:\n%s: ", FirstElemName);

    do 
    {
        if(FirstSearchPaths.IsRight[FirstFeatureNum])
        {
            printf("NE ");
        }
        printf("%s ", FirstSearchPaths.Path[FirstFeatureNum]);
        FirstFeatureNum++;
    } while(FirstSearchPaths.Path[FirstFeatureNum]);

    printf("\n%s: ", SecondElemName);

    do 
    {
        if(SecondSearchPaths.IsRight[SecondFeatureNum])
        {
            printf("NE ");
        }
        printf("%s ", SecondSearchPaths.Path[SecondFeatureNum]);
        SecondFeatureNum++;
    } while(SecondSearchPaths.Path[SecondFeatureNum]);

    printf("\n");

    printf("\nEnter anything to continue\n");

    char WTF[2] = {};
    scanf("%s", WTF);

    return 0;
}

static int searchElem(NodeStruct* node, const char ElemName[15], Paths* SearchPaths)
{
    if(!node)
    {
        printf("Bad root given to searchElem\n");
        return 1;
    }
    assert(SearchPaths);    
    assert(ElemName);

    SearchPaths->CurrentPathLen += 1;
    
    if(!node)
    {
        SearchPaths->CurrentPathLen -= 1;
        return 0;
    }

    SearchPaths->CurrentPath[SearchPaths->CurrentPathLen] = node->data;

    if(!strcmp(ElemName, node->data))
    {
        for(size_t i = 1; i < SearchPaths->CurrentPathLen; i++)
        {
            SearchPaths->Path[i] = SearchPaths->CurrentPath[i];
            SearchPaths->IsRight[i] = SearchPaths->CurrentIsRight[i];
        }

        return 0;
    }

    if(node->Left)
    {
        searchElem(node->Left, ElemName, SearchPaths);
    }
    if(node->Right)
    {
        SearchPaths->CurrentIsRight[SearchPaths->CurrentPathLen] = 1;        
        searchElem(node->Right, ElemName, SearchPaths);
    }
    
    SearchPaths->CurrentPath[SearchPaths->CurrentPathLen] = {};
    SearchPaths->CurrentPathLen -= 1;

    return 0;
}

