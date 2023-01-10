#include <stdio.h> 
#include <stdlib.h> 
typedef struct Node
{ 
    float value; 
    int expo; 
    struct Node * next; 
}
 Node;
void CreateSLL(Node *head,Node *end)
{ 
    Node * ele, 
    * prev = NULL; 
    int t1, t2=0; 
    while(t2 != -1)
    { 
        scanf("%d %d",&t1,&t2);
        ele = (Node *) malloc(sizeof(Node));
        ele->value = t1; 
        ele->expo = (t2 == -1 ? 0 : t2 ); 
        ele->next = NULL; 
        if(head == NULL)
        { 
            head = ele; 
        }
        if(prev != NULL)
        { 
            prev->next = ele; 
        }
        prev = ele; 
    }
    end = ele; 
}
void Display(Node * head)
{ 
    Node * curr = head; 
    while(curr != NULL)
    { 
        printf("%f",curr->value); 
        if(curr->expo != 0)
        { 
            printf("x^%d + ",curr->expo); 
        }curr = curr->next; 
    }printf("\n") ; 
}
Node * AddLL(Node * head1, Node * head2)
{ 
    Node * head = NULL, *curr, *curr1 = head1 , *curr2 = head2, *prev = NULL; 
    while(curr1 != NULL && curr2 != NULL)
    { 
        curr = (Node *) malloc(sizeof(Node)); 
        if(curr1->expo > curr2->expo)
        { 
            curr->value = curr1->value; 
            curr->expo = curr1->expo; 
            curr->next = NULL; 
            curr1 = curr1->next; 
        }
        else if(curr2->expo > curr1->expo)
        { 
            curr->value = curr2->value; 
            curr->expo = curr2->expo; 
            curr->next = NULL; 
            curr2 = curr2->next; 
        }
        else
        {
            curr->value = curr1->value + curr2->value;
            curr->expo = curr2->expo; curr->next = NULL;
            curr1 = curr1->next;
            curr2 = curr2->next;
            }
            if(head == NULL)
            {
                head = curr; 
            }
            if(prev != NULL)
            { 
                prev->next = curr; 
            }
            prev = curr; 
        }
        while(curr1 != NULL)
        { 
            curr = (Node *) malloc(sizeof(Node));
            curr->value = curr1->value; 
            curr->expo = curr1->expo; 
            curr->next = NULL; 
            if(head == NULL)
            { 
                head = curr; 
            }
            if(prev != NULL)
            { 
                prev->next = curr; 
            }
            prev = curr; curr1 = curr1->next; 
        }
        while(curr2 != NULL)
        { 
            curr = (Node *) malloc(sizeof(Node)); 
            curr->value = curr2->value; 
            curr->expo = curr2->expo; 
            curr->next = NULL; 
            if(head == NULL)
            { 
                head = curr; 
            }
            if(prev != NULL)
            { 
                prev->next = curr; 
            }
            prev = curr; curr2 = curr2->next; 
        }
        return head; 
    }
Node * SubLL(Node * head1, Node * head2)
{ 
    Node * head = NULL, *curr, *curr1 = head1 , *curr2 = head2, *prev = NULL; 
    while(curr1 != NULL && curr2 != NULL)
    { 
        curr = (Node *) malloc(sizeof(Node)); 
        if(curr1->expo > curr2->expo)
        { 
            curr->value = curr1->value; 
            curr->expo = curr1->expo; 
            curr->next = NULL; 
            curr1 = curr1->next; 
        }
        else if(curr2->expo > curr1->expo)
        { 
            curr->value = -curr2->value; 
            curr->expo = curr2->expo; 
            curr->next = NULL; 
            curr2 = curr2->next; 
        }
        else
        {
            curr->value = curr1->value - curr2->value; 
            curr->expo = curr2->expo; 
            curr->next = NULL; 
            curr1 = curr1->next; 
            curr2 = curr2->next; 
            if(curr->value == 0)
            { 
                continue; 
            } 
        }
        if(head == NULL)
        { 
            head = curr; 
        }
        if(prev != NULL)
        { 
            prev->next = curr; 
        }
        prev = curr; 
    }
    while(curr1 != NULL)
    { 
        curr = (Node *) malloc(sizeof(Node));
        curr->value = curr1->value; 
        curr->expo = curr1->expo; 
        curr->next = NULL; 
        if(head == NULL)
        { 
            head = curr;
        }
        if(prev != NULL)
        { 
            prev->next = curr; 
        }
        prev = curr; 
        curr1 = curr1->next; 
    }
    while(curr2 != NULL)
    { 
        curr = (Node *) malloc(sizeof(Node)); 
        curr->value = -curr2->value; 
        curr->expo = curr2->expo; 
        curr->next = NULL; 
        if(curr->value == 0)
        { 
            continue; 
        }
        if(head == NULL)
        { 
            head = curr; 
        }
        if(prev != NULL)
        { 
            prev->next = curr; 
        }
        prev = curr;
        curr2 = curr2->next;
    }
    return head; 
}
Node * MultiplyLL(Node * head1, Node * head2)
{ 
    Node * head = NULL, *curr, *curr1 = head1 , *curr2 = head2, *prev = NULL, *temp, *prev_arr = NULL; 
    if(curr2 != NULL)
    { 
        if(curr2->value > curr1->value)
        { 
            temp = curr1; 
            curr1 = curr2; 
            curr2 = temp; 
        } 
    }
    while(curr1 != NULL)
    { 
        temp = curr2;
        while(curr2 != NULL)
        { 
            curr = (Node *) malloc(sizeof(Node)); 
            curr->value = curr1->value * curr2->value; 
            curr->expo = curr1->expo + curr2->expo; 
            if(head == NULL)
            { 
                head = curr; 
            }
            if(prev != NULL)
            { 
                prev->next = curr; 
            }
            curr2 = curr2->next; 
            prev = curr;
        }
        prev_arr = AddLL(prev_arr,head); 
        head = NULL;
        prev = NULL;
        curr2 = temp; 
        curr1 = curr1->next; 
    }
    return prev_arr; 
}
Node * DivideLL(Node * head1 , Node * head2)
{ 
    Node * divident = head1 , * divisor = head2, * head =NULL, *ele, *ele2, *t_head2, *t_p2; 
    while(divident != NULL)
    { 
        if(divisor->expo > divident->expo)
        { 
            break; 
        }
        else
        {
            ele = (Node *) malloc(sizeof(Node)); 
            ele->value = (float)divident->value / divisor->value;
            ele->expo = divident->expo - divisor->expo; 
            ele->next = NULL; 
            head = AddLL(head,ele); 
            t_head2 = MultiplyLL(ele,divisor); 
            t_p2 = SubLL(divident,t_head2); divident = t_p2; 
        } 
    }
    return head; 
}
int main()
{ 
    Node * head1 =NULL, * head2 = NULL , * end1, * end2, *ans; 
    CreateSLL(head1,end1); 
    printf("First Polynomial : "); 
    Display(head1); 
    CreateSLL(head2,end2); 
    printf("Second Polynomial : "); 
    Display(head2); 
    printf("Sum of both Polys : "); 
    ans = AddLL(head1,head2);
    Display(ans); 
    ans = MultiplyLL(head1,head2); 
    printf("Mult of both Polys : "); 
    Display(ans); 
    ans = DivideLL(head1,head2); 
    printf("Division : "); 
    Display(ans); 
}