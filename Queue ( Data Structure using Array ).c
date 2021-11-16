#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct Queue 
{
	int front;
	int rear;
	int size;
	int *q;	
};

void create(struct Queue *q1)
{
	int i;
	
	printf("Enter Size Of The Queue :\n");
	scanf("%d",&q1->size);
	
	q1->q=(int *)malloc(q1->size*sizeof(int));
	q1->front=q1->rear=-1;
	
	printf("Enter Information About Element Of Queue :\n");
	for(i=0;i<q1->size;i++)
	{
		printf("\nEnter %d Element :\n",i+1);
		q1->rear++;
		scanf("%d",q1->q+q1->rear);
	}
}

void I(struct Queue *q1,int size)
{
    int i;
	
	q1->size=size;
    q1->front=q1->rear=-1;
    q1->q=(int *)malloc(q1->size*sizeof(int));
    
    for(i=0;i<q1->size;i++)
        *(q1->q+i)=0;
}

void Enqueue(struct Queue *q1,int x)
{
	if(q1->rear==q1->size-1)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	
    else
    {
    	q1->rear++;
    	*(q1->q+q1->rear)=x;
	}
}

int Dequeue(struct Queue *q1)
{
	int x=-1;
	
	if(q1->front==q1->rear)
		printf("\nQueue Underflow\n");
	
	else
	{
		x=*(q1->q+q1->front);
		*(q1->q+q1->front)=0;
		q1->front++;
	}
	
	return(x);
}

void Display(struct Queue q1)
{
	int i;
	
	printf("\n---------------------------------------------------\n\n");
	printf("Size Of The Stack Is : %d \n\n",q1.rear-q1.front);
	printf("Queue Is As Follows :\n");
	
	for(i=q1.front+1;i<=q1.rear;i++)
		printf("%d ",*(q1.q+i));
	
	printf("\n\n---------------------------------------------------\n");
}

int Front(struct Queue q1)
{
	if(q1.front==-1)
	    return(-1);
	
	return(*(q1.q+q1.front));
}

int Rear(struct Queue q1)
{
	return(*(q1.q+q1.rear));
}

bool isEmpty(struct Queue q1)
{
	if(q1.front==q1.rear)
	    return true;
	    
	return(false);
}

bool isFull(struct Queue q1)
{
	if(q1.rear=q1.size-1)
	    return(true);
	    
	return(false);
}

int main()
{
	struct Queue q1;
	
	I(&q1,5);
	
	Enqueue(&q1,12);
	Enqueue(&q1,24);
	Enqueue(&q1,36);
	Enqueue(&q1,48);
	Enqueue(&q1,60);
	
	Dequeue(&q1);

    Display(q1);
	
	return(0);
}


