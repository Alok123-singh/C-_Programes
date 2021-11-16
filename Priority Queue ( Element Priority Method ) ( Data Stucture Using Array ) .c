#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

struct PriorityQueue
{
    int rear;
	int size;
	int *q;	
};

void create(struct PriorityQueue *pq,int size)
{
    int *arr=NULL,x;
	int i,j,k;
	
	arr=(int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	    *(arr+i)=-1;
	
	printf("Do You Want To Initialise Array? Enter 1 For Yes and 0 For No :\n");
	scanf("%d",&x);
	
	if(x==1)
	{	
		for(j=0;j<size;j++)
		{
			printf("\nEnter %d Element :\n",j+1);
			scanf("%d",arr+j);
		}
		
		pq->size=3*size;
	}
	
	else if(x==0)
	    pq->size=50;
	    
	pq->rear=-1;
	pq->q=(int *)malloc(pq->size*sizeof(int));
	
	if(*arr!=-1)
	{
		for(k=0;k<size;k++)
		{
		   ++pq->rear;
		   *(pq->q+pq->rear)=*(arr+k);
	    }
	}
}

void Display(struct PriorityQueue pq)
{
	int i;
	
	printf("\n------------------------------------------------------------------------------------------------\n\n");
	printf("Size Of The Pririty Queue Is : %d\n\n",pq.rear+1);
	
	printf("Pririty Queue Is As Follows : ");
	for(i=0;i<=pq.rear;i++)
	    printf("%d ",*(pq.q+i));
	
	printf("\n\n------------------------------------------------------------------------------------------------\n");
}

void Insert(struct PriorityQueue *pq,int x)
{
	if(pq->rear==pq->size-1)
	    printf("\nElement Can Not Be Inserted Because Priority Queue Is Full\n");
	    
	else
	{
		pq->rear++;
		*(pq->q+pq->rear)=x;
	}
}

int Delete(struct PriorityQueue *pq)
{
	int x=-1,maxprio=INT_MAX;
	int i,j,y;
	
	if(pq->rear==-1)
	    printf("\nElement Can Not Be Deleted Because Priority Queue Is Empty\n");
	    
	else
	{
		for(i=0;i<=pq->rear;i++)
		{
			if(*(pq->q+i)<maxprio)
			{
			    y=i;
			    maxprio=*(pq->q+i);
			}
		}
		
		x=*(pq->q+y);
		
		for(j=y;j<pq->rear;j++)
		    *(pq->q+j)=*(pq->q+j+1); 
		
		*(pq->q+pq->rear)=-1;    
		--pq->rear;
	}
	
	return(x);
}

int Front(struct PriorityQueue pq)
{
	if(pq.rear=-1)
	    return(-1);
	    
	return(*(pq.q));
}

int Rear(struct PriorityQueue pq)
{
	if(pq.rear==-1)
	    return(-1);
	    
	return(*(pq.q+pq.rear));
}

bool isEmpty(struct PriorityQueue pq)
{
	if(pq.rear==-1)
	    return(true);
	    
	return false;
}

bool isFull(struct PriorityQueue pq)
{
	if(pq.rear==pq.size-1)
	    return(true);
	    
	return (false);
}

int main()
{
	struct PriorityQueue pq;
	
	create(&pq,3);
	
	Insert(&pq,48);
	Insert(&pq,60);
	Insert(&pq,72);
	
	Display(pq);
	
	printf("\nThe Deleted Element Is : %d\n",Delete(&pq));
	
	Display(pq);
	
	return(0);
}


