#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void createll(struct node *ptr)
{
    int n;
    printf("Enter -1 to stop\nEnter the data : ");
    scanf("%d",&n);
    while(n!=-1)
    {
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
    
        if(head==NULL)
        {
            ptr=head=new;
        }
        else
        {
            ptr->next=new;
            ptr=new;
        }
        printf("Enter the data: ");
        scanf("%d",&n);
    }
}

void print(struct node *p)
{
    printf("Linked list to be displayed is : \n");
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

int main()
{
    createll(head);
    print(head);
    return 0;
}