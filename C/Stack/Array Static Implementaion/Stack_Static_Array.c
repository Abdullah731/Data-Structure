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
u8      Stack_u8Pop(void);
u8      Stack_u8Top(void);
u8      Stack_u8IsEmpty(void);
u8      Stack_u8IsFull(void);



void main(void)
{
    /* ------------ Checking The Stack Pop Underflow --------------- */
    // printf("%d\n",Stack_u8Pop());

    /* ------------ Checking The Stack Overflow --------------- */
    // Stack_voidPush(1);
    // Stack_voidPush(4);
    // Stack_voidPush(2);
    // Stack_voidPush(3);
    // Stack_voidPush(8);
    // Stack_voidPush(6);


    /* ------------ Checking The Stack Underflow --------------- */
    Stack_voidPush(1);
    Stack_voidPush(4);
    Stack_voidPush(2);
    Stack_voidPush(3);
    Stack_voidPush(8);
    printf("%d\n",Stack_u8Pop());
    printf("%d\n",Stack_u8Pop());
    printf("%d\n",Stack_u8Pop());
    printf("%d\n",Stack_u8Pop());
    printf("%d\n",Stack_u8Pop());
    printf("%d\n",Stack_u8Pop());

    /* ------------ Checking The Stack Pushing and Popping --------------- */
    // Stack_voidPush(1);
    // Stack_voidPush(4);
    // Stack_voidPush(2);
    // Stack_voidPush(3);
    // Stack_voidPush(8);
    // printf("%d\n",Stack_u8Pop());
    // Stack_voidPush(6);
    // printf("%d\n",Stack_u8Pop());

    /* ------------ Test The Top Function --------------- */
    // Stack_voidPush(8);
    // printf("%d\n", Stack_u8Top());
    // printf("%d\n", Stack_u8Top());
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

u8 Stack_u8Pop(void)
{
    u8 Local_u8Data;
    if(Stack_u8IsEmpty() == 1)
    {
        return;
    }
    else
    {
        Local_u8Data = DataArray[TOP--];
        return Local_u8Data;
    }
}

u8 Stack_u8Top(void)
{
    if(Stack_u8IsEmpty() != 1)
    {
        return DataArray[TOP];
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
