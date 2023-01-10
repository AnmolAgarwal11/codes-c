#include<stdio.h>
#include<malloc.h>
struct node
{
 int coeff;
 int power;
 struct node *next;
};

struct node *start1=NULL;

struct node *create_poly(struct node *start)
{

  struct node *new_node,*ptr;
  int c,p;
  printf("Enter the coefficient : ");
  scanf("%d",&c);
  printf("Enter the power : ");
  scanf("%d",&p);

while(p !=-1)
{
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->coeff=c;
    new_node->power=p;
    new_node->next=NULL;

  if(start==NULL)
  {
      start=new_node;
      ptr=start;
  }

else
  {
      ptr->next=new_node;
      ptr=new_node;
  }

  printf("Enter the coefficient : ");
  scanf("%d",&c);
  printf("Enter the power : ");
  scanf("%d",&p);
}
return start;
}

struct node *display_poly(struct node *start)
{
  struct node *ptr;
  ptr=start;

  while(ptr != NULL)
  {

    printf("%d x^%d \t",ptr->coeff,ptr->power);
    ptr=ptr->next;
  }
  return start;
}



int main()
{

 printf("Enter the first polynomial : \n");
 start1=create_poly(start1);
 printf("Display the first polynomial : \n");
 start1=display_poly(start1);

 return 0;
}