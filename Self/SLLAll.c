#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

void createll()
{
    int n;
    printf("Enter -1 to stop\nEnter the data : ");
    scanf("%d",&n);
    while(n!=-1)
    {
        struct node *ptr,*new=(struct node *)malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
    
        if(head==NULL)
        {
            head=new;
            ptr=head;
        }
        else
        {
            ptr->next=new;
            ptr=new;
        }
        printf("Enter the data : ");
        scanf("%d",&n);
    }
}

void insertbegin()
{
    if(head==NULL)
    printf("Create a Link list first\n");
    else
    {
        struct node *new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the number to be inserted : ");
        scanf("%d",&new->data);
        new->next=head;
        head=new;
    }
}

void insertend()
{
    if(head==NULL)
    {
        printf("Create a Link list first \n");
    }
    else
    {
        struct node *ptr=head,*new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the number to be inserted : ");
        scanf("%d",&new->data);
        new->next=NULL;

        while(ptr->next!=NULL)
        ptr=ptr->next;

        ptr->next=new;

    }
}

void insertpos()
{
    if(head==NULL)
    printf("Create a Link list first\n");
    else
    {
        struct node *ptr=head;
        int n,pos;
        printf("Enter the number and the position : ");
        scanf("%d %d" ,&n,&pos);
        struct node *new=(struct node *)malloc(sizeof(struct node));
        new->data=n;
        for(int i=0;i<pos-2;i++)
        {
            ptr=ptr->next;
        }
        new->next=ptr->next;
        ptr->next=new;
    }
}

void deletebegin()
{
    if(head==NULL)
    printf("Link list is already empty \n");
    else
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}

void deletend()
{
    if(head==NULL)
    printf("Link list is already empty \n");
    else if(head->next==NULL)
    {
        printf("Last node has been deleted\nLink list is now empty \n");
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    } 
}

void deletepos()
{
    if(head==NULL)
    printf("Link list is already empty \n");
    else
    {
        struct node *ptr2,*ptr=head;
        int pos;
        printf("Enter the position : ");
        scanf("%d" ,&pos);
        if(pos==1)
        {
            struct node *temp=head;
            head=head->next;
            free(temp);
            temp=NULL;
        }
        else
        {
            while(pos!=2)
            {
                ptr=ptr->next;
                pos--;
            }
            ptr2=ptr->next;
            ptr->next=ptr2->next;
            free(ptr2);
        }
    }
}

void deleteall()
{
    struct node *temp=head;

    while(head!=NULL)
    {
        temp=temp->next;
        free(head);
        head=temp;
    }
}

void reverse()
{
    struct node *ptr=head,*ptr2=NULL,*ptr3=NULL;
    while(ptr!=NULL)
    {
        ptr2=ptr3;
        ptr3=ptr;
        ptr=ptr->next;
        ptr3->next=ptr2;
    }
    head=ptr3;
}

void count()
{
    if(head==NULL)
    {
        printf("Linked list is empty \n");
    }
    else
    {
        int count=0;
        struct node *ptr=head;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        printf("Size of the linked list is : %d\n" ,count);
    }
}

void print()
{
    if(head==NULL)
    {
        printf("Linked list is empty \n");
    }
    else
    {
        struct node *ptr=head;
        printf("Linked list to be displayed is : \n");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void removeNthFromEnd(int n) {
    int count = 0;
    struct node* ptr2, * ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d",count);
    int pos = count - n + 1;
    struct node* ptr3 = head;
    if(pos == 1)
    { 
        struct node* temp = head;
        temp->next = NULL;
        head = head->next;
        free(temp);
    }
    while(pos!=2)
    {
        ptr3 = ptr3->next;
    }
    ptr2 = ptr3->next;
    ptr3->next = ptr2->next;
    free(ptr3);
}

int main()
{
    int opt;
    printf("*****MAIN MENU******\n");
    printf("1) Create linked list\n");
    printf("2) Insert at start\n");
    printf("3) Insert at end\n");
    printf("4) Insert at position\n");
    printf("5) Delete at start\n");
    printf("6) Delete at end\n");
    printf("7) Delete at position\n");
    printf("8) Delete all\n");
    printf("9) Reverse linked list\n");
    printf("10) Count elements of linked list\n");
    printf("11) Display linked list\n");
    printf("12) Exit\n");

    while(1)
    {
        printf("Enter the option : ");
        scanf("%d" ,&opt);
        switch(opt)
        {
            case 1:
            createll();
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
            deletebegin();
            break;

            case 6:
            deletend();
            break;
            
            case 7:
            deletepos();
            break;

            case 8:
            deleteall();
            break;

            case 9:
            reverse();
            break;

            case 10:
            count();
            break;

            case 11:
            print();
            break;

            case 12:
            return 0;

            case 13:
            removeNthFromEnd(2);
            break;

            default:
            printf("Invalid option\n");
        }
    }
}