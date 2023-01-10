#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head=NULL;

void createDLL()
{
    int num;
    printf("Enter data ,enter -1 to terminate : ");
    scanf("%d" ,&num);
    struct node *ptr=head;

    while(num!=-1)
    {
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->prev=NULL;
        new->data=num;
        new->next=NULL;
        
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else
        {
            ptr->next=new;
            new->prev=ptr;
            ptr=ptr->next;
        }
        printf("Enter data : ");
        scanf("%d" ,&num);
    }
}

void display()
{
    if(head==NULL)
    {
        printf("Linked list is empty \n");
    }
    else
    {
        struct node *ptr=head;
        printf("Linked list to be displayed is \n");
        while(ptr!=NULL)
        {
            printf("%d \t" ,ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    createDLL();
    display();

    return 0;  
}