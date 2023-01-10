#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;

void push(int num)
{
    struct stack *ptr;
    ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->data=num;
    if(top==NULL)
    {
        ptr->next=NULL;
        top=ptr;
    }
    else
    {
        ptr->next=top;
        top=ptr;
    }
}
int pop()
{
    int x=-1;
    struct stack *ptr=top;
    if(top==NULL)
    printf("Stack underflow!\n");
    else
    {
        x=ptr->data;
        top=ptr->next;
    }
    free(ptr);
    return x;
}
void display()
{
    struct stack *ptr=top;
    printf("Elements of the stack are : ");
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    printf("Element popped is : %d\n",pop());
    push(4);
    push(5);
    display();

    return 0;
}