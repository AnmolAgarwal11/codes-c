#include<stdio.h>
#define size 5
typedef struct Cqueue
{
	int que[size];
	int f,r;
}queue;


void insert(queue *p,int item) //enqueue
{
	// write the code here.
	if((p->f==0 && p->r==size-1) || ( p->f==p->r+1))
		printf("Queue is full\n");
	else
	{
		if(p->r==size-1)
			p->r=0;
		else
			p->r++;
		if(p->f==-1)
			++p->f;
		p->que[p->r]=item;
	}	
	
}
void del(queue *p)//dequeue
{
	if(p->f==-1)
		printf("Queue is empty.");
	else
	{
		printf("Deleted item =%d\n\n",p->que[p->f]);
		if(p->f==p->r)	
			p->f=p->r=-1;
		else if(p->f==size-1)
			p->f=0;
		else
			++p->f;
	}	
}

void print(queue *p)
{
	int i;
	if(p->f==-1)
		printf("Queue is empty");
	else if(p->f > p->r)
	{
	
		for(i=p->f;i<=size-1;i++)
			printf("%d ",p->que[i]);
		for(i=0;i<=p->r;i++)
			printf("%d ",p->que[i]);
	}
	else
		for(i=p->f;i<=p->r;i++)
			printf("%d ",p->que[i]);
}



void main()
{
	queue q;
	q.f=q.r=-1;
	insert(&q,5);
	insert(&q,6);
	insert(&q,7);
	printf("\nThe elements in q are:");
	print(&q);
	insert(&q,8);

	printf("\nThe elements in q are:");
	print(&q);
	insert(&q,9);
	printf("\nThe elements in q are:");
	print(&q);
	
	insert(&q,10);
	
	del(&q);
	del(&q);
	del(&q);
	
	printf("\nThe elements in q are:");
	print(&q);
	
	
	insert(&q,10);
	insert(&q,11);
	
	printf("\nThe elements in q are:");
	print(&q);
	
}
