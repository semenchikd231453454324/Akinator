#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "createroot.h"

int CreateRoot(NodeStruct* node, const char* RootName)
{
    if(!node)
    {
        printf("nullptr in Create Root\n");
        return 1;
    }

    strcpy(node->data, RootName);

    return 0;
}