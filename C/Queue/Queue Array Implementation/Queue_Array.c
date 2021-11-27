/********************************************************************
*  Author  :     Abdullah M. Abdullah
*  Date    :     26 NOV, 2021
*  Version :     v1.0
*  Descrip :     Implementation of The Queue With Static Array 
*                Allocation.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../utils/STD_TYPES.h"

#define MAX_SIZE        5

u8 DataArray[MAX_SIZE] = {0};

s8 Front = -1;

void Queue_voidEnQueue(u8 Copy_u8Data);
void Queue_voidDeQueue(void);
void Queue_voidFront(void);
u8   Queue_u8IsEmpty(void);
u8   Queue_u8IsFull(void);


void main(void)
{
    /* ---------------Enqueue & Dequeue TestCase -------------------- */
    // Queue_voidEnQueue(3);
    // Queue_voidEnQueue(4);
    // Queue_voidEnQueue(5);
    // Queue_voidEnQueue(6);
    // Queue_voidEnQueue(7);
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();

    /* ----------- Queue Underflow TestCase --------------------- */
    // Queue_voidEnQueue(3);
    // Queue_voidEnQueue(4);
    // Queue_voidEnQueue(5);
    // Queue_voidEnQueue(6);
    // Queue_voidEnQueue(7);
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();
    // Queue_voidDeQueue();

    /* ----------- Queue Overflow TestCase --------------------- */
    // Queue_voidEnQueue(3);
    // Queue_voidEnQueue(4);
    // Queue_voidEnQueue(5);
    // Queue_voidEnQueue(6);
    // Queue_voidEnQueue(7);
    // Queue_voidEnQueue(8);
    // Queue_voidEnQueue(9);
    
    /* ----------- Queue Front TestCase --------------------- */
    Queue_voidEnQueue(3);
    Queue_voidFront();
    Queue_voidEnQueue(4);
    Queue_voidFront();
}


void Queue_voidEnQueue(u8 Copy_u8Data)
{
    if(Queue_u8IsFull() == 1)
    {
        return;
    }
    else
    {
        DataArray[++Front] = Copy_u8Data;
    }
}

void   Queue_voidDeQueue(void)
{
    if(Queue_u8IsEmpty() == 1)
    {
        return;
    }
    printf("%d\n",DataArray[Front--]);
}

void   Queue_voidFront(void)
{
    if(Queue_u8IsEmpty() == 1)
    {
        return;
    }
    printf("%d\n",DataArray[Front]);
}

u8   Queue_u8IsEmpty(void)
{
    if(Front == -1)
    {
        printf("Queue Underflow\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

u8   Queue_u8IsFull(void)
{
    if(Front == (MAX_SIZE - 1))
    {
        printf("Queue Overflow\n");
        return 1;
    }
    else
    {
        return 0;
    }
}