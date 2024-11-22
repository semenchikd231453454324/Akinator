#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "tors.h"
#include "subtreerem.h"
#include "createroot.h"
#include "searche.h"
#include "createtree.h"
#include "Akinator.h"
#include "graphicdump.h"
#include "write.h"
#include "read.h"

int main()
{
    NodeStruct* Root;          //TODO man -> readline
    Root = (NodeStruct*) calloc(1, sizeof(NodeStruct));
    assert(Root);

    //GraphicDump(&Root);

    //Write(&Root);

    //search(&Root, "DILDO");

    Akinator(Root);

    // Akinator(&Root);

    return 0;
}