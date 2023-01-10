#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;

void createCLL()
{
    int num;
    printf("Enter data, enter -1 to end : ");
    scanf("%d" ,&num);

    while(num!=-1)
    {
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=num;
        new->next=NULL;

        if(head==NULL)
        {
            head=new;
            tail=new;
            new->next=head;
        }
        else
        {
            tail->next=new;
            tail=new;
            tail->next=head;
        }
        printf("Enter data : ");
        scanf("%d" ,&num);
    }
}

void print()
{
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        printf("Lined list to be displayed is : \n");
        struct node *ptr=head;
        do
        {
            printf("%d\t" ,ptr->data);
            ptr=ptr->next;
        } while (ptr!=head);
    }
    printf("\n");
}

int main()
{
    createCLL();
    print();

    return 0;
}