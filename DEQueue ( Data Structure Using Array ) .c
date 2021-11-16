#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

struct DEQueue
{
    int front;
	int rear;
	int size;
	int *q;	
};

void create(struct DEQueue *dq,int size)
{
	int i;
	
	dq->front=dq->rear=-1;
	
	dq->q=(int *)malloc(dq->size*sizeof(int));
    
	for(i=0;i<size;i++)
        *(dq->q+i)=0;
}

void InsertFront(struct DEQueue *dq,int x)
{
	if(dq->front==-1)
		printf("\nElement Can Not Be Inserted From Front\n");
	
	else
	{
		*(dq->q+dq->front)=x;
		--dq->front;
	}
}

int DeleteFront(struct DEQueue *dq)
{
	int x=0;
	
	if(dq->front==dq->rear)
	    printf("\nElement Can Not Be Deleted From Front\n");
	    
	else
	{
	    dq->front++;
		x=*(dq->q+dq->front);
	}
	
	return(x); 
}

void InsertRear(struct DEQueue *dq,int x)
{
	if(dq->rear==dq->size-1)
	    printf("\nElement Can Not Be Inserted From Rear\n");
	    
	else
	{
	    dq->rear++;
		*(dq->q+dq->rear)=x;	
	}    
}

int DeleteRear(struct DEQueue *dq)
{
	int x=0;
	
	if(dq->rear==dq->front)
	    printf("\nElement Can Not Be Deleted From Rear\n");
	
	else 
	{
		x=*(dq->q+dq->rear);
		dq->rear--;
	}
	
	return(x);
}

bool isEmpty(struct DEQueue dq)
{
	if(dq.front==dq.rear)
	    return(true);
	    
	return(false);
}

bool isFull(struct DEQueue dq)
{
	if(dq.front==-1 && dq.rear==dq.size-1)
	    return(true);
	    
	return(false);
}

int Front(struct DEQueue dq)
{
	if(dq.front==dq.size-1)
	    return(0);
	    
	return(*(dq.q+dq.front+1));
}

int Rear(struct DEQueue dq)
{
	if(dq.rear==-1)
	    return(0);
	    
	return(*(dq.q+dq.rear));
}

void Display(struct DEQueue dq)
{
	int i;
	
	printf("\n-------------------------------------------------------\n\n");
	if(dq.front==dq.rear)
	    printf("Size Of The DEQueue Is : 0\n\n");
	else
	    printf("Size Of The DEQueue Is : %d\n\n",dq.rear-dq.front);
	
	printf("DEQueue Is As Follows : ");
	
	
	
	for(i=dq.front+1;i<=dq.rear;i++)
	    printf("%d ",*(dq.q+i));
	
	printf("\n\n-------------------------------------------------------\n");
}

int main()
{
	struct DEQueue dq;
	
	create(&dq,5);
	
	InsertRear(&dq,12);
	InsertRear(&dq,24);
	DeleteFront(&dq);
	InsertFront(&dq,12);
	
	Display(dq);
	
	return(0);
}

