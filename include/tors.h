#ifndef TORS_H
#define TORS_H

#include "NodeStruct.h"

int AddNewElem(NodeStruct* node, const char NewElemName [15], const char ElemName [15], const char Direction[5]);
int RemoveElem(NodeStruct* node, const char RemoveElemName [15]);

#endif