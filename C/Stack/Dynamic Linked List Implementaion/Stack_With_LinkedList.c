/********************************************************************
*  Author  :     Abdullah M. Abdullah
*  Date    :     27 NOV, 2021
*  Version :     v1.0
*  Descrip :     Implementation of the Stack Data Structrue using 
*                Linked List, unlimited Size.
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../../utils/STD_TYPES.h"

struct Stack
{
    u8 Data;
    struct Stack * PointerToTheNextNode;
};

struct Stack * TOP = NULL;

void Stack_voidPush(u8 Copy_u8Data);
u8 Stack_u8Pop(void);
u8 Stack_u8Top(void);
u8 Stack_u8IsEmpty(void);


void main(void)
{

    // Stack_voidPush(5);
    // Stack_voidPush(3);
    // Stack_voidPush(2);
    // Stack_voidPush(4);
    // printf("The Top Value Is %d\n",Stack_u8Pop());
    // printf("The Top Value Is %d\n",Stack_u8Pop());
    // printf("The Top Value Is %d\n",Stack_u8Pop());
    // Stack_voidPush(8);
    // printf("The Top Value Is %d\n",Stack_u8Pop());

    /* ------------------------------------------------------ */

    // printf("%d", Stack_u8Top());
    

    /* ------------------------------------------------------ */

    // Stack_voidPush(5);
    // Stack_voidPush(2);
    // Stack_voidPush(3);
    // printf("%d\n", Stack_u8Top());
    // Stack_u8Pop();
    // printf("%d\n", Stack_u8Top());
    
    /* ------------------------------------------------------ */

    // Stack_voidPush(3);
    // printf("%d\n", Stack_u8IsEmpty());
    // printf("%d\n", Stack_u8Pop());
    // printf("%d\n", Stack_u8IsEmpty());
}



void Stack_voidPush(u8 Copy_u8Data)
{
    struct Stack * NewNode = (struct Stack *)malloc(sizeof(struct Stack));
    if(TOP == NULL)
    {
        TOP = NewNode;
        NewNode -> PointerToTheNextNode = NULL;
    }
    else
    {
        struct Stack * Temp;
        Temp = TOP;
        TOP = NewNode;
        NewNode -> PointerToTheNextNode = Temp;
    }
    NewNode -> Data = Copy_u8Data;
}

u8 Stack_u8Pop(void)
{
    if(Stack_u8IsEmpty() == 0)
    {
        printf("Sorry, The Stack Is Empty Please Insert Some Data\n");
        return;
    }
    u8 Local_u8NodeData;
    struct Stack * Temp;
    Temp = TOP;
    TOP = TOP -> PointerToTheNextNode;
    Local_u8NodeData = Temp -> Data;
    free(Temp);
    return Local_u8NodeData;
}

u8 Stack_u8Top(void)
{
    if(Stack_u8IsEmpty() == 0)
    {
        printf("Sorry, The Stack Is Empty Please Insert Some Data\n");
        return;    
    }
    return TOP -> Data;

}
/* Function That Returns 0 If The Stack Is Empty, Otherwise, Returns 1*/
u8 Stack_u8IsEmpty(void)
{
    if(TOP == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}