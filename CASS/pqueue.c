#include<stdio.h>
#define size 5 
struct Queue
{
	int item;
	int pri;
};
typedef struct pqueue
{
	struct Queue q[size];
	int f,r;
}queue;


void insert(queue *p,int num,int pr)
{
	if(p->r==size-1)
		printf("Queue is full.");
	else
	{
		p->q[++p->r].item=num;
		p->q[p->r].pri=pr;
		if(p->f==-1)
			++p->f;
	}
}




void disp(queue *p)
{
	int i;
	if(p->f==-1)
		printf("Queue is empty.");
	else
	{
		for(i=p->f;i<=p->r;i++)
			printf("%d %d\n",p->q[i].item,p->q[i].pri);
	}
}
void del(queue *p)
{
	int pos,i,small;
	if(p->f==-1)
		printf("Queue is empty.");
	else
	{
		small=p->q[p->f].pri;
		pos=p->f;
		for(i=p->f+1;i<=p->r;i++)
		{
			if(p->q[i].pri < small)
			{
				pos=i;
				small=p->q[i].pri;
			}
		}
		printf("Deleted item=%d",p->q[pos].item);
		if(p->f==p->r) //single element
			p->f=p->r=-1;
		else if(pos==p->f)
			++p->f;
		else if(pos==p->r)
			--p->r;
		else
		{
			for(i=pos;i<p->r;i++)
			{
				p->q[i].item=p->q[i+1].item;
				p->q[i].pri=p->q[i+1].pri;
			}
			--p->r;
		}
	}
}
void main()
{
	queue que;
	int choice,num,pr;
	que.f=que.r=-1;
	do
	{
		printf("\n1.Insert");
		printf("\n2.del");
		printf("\n3.disp");
		printf("\n4.exit");
		printf("\nEnter ur choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an item & its priority.");                       
					 scanf("%d %d",&num,&pr);
					 insert(&que,num,pr);break;
			case 2:del(&que);break;
			case 3:disp(&que);break;
			case 4:break;
			default:printf("\nWrong choice.");                              
		}
	}while(choice!=4);
	printf("\nProgram end.");
}//main() end








