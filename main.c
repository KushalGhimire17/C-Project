//Build a stack using c
/*
    Principle:
        [LIFO] Last In First Out
    Operations:
        push()          : insert data in the stack from top.
        pop()           : remove data in the stack from top.
        peek()          : returns the top data in the stack.
        display()       : displays all data in the stack.
        is_empty()      : returns true if stack is empty.
        is_full()       : returns true if stack is full.
*/
#include <stdio.h>
#define SIZE 5

//stack
int stack[SIZE];
int top = -1; //empty stack

//function declaration
void push(int);
int is_full();
int is_empty();
void display();
void pop();

void menu()
{
    printf("\nEnter \n1 for Push \n2 for Pop \n3 for Peek \n4 for Display \n5 for Exit: ");
}

int main()
{
    int choice, data;

    do
    {
        menu();
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            if(!is_full())
            {
                printf("\nEnter data: ");
                scanf("%d", &data);
                push(data);
                printf("\nData inserted on the stack");
            }
            else
            {
                printf("\n Stack Overflow");
            }
            break;

        case 2:
            pop();
            break;
        case 3:
            if(!is_empty())
            {
                printf("\nThe topmost data is %d", stack[top]);
            }
            else
            {
                printf("\nStack is empty");
            }
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nLeaving from the system...");
            break;
        default:
            printf("\nInvalid Choice");

        }

    }while(choice != 5);

    return 0;
}

int is_full()
{
    if(top == SIZE-1)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    top++;
    stack[top] = data;

}

void display()
{
    int i;
    if(is_empty())
    {
        printf("\nStack Is Empty");
    }
    else
    {
        for(i=0; i<=top; i++)
        {
            printf("\n%d", stack[i]);
        }
    }
}

void pop()
{
    if(is_empty())
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("\n%d is popped from the stack.", stack[top]);
        top--;
    }
}
