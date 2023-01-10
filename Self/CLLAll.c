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

void insertbegin()
{
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        printf("Enter the number to be inserted : ");
        struct node *new=(struct node *)malloc(sizeof(struct node));
        scanf("%d" ,&new->data);
        new->next=head;
        head=new;
        tail->next=head;
    }
}

void insertend()
{
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        printf("Enter the number to be inserted : ");
        struct node *new=(struct node *)malloc(sizeof(struct node));
        scanf("%d" ,&new->data);
        new->next=head;
        tail->next=new;
        tail=new;
    }
}

void deletebegin()
{
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else if(head->next==head)
    {
        free(head);
        printf("Last node has been deleted\nLinked list is now empty!\n");
    }
    else
    {
        struct node *ptr=head;
        head=head->next;
        tail->next=head;
        free(ptr);
    }
}

void deletend()
{
    if(head==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else if(head->next==head)
    {
        free(head);
        printf("Last node has been deleted\nLinked list is now empty!\n");
    }
    else
    {
        struct node *ptr=head;
        while(ptr->next!=tail)
        ptr=ptr->next;

        free(ptr->next);
        ptr->next=head;
        tail=ptr;
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
    int opt;
    printf("******Main Menu******\n");
    printf("1)Create a circular linked list\n");
    printf("2)Insert a new node in begining\n");
    printf("3)Insert a new node at end\n");
    printf("4)Delete the first node\n");
    printf("5)Delete the last node\n");
    printf("6)Display the linked list\n");
    printf("7)Exit\n");

    while(1)
    {
        printf("Enter option : ");
        scanf("%d" ,&opt);
        switch (opt)
        {
            case 1:
            createCLL(); 
            break;

            case 2:
            insertbegin();
            break;

            case 3:
            insertend();
            break;    

            case 4:
            deletebegin();
            break;

            case 5:
            deletend();
            break;

            case 6:
            print();
            break;

            case 7:
            return 0;
            break;

            default:
            printf("Invalid option!\n");
            break;
        }
    }
}