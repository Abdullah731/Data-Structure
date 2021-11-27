/********************************************************************
*  Author  :     Abdullah M. Abdullah
*  Date    :     26 NOV, 2021
*  Version :     v1.0
*  Descrip :     Implementation of The Stack With Static Array
*                Allocation.
********************************************************************/
#include <stdio.h>
#include "../../utils/STD_TYPES.h"


#define MAX_SIZE        5

u8 DataArray[MAX_SIZE] = {0};

s8 TOP = -1;

void    Stack_voidPush(u8 Copy_u8Data);
void    Stack_voidPop(void);
void    Stack_voidTop(void);
u8      Stack_u8IsEmpty(void);
u8      Stack_u8IsFull(void);



void main(void)
{
    /* ------------ Checking The Stack Pop Underflow --------------- */
    // Stack_voidPop();

    /* ------------ Checking The Stack Overflow --------------- */
    // Stack_voidPush(1);
    // Stack_voidPush(4);
    // Stack_voidPush(2);
    // Stack_voidPush(3);
    // Stack_voidPush(8);
    // Stack_voidPush(6);


    /* ------------ Checking The Stack Underflow --------------- */
    // Stack_voidPush(1);
    // Stack_voidPush(4);
    // Stack_voidPush(2);
    // Stack_voidPush(3);
    // Stack_voidPush(8);
    // Stack_voidPop();
    // Stack_voidPop();
    // Stack_voidPop();
    // Stack_voidPop();
    // Stack_voidPop();
    // Stack_voidPop();

    /* ------------ Checking The Stack Pushing and Popping --------------- */
    // Stack_voidPush(1);
    // Stack_voidPush(4);
    // Stack_voidPush(2);
    // Stack_voidPush(3);
    // Stack_voidPush(8);
    // Stack_voidPop();
    // Stack_voidPush(6);
    // Stack_voidPop();

    /* ------------ Test The Top Function --------------- */
    Stack_voidPush(8);
    Stack_voidTop();
    Stack_voidTop();
}



void Stack_voidPush(u8 Copy_u8Data)
{
    if(Stack_u8IsFull() == 1)
    {
        return;
    }
    else
    {
        DataArray[++TOP] = Copy_u8Data;
    }

}

void Stack_voidPop(void)
{
    u8 Local_u8Data;
    if(Stack_u8IsEmpty() == 1)
    {
        return;
    }
    else
    {
        printf("%d\n", DataArray[TOP--]);
    }
}

void Stack_voidTop(void)
{
    if(Stack_u8IsEmpty() != 1)
    {
        printf("%d\n", DataArray[TOP]);
    }
    
}

u8 Stack_u8IsEmpty(void)
{
    if((TOP == -1))
    {
        printf("Stack Underflow\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

u8 Stack_u8IsFull(void)
{
    if(TOP == MAX_SIZE-1)
    {
        printf("Stack Overflow\n");
        return 1;
    }
    else
    {
        return 0;
    }

}
