#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter the size of stack : ");
    scanf("%d",&st->size);
    //st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
    printf("Stack overflow!\n");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }   
}
int pop(struct stack *st)
{
    int x=-1;

    if(st->top==-1)
    printf("Stack underflow!\n");
    else
    {
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct stack st,int pos)
{
    int x=-1,index=st.top-pos+1;
    if(index<0)
    printf("Invalid position!\n");
    else
    x=st.s[index];
    return x;
}
void display(struct stack st)
{
    if(st.top==-1)
    printf("Stack is empty!\n");
    else
    {
        printf("The stack entered is : ");
        for(int i=st.top;i>=0;i--)
        {
            printf("%d\t",st.s[i]);
        }
        printf("\n");
    }
}
void isEmpty(struct stack st)
{
    if(st.top==-1)
    printf("Stack is empty!\n");
    else
    printf("Stack is not empty!\n");
}
void isFull(struct stack st)
{
    if(st.top==st.size-1)
    printf("Stack is full!\n");
    else
    printf("Stack is not full!\n");
}
int main()
{
    struct stack st;
    st.top=-1;
    int choice,num;
    printf("****MENU****\n");
    printf("1.Create\n");
    printf("2.Push\n");
    printf("3.Pop\n");
    printf("4.Peek\n");
    printf("5.IsEmpty\n");
    printf("6.IsFull\n");
    printf("7.Display\n");
    printf("Enter -1 to exit\n");
    while(1)
    {
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            create(&st);
            break;

            case 2:
            printf("Enter the number to be pushed : ");
            scanf("%d",&num);
            push(&st,num);
            break;

            case 3:
            printf("The number popped is : %d\n",pop(&st));
            break;

            case 4:
            printf("Enter the position : ");
            scanf("%d",&num);
            printf("The number at position is : %d\n",peek(st,num));
            break;

            case 5:
            isEmpty(st);
            break;

            case 6:
            isFull(st);
            break;

            case 7:
            display(st);
            break;

            case -1:
            return 0;

            default:
            printf("Invalid choice!\n");
            break;
        }
    }

}