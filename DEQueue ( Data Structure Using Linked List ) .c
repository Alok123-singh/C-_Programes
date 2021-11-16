#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <conio.h>

struct Node 
{
	int data;
	struct Node *next;
};

struct DEQueue
{
    struct Node *front;	
    struct Node *rear;
    int size;
};

void create(struct DEQueue *dq,int size)
{
	
	int i;
	struct Node *temp=NULL,*p=NULL;
	
	if(size==0)
	{
		dq->front=dq->rear=NULL;
		return;
	}
	
	dq->size=size;
	dq->front=(struct Node *)malloc(sizeof(struct Node));
	
	printf("Enter The Information Of Elements Of DEQueue :\n\n");
	printf("Enter 1 Element :\n");
	scanf("%d",&dq->front->data);
	dq->front->next=NULL;
	dq->rear=dq->front;
	
	for(i=1;i<size;i++)
	{
		temp=(struct Node *)malloc(sizeof(struct Node));
		
		printf("\nEnter %d Element :\n",i+1);
		scanf("%d",&temp->data);
		temp->next=dq->rear->next;
		dq->rear->next=temp;
		dq->rear=temp;
	}
}

int CountNodes(struct Node *p)
{
	int count=0;
	
	while(p)
	{
		count++;
		p=p->next;
	}
	
	return(count);
}

void Display(struct DEQueue dq)
{	
	struct Node *p=NULL;
	
	printf("\n------------------------------------------------------------------\n\n");
    printf("Size Of The DEQueue Is : %d\n\n",CountNodes(dq.front));
    
    p=dq.front;
    printf("DEQueue Is AS Follows : ");
    
	while(p)
    {
    	printf("%d ",p->data);
    	p=p->next;
	}
	
    printf("\n-------------------------------------------------------------------\n\n");
}

void InsertFront(struct DEQueue *dq,int x)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	if(temp==NULL)
	{
		printf("\nElement Can Not Be Inserted From Front\n");
		return;
	}
	
	else if(dq->front!=NULL && dq->rear!=NULL && dq->front==dq->rear)
	{
		temp->data=x;
		temp->next=dq->front;
		dq->front=temp;
	}
	
	else
	{
		temp->data=x;
		temp->next=dq->front;
		dq->front=temp;
		
		if(dq->rear==NULL)
		    dq->rear=temp;
	}
}

int DeleteFront(struct DEQueue *dq)
{
    int x=0;
	struct Node *p=NULL;
	
	if(dq->front==NULL)
	    printf("\nElement Can Not Be Deleted From Front\n");	
	
	else if(dq->front==dq->rear)
	{
		p=dq->front;
		dq->front=dq->rear=NULL;
		x=p->data;
		free(p);
	}
	
	else
	{
		p=dq->front;
		x=p->data;
		dq->front=dq->front->next;
		free(p);
	}
	
	return(x);
}

void InsertRear(struct DEQueue *dq,int x)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	if(temp==NULL)
	{
		printf("\nElement Can Not Be Inserted From Rear\n");
		return;
	}
	
	else if(dq->front==NULL && dq->rear==NULL && dq->front==dq->rear)
	{
		temp->data=x;
		temp->next=dq->front;
		dq->front=dq->rear=temp;
	}
	
	else
	{
		temp->data=x;
		temp->next=NULL;
		dq->rear->next=temp;
		
	}
}

int DeleteRear(struct DEQueue *dq)
{
	int x=0;
	struct Node *p=NULL,*q=NULL;
	
	if(dq->rear==NULL)
	    printf("\nElement Can Not Be Deleted From Rear\n");
	
	else if(dq->rear==dq->front && dq->rear!=NULL && dq->front!=NULL)
	{
		p=dq->rear;
		dq->rear=dq->front=NULL;
		x=p->data;
		free(p);
	}
	
	else
	{
		q=dq->front;
		while(q!=dq->rear)
		{
	        p=q;
	        q=q->next;
	    }
	    
		dq->rear=p;
		dq->rear->next=NULL;
		p=q;
		q=NULL;
		x=p->data;
		free(p);
	}
	
	return(x);
}

bool ifEmpty(struct DEQueue dq)
{
	if(dq.front==NULL & dq.rear==NULL)
	    return(true);
	
	return(false);
}

bool isFull(struct DEQueue dq)
{
	struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	if(test==NULL)
	    return(true);
	    
	return (false);	
}

int Front(struct DEQueue dq)
{
	if(dq.front==NULL)
	    return(0);
	    
	return(dq.front->data);
}

int Rear(struct DEQueue dq)
{
	if(dq.rear==NULL)
	    return(0);
	    
	return(dq.rear->data);
}

int main()
{
	struct DEQueue dq;
	create(&dq,0);
	
	InsertRear(&dq,12);
	InsertFront(&dq,6);
	
	DeleteRear(&dq);
	
	Display(dq);
	
	return(0);
}
