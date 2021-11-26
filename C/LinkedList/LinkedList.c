#include <stdio.h>
#include <stdlib.h>
#include "../STD_TYPES.h"

#define     NULL        (void*)0
// Create a Struct
struct Node
{
    u8 Data;
    struct Node * PointerToTheNextNode;
};

/*Declare and Initialize HeadNode Pointer To Struct*/
struct Node * HeadNode = NULL;

/*A Function To Insert A Node At The End Of The LinkedList*/
void LinkedList_voidTailInsert(u8 Copy_u8Data)
{
    /*Check if there is any node already in the linkedlist*/
    if(HeadNode == NULL)
    {
        /*Declare and Reserve A New Node Pointer To Struct Which Has A Size Of The Node Struct*/
        struct Node * NewNode             = (struct Node *) malloc(sizeof(struct Node));
        /*Assign The Given Data To This New Node*/
        NewNode  -> Data                  = Copy_u8Data;
        /*Assign The PointerToNextNode To NULL */
        NewNode  -> PointerToTheNextNode  = NULL;
        /*Make The HeadNode Pointer To Struct Points To The NewNode*/
        HeadNode = NewNode;
    }
    /*If There Was Already Nodes In The LinkedList*/
    else
    {
        /*Declare A New Node*/
        struct Node * Temp;
        /*Set The Temp Node To The HeadNode*/
        Temp = HeadNode;
        /*Looping On The PointerToTheNextNode Until Reaching The Last Node*/
        while(Temp -> PointerToTheNextNode != NULL)
        {
            Temp = Temp -> PointerToTheNextNode;
        }
        struct Node * NewNode = (struct Node *) malloc(sizeof(struct Node));
        Temp    -> PointerToTheNextNode = NewNode;
        NewNode -> Data                 = Copy_u8Data;
        NewNode -> PointerToTheNextNode = NULL;
    }
}

void LinkedList_voidPrint(void)
{
    /*Function To Print All Nodes' Data*/
    u8 LoopCounter = 0;
    struct Node * TempNode = HeadNode;
    while(TempNode != NULL)
    {
        printf("The Data In The Node Index %d Is = %d\n", LoopCounter, TempNode -> Data);
        TempNode = TempNode -> PointerToTheNextNode;
        LoopCounter++;
    }
}

void main(void)
{
    LinkedList_voidTailInsert(1);
    LinkedList_voidTailInsert(2);
    LinkedList_voidTailInsert(3);
    LinkedList_voidTailInsert(4);
    
    LinkedList_voidPrint();
}
