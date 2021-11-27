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

void LinkedList_voidInsertNodeAtTail(u8 Copy_u8Data);
void LinkedList_voidInsertNodeAtSpecificPosition(u8 Copy_u8NodePosition, u8 Copy_u8Data);
u8   LinkedList_u8DeleteNode(u8 Copy_u8DataToBeDeleted);
u8   LinkedList_u8SearchInLinkedList(u8 Copy_u8DataToBeSearchFor);
void LinkedList_voidPrintAllLinkedList(void);



void main(void)
{
    LinkedList_voidInsertNodeAtTail(1);
    LinkedList_voidInsertNodeAtTail(2);
    LinkedList_voidInsertNodeAtTail(5);
    
    LinkedList_u8SearchInLinkedList(0);
    
    LinkedList_u8SearchInLinkedList(1);

    LinkedList_voidPrintAllLinkedList();
}


/*A Function To Insert A Node At The End Of The LinkedList*/
void LinkedList_voidInsertNodeAtTail(u8 Copy_u8Data)
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

void LinkedList_voidInsertNodeAtSpecificPosition(u8 Copy_u8NodePosition, u8 Copy_u8Data)
{
    /*Check if the linked list is empty*/
    if(HeadNode == NULL)
    {
        /*Calling the InsertNodeAtTail function to add this node*/
        LinkedList_voidInsertNodeAtTail(Copy_u8Data);
    }
    else
    {
        u8 LoopCounter;
        struct Node * NewNode = (struct Node *)malloc(sizeof(struct Node));
        struct Node * TempNode;
        TempNode = HeadNode;
        NewNode -> Data = Copy_u8Data;
        /*Check if the Position was 0, then the Node Should be at the beginning of the linked list*/
        if(Copy_u8NodePosition == 0)
        {
            NewNode -> PointerToTheNextNode  = HeadNode;
            HeadNode = NewNode;
        }
        else
        {
            for(LoopCounter = 0; LoopCounter < (Copy_u8NodePosition-1); LoopCounter++)
            {
                if(TempNode -> PointerToTheNextNode == NULL)
                {
                    break;
                }
                TempNode = TempNode -> PointerToTheNextNode;
            }
            NewNode -> PointerToTheNextNode = TempNode -> PointerToTheNextNode;
            TempNode -> PointerToTheNextNode = NewNode;
        }
    }
}
u8 LinkedList_u8DeleteNode(u8 Copy_u8DataToBeDeleted)
{
    // 0 -> No Error, 1 -> The Data Does Not Exists, 2 -> The Linked List Is Empty.
    u8 Local_u8ErrorStatus;
    struct Node * CurrentNode;
    struct Node * PrevoiusNode;
    CurrentNode = HeadNode;
    if(CurrentNode == NULL)
    {
        printf("The Linked List Is Empty, Please Insert Some Data\n");
        return 2;
    }
    else
    {
        while( (CurrentNode != NULL) && (CurrentNode -> Data != Copy_u8DataToBeDeleted) )
        {
            PrevoiusNode = CurrentNode;
            CurrentNode = CurrentNode -> PointerToTheNextNode;
        }
        if(CurrentNode == NULL)
        {
            printf("The Entered Data \"%d\" Does Not Exists\n", Copy_u8DataToBeDeleted);
            return 1;
        }
        else
        {
            if(Copy_u8DataToBeDeleted == HeadNode -> Data)
            {
                HeadNode = HeadNode -> PointerToTheNextNode;
                free(CurrentNode);
            }
            else
            {
                PrevoiusNode -> PointerToTheNextNode = CurrentNode -> PointerToTheNextNode;
                free(CurrentNode);
            }
            printf("The Entered Data Has Been Deleted Successfully \n");
            return 0;
        }
    }
}

u8 LinkedList_u8SearchInLinkedList(u8 Copy_u8DataToBeSearchFor)
{
    struct Node * TempNode;
    TempNode = HeadNode;
    u8 Local_u8Flag = 1;
    while((TempNode -> Data != Copy_u8DataToBeSearchFor))
    {
        TempNode = TempNode -> PointerToTheNextNode;
        if((TempNode == NULL))
        {
            Local_u8Flag = 0;
            break;
        }
    }
    if(Local_u8Flag == 1)
    {
        printf("The Entered Data \"%d\" Found In The Linked List \n", Copy_u8DataToBeSearchFor);
        return 1;
    }
    else
    {
        printf("Sorry, The Entered Data \"%d\" Did Not Found In The Linked List\n", Copy_u8DataToBeSearchFor);
        return 0;
    }

}

void LinkedList_voidPrintAllLinkedList(void)
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
