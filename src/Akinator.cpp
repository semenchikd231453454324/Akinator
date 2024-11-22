#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <sys/stat.h>

#include "Akinator.h"
#include "searche.h"
#include "graphicdump.h"
#include "createroot.h"
#include "subtreerem.h"
#include "write.h"
#include "read.h"

int Akinator(NodeStruct* Root)
{

    CreateRoot(Root, "Unknown");

    char Command[15] = {};

    bool WorkingStatus = 1;

    while(WorkingStatus)
    {
        printf("Enter command:\nguess - play akinator\nroot - ceate first element\ndump - to create graphic dump\npath - to show path to elem\ndiv - to show differenses\nsave - to write tree to file\nload - to write from file\nquit - stop program\n");

        scanf("%s", Command);

        if(!strcmp(Command, "guess"))
        {
            printf("Let's start:\n");

            choice(Root);
        }
        else if(!strcmp(Command, "dump"))
        {
            GraphicDump(Root);
        }
        else if(!strcmp(Command, "root"))
        {
            char RootName[15] = {};

            printf("Enter Root name:\n");
            
            scanf("%s", RootName);

            CreateRoot(Root, RootName);
        }
        else if(!strcmp(Command, "save"))
        {
            Write(Root);

            printf("Your tree was saved\n");
        }
        else if(!strcmp(Command, "load"))
        {
            Root = Read(Root);

            printf("Your tree was loaded\n");
        }
        else if(!strcmp(Command, "path"))
        {
            printf("Enter name of the Element for path\n");

            char ElemName[15] = {};
            scanf("%s", ElemName);

            search(Root, ElemName);
        }
        else if(!strcmp(Command, "div"))
        {
            printf("Enter name of the First Element:\n");

            char FirstElemName[15] = {};
            scanf("%s", FirstElemName);

            printf("Enter name of the Second Element:\n");

            char SecondElemName[15] = {};
            scanf("%s", SecondElemName);

            difference(Root, FirstElemName, SecondElemName);
        }
        else if(!strcmp(Command, "quit"))
        {
            WorkingStatus = 0;
        }
        else
        {
            printf("Unknown commands tru again.\n");
        }
    }

    return 0;
}

int choice(NodeStruct* node)
{
    if(!node)
    {
        return 1;
    }

    char CurrentCommand [15] = {};
    char answer = 0;

    if (!node->Left && !node->Right)
    {
        printf("You guessed %s?[y/n]\n", node->data);

        scanf("%s", &answer);

        if(!strcmp(&answer, "y"))
        {
            printf("Congrats\n");
            return 0;
        }
        else if(!strcmp(&answer, "n"))
        {
            char Thing[15] = {};

            printf("What did you guess?\n");

            scanf("%s", Thing);
            //fgets(Thing, 15, stdin);

            printf("What difference between %s and %s?\n", Thing, node->data);

            scanf("%s", CurrentCommand);
            //fgets(CurrentCommand, 15, stdin);

            accession(node, Thing, CurrentCommand);
            return 0;
        }
        
        printf("Unknown answer\n");
        return 1;
    }
    else
    {
        printf("Does your thing have feature %s?[y/n]\n", node->data);
        scanf("%s", CurrentCommand);
        if(!strcmp(CurrentCommand, "y"))
        {
            if(!node->Left)
            {
                printf("There is no left leaf in %s\nYou want to add %s there?[y/n]\n", node->data, "penis");

                char Ans[15] = {};
                scanf("%s", Ans);
                if(!strcmp(Ans, "y"))
                {
                    CREATENODE(node->Left);
                    strcpy(node->Left->data, "penis");

                    return 0;
                }
                else if(!strcmp(Ans, "n"))
                {
                    printf("OK Thing didn't added\n");
                    return 0;
                }
                else
                {
                    printf("Unknown command\n");
                    return 1;
                }

                return 0;
            }
            
            choice(node->Left);
        }
        else if(!strcmp(CurrentCommand, "n"))
        {
            if(!node->Right)
            {
                printf("There is no Right leaf in %s\nYou want to add %s there?[y/n]\n", node->data, "penis");

                char Ans[15] = {};
                scanf("%s", Ans);
                if(!strcmp(Ans, "y"))
                {
                    CREATENODE(node->Right);
                    strcpy(node->Right->data, "penis");

                    return 0;
                }
                else if(!strcmp(Ans, "n"))
                {
                    printf("OK Thing didn't added\n");
                    return 0;
                }
                else
                {
                    printf("Unknown command\n");
                    return 1;
                }

                return 0;
            }
            
            choice(node->Right);
        }
        else
        {
            printf("Unknown answer\n");
            return 1;
        }
    }
    
    return 0;
}

