/********************************************************************
*  Author  :     Abdullah M. Abdullah
*  Date    :     26 NOV, 2021
*  Version :     v1.0
*  Descrip :     Implementation of The Queue With LinkedList.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../utils/STD_TYPES.h"

struct QueueNode
{
    u8 Data;
    struct QueueNode * PointerToTheNextNode;
};

struct QueueNode * Front = NULL;

void Queue_voidEnQueue(u8 Copy_u8Data);
u8   Queue_u8DeQueue(void);
u8   Queue_u8Front(void);
u8   Queue_u8IsEmpty(void);
u8   Queue_u8IsFull(void);


void main(void)
{
    // Queue_voidEnQueue(5);
    // Queue_voidEnQueue(6);
    // printf("%d\n",Queue_u8DeQueue());
    // printf("%d\n",Queue_u8DeQueue());
    // printf("%d\n",Queue_u8DeQueue());

    /* ---------------------------------------------------- */
    Queue_voidEnQueue(6);
    Queue_voidEnQueue(8);
    printf("%d\n", Queue_u8Front());
    Queue_u8DeQueue();
    printf("%d\n", Queue_u8Front());
}



void Queue_voidEnQueue(u8 Copy_u8Data)
{
    struct QueueNode * TempNode;
    struct QueueNode * NewNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    TempNode = Front;
    Front = NewNode;
    NewNode -> Data = Copy_u8Data;
    NewNode -> PointerToTheNextNode = TempNode;
}

u8   Queue_u8DeQueue(void)
{
    u8 Local_u8Data;
    if(Queue_u8IsEmpty() == 0)
    {
        return;
    }
    struct QueueNode * CurrentNode;
    CurrentNode = Front;
    Front = CurrentNode -> PointerToTheNextNode;
    Local_u8Data = CurrentNode -> Data;
    free(CurrentNode);
    return Local_u8Data;
}

u8   Queue_u8Front(void)
{
    if(Queue_u8IsEmpty() == 0)
    {
        return;
    }
    return Front -> Data;
}

u8   Queue_u8IsEmpty(void)
{
    if(Front == NULL)
    {
        printf("Queue Underflow!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}