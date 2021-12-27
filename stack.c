#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "typedef.h"

/*
MACROS
*/
#define EMPTY_STACK 0
#define FULL_STACK 100


typedef struct Node_t node;
typedef struct Node_t
{
    uint8_t u8_NodeData;
     node* u8_PtrToNode;

}node;

/*
Global Variables
*/
uint8_t gu8_stackTop = EMPTY_STACK;
node* gptr_head = NULL;


/*
Function prototypes
*/
void push(uint8_t  u8_data);
uint8_t pull(void);
void printStack(void);
uint8_t* balancedParentheses(uint8_t* expression);


/*
push function that take data and added it to stack
function take u8 data and return void
*/
void push(uint8_t u8_data)
{
    node* Ptr_temp;
    node* Ptr_NewNode=(node*)malloc(sizeof(node));
    if(gptr_head == NULL)
    {
        gptr_head = Ptr_NewNode;
        Ptr_NewNode->u8_NodeData = u8_data;
        Ptr_NewNode->u8_PtrToNode = NULL;
        gu8_stackTop++;
    }
    else if (FULL_STACK <= gu8_stackTop)
    {
        printf(" Stack Overflow\n");

    }
    else
    {
     Ptr_temp = gptr_head ;
    gptr_head = Ptr_NewNode ;
    Ptr_NewNode->u8_NodeData = u8_data;
    Ptr_NewNode->u8_PtrToNode = Ptr_temp;
    gu8_stackTop++;
    }
}


/*
pull function that pull u8 data from the stack
function take void and return u8 data
*/
uint8_t pull()
{
    node* Ptr_temp;
    uint8_t u8_pulled;

    if(gptr_head == NULL)
    {
        printf(" Nothing to pull\n");
        return NULL;
    }
    else
    {
        Ptr_temp = gptr_head;
        gptr_head = Ptr_temp->u8_PtrToNode;
        u8_pulled = Ptr_temp->u8_NodeData;
        free(Ptr_temp);
        gu8_stackTop--;
        return u8_pulled;
    }
}

/*
function to print the stack
*/
void printStack(void)
{
   while(gptr_head!=NULL)    //while head not equal null (didn't pull all elements)
   {
      printf("%c ", pull());  //pull and print
   }
}

/*
function check the balanced parentheses
function take string and return balanced or unbalanced
*/
uint8_t* balancedParentheses(uint8_t* str)
{
    uint8_t u8_TestChar=0;
    uint8_t u8_index=0;
    sint8_t s8_Curly = 0;
    sint8_t s8_Bracket = 0;

    while(str[u8_index]!='\0')
    {
        push(str[u8_index]);
        u8_index++;
    }


    while (gptr_head != NULL)
    {
        u8_TestChar=pull();
        if(u8_TestChar == '{')
            {
                s8_Curly ++;
            }

        else if(u8_TestChar == '}')
        {
            s8_Curly --;
        }
        else if(u8_TestChar =='(')
        {
            s8_Bracket ++;
        }
        else if(u8_TestChar == ')')
        {
            s8_Bracket --;
        }
    }

    if(s8_Curly ==0 && s8_Bracket ==0)
    {
        return "Balanced Parentheses\n";
    }
    else
    {
        return "Unbalanced Parentheses\n";
    }
}


int main(void)
{
    /*
    Test cases
    */
   uint8_t u8test_arr[30];
   printf("First Test case : { 1+( 2/5 )+2 }\n\n");
   printf("%s\n", balancedParentheses("{ 1+( 2/5 )+2 }"));
   printf("Second Test case : (2*3 + ( 5/2 + ( 4*3 )))\n\n");
   printf("%s\n", balancedParentheses("(2*3 + ( 5/2 + ( 4*3 )))"));
   printf("Third Test case : { ( { 2+10 } }*11 }\n\n");
   printf("%s\n", balancedParentheses("{ ( { 2+10 } }*11 }"));
   printf("Test case : ");

   scanf("%s",&u8test_arr);
   printf("%s\n", balancedParentheses(u8test_arr));


  }
