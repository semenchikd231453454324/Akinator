#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "createtree.h"

int CreateTree(NodeStruct* Root)
{
    if(!Root)
    {
        printf("Incorrect Root pointer in createtree\n");
        return 1;
    }

    CreateRoot(Root, "PENIS");
    
    AddNewElem(Root, "MICRO", "PENIS", "Left");
    
    AddNewElem(Root, "MEGA", "PENIS", "Right");

    AddNewElem(Root, "DILDO", "MEGA", "Right");

    AddNewElem(Root, "SUPER", "MEGA", "Left");

    // AddNewElem(Root, "ULTRA", "MICRO", "Left");

    return 0;
}