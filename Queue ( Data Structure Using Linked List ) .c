#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <conio.h>

struct Node 
{
    int data;
	struct Node *next;	
};

struct Queue
{
    int size;
	struct Node *front;
	struct Node *rear;	
};

void create(struct Queue *q,int size)
{
	int i;
	struct Node *temp=NULL;
	
	q->size=size;
	
	if(q->size==0)
	{
		q->front=q->rear=NULL;
		return;
	}
	
	printf("\nEnter Information About The Elements Of Queue :\n");
	q->front=(struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter 1 Element :\n");
	scanf("%d",&q->front->data);
	q->front->next=NULL;
	q->rear=q->front;
	
	for(i=1;i<q->size;i++)
    {
    	printf("\nEnter %d Element :\n",i+1);
    	temp=(struct Node *)malloc(sizeof(struct Node));
    	temp->next=NULL;
    	scanf("%d",&temp->data);
        q->rear->next=temp;
    	q->rear=temp;
	}
}

void Enqueue(struct Queue *q,int x)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	if(temp==NULL)
	{
		printf("\nQueue Overfull\n");
		return;
	}
	
	else
	{
		temp->data=x;
		temp->next=NULL;
		if(q->front==NULL)
		    q->front=q->rear=temp;
		    
		else
		{
			q->rear->next=temp;
			q->rear=temp;
		}
		q->size++;	
	}
}

int Dequeue(struct Queue *q)
{
	int x=0;
	struct Node *p=NULL;
	
	if(q->front==NULL)
	    printf("\nQueue Underflow\n");
	
	else
	{
		p=q->front;
		q->front=q->front->next;
		x=p->data;
		free(p);
		q->size--;
	}
	
	return(x);
}

bool isEmpty(struct Queue q)
{
	if(q.front==NULL)
	    return(true);
	    
	return(false);
}

bool isFull(struct Queue q)
{
    struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
	    return(true);
	    
	return(false);
}

void Display(struct Queue q)
{
	struct Node *p=NULL;
	
	printf("\n---------------------------------------------------------\n\n");
	printf("Size Of The Queue Is : %d\n\n",q.size);
	
	p=q.front;
	printf("Queue Is As Follows : ");
	
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	
	printf("\n\n---------------------------------------------------------\n");
}

int First(struct Queue q)
{
	if(q.front==NULL)
	    return(-1);
	    
	return(q.front->data);
}

int Last(struct Queue q)
{
	return(q.rear->data);
}

int main()
{
	struct Queue q1;
	
	create(&q1,0); 
	
	Enqueue(&q1,10);
	Enqueue(&q1,20);
	Enqueue(&q1,30);
	Enqueue(&q1,40);
	Enqueue(&q1,50);
	
	Display(q1);
	
	return(0);
}
