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

void insertbegin()
{
    if(head==NULL)
    {
        printf("Linked list is empty \nCreate a linked list first\n");
    }
    else
    {
        struct node *ptr=head,*new=(struct node *)malloc(sizeof(struct node));
        new->prev=NULL;
        printf("Enter the number to be inserted : ");
        scanf("%d" ,&new->data);
        new->next=ptr;
        ptr->prev=new;
        head=new;
    }
}

void insertend()
{
    if(head==NULL)
    {
        printf("Linked list is empty \nCreate a linked list first\n");
    }
    else
    {
        struct node *ptr=head,*new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the number to be inserted : ");
        scanf("%d" ,&new->data);
        new->prev=NULL;
        new->next=NULL;

        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
        new->prev=ptr;
    }
}

void insertpos()
{
    if(head==NULL)
    {
        printf("Linked list is empty \nCreate a linked list first\n");
    }
    else
    {
        struct node *ptr2,*ptr=head,*new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the number and it's position to be inserted at : ");
        int pos;
        scanf("%d%d" ,&new->data,&pos);
        new->prev=NULL;
        new->next=NULL;

        if(pos==1)
        {
            new->next=ptr;
            ptr->prev=new;
            head=new;
        }
        else
        {
            while(pos!=1)
            {
                ptr=ptr->next;
                pos--;
            }
            ptr2=ptr->next;

            ptr->next=new;
            ptr2->prev=new;
            new->prev=ptr;
            new->next=ptr2;
        }
    }
}

void insertbefore()
{
    if(head==NULL)
    {
        printf("Linked list is empty \nCreate a linked list first\n");
    }
    else
    {
        struct node *ptr2,*ptr=head,*new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the number and it's position to be inserted at : ");
        int pos;
        scanf("%d%d" ,&new->data,&pos);
        new->prev=NULL;
        new->next=NULL;

        if(pos==1)
        {
            new->next=ptr;
            ptr->prev=new;
            head=new;
        }
        else
        {
            while(pos>2)
            {
                ptr=ptr->next;
                pos--;
            }
            ptr2=ptr->next;

            ptr->next=new;
            ptr2->prev=new;
            new->prev=ptr;
            new->next=ptr2;
        }
    }
}

void deletebegin()
{
    if(head==NULL)
    {
        printf("Linked list is already empty \n");
    }
    else
    {
        head=head->next;
        free(head->prev);
        head->prev=NULL;
    }
}

void deletend()
{
    if(head==NULL)
    {
        printf("Linked list is empty \n");
    }
    else if(head->next==NULL)
    {
        printf("Last node has been deleted\nLinked list is empty \n");
        free(head);
        head=NULL;
    }
    else
    {
        struct node *ptr=head;
        while(ptr->next!=NULL)
        ptr=ptr->next;

        ptr->prev->next=NULL;
        free(ptr);
        ptr=NULL;
    }
}

void deletepos()
{
    if(head==NULL)
    {
        printf("Linked list is empty \n");
    }
    else
    {
        struct node *ptr2,*ptr=head;
        int pos;
        printf("Enter the position to delete : ");
        scanf("%d" ,&pos);

        if(pos==1)
        {
            head=head->next;
            free(head->prev);
            head->prev=NULL;
        }
        else
        {
            while(pos>2)
            {
                ptr=ptr->next;
                pos--;
            }
            ptr2=ptr->next;
            ptr->next=ptr2->next;
            if(ptr2->next==NULL)
            ptr->next=NULL;
            else
            ptr2->next->prev=ptr;
            free(ptr2);
        }
    }
}

void deleteall()
{
    struct node *ptr=head;

    while(head!=NULL)
    {
        ptr=ptr->next;
        free(head);
        head=ptr;
    }
}

void reverse()
{
    struct node *ptr1=head,*ptr2=ptr1->next;
    
    ptr1->next=NULL;
    ptr1->prev=ptr2;

    while(ptr2!=NULL)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
}

void count()
{
    if(head==NULL)
    {
        printf("Linked list is empty \n");
    }
    else
    {
        struct node *ptr=head;
        int count=0;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        printf("Size of the linked list is : %d\n" ,count);
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
        printf("Linked list to be displayed is :\n");
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
    int opt;
    printf("*****MAIN MENU******\n");
    printf("1) Create linked list\n");
    printf("2) Insert at start\n");
    printf("3) Insert at end\n");
    printf("4) Insert at position\n");
    printf("5) Insert before position\n");
    printf("6) Delete at start\n");
    printf("7) Delete at end\n");
    printf("8) Delete at position\n");
    printf("9) Delete all\n");
    printf("10) Reverse linked list\n");
    printf("11) Count elements of linked list\n");
    printf("12) Display linked list\n");
    printf("13) Exit\n");

    while(1)
    {
        printf("Enter the option : ");
        scanf("%d" ,&opt);
        switch(opt)
        {
            case 1:
            createDLL();
            break;

            case 2:
            insertbegin();
            break;

            case 3:
            insertend();
            break;

            case 4:
            insertpos();
            break;

            case 5:
            insertbefore();
            break;

            case 6:
            deletebegin();
            break;

            case 7:
            deletend();
            break;
            
            case 8:
            deletepos();
            break;

            case 9:
            deleteall();
            break;

            case 10:
            reverse();
            break;

            case 11:
            count();
            break;

            case 12:
            display();
            break;

            case 13:
            return 0;

            default:
            printf("Invalid option\n");
        }
    }
}