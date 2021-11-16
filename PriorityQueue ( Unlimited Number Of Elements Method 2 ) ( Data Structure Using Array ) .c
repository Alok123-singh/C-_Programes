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
	int *arr=NULL,x,y;
	int i,j,k,l;
	
	arr=(int *)malloc(size*sizeof(int));
	
	for(i=0;i<size;i++)
	    *(arr+i)=0;
	
	printf("Do You Want To Initialise Array? Enter 1 For Yes And 0 For No :\n");
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
	    pq->size=40;
	
	pq->q=(int *)malloc(pq->size*sizeof(int));
	pq->rear=-1;
	
	if(*arr!=0)
	{
		int max;
		
		for(k=0;k<size;k++)
		{
			max=INT_MIN;
			for(l=0;l<size;l++)
			{
				if(*(arr+l)>max && *(arr+l)!=-1)
				{
					max=*(arr+l);
					y=l;
				}
			}
			
            *(pq->q+k)=max;
            pq->rear++;
            *(arr+y)=-1;
		}
	}
}

void Display(struct PriorityQueue pq)
{
	int i;
	
	printf("\n------------------------------------------------------------------------------------------------\n\n");
	printf("Size Of The Priority Queue Is : %d\n\n",pq.rear+1);
	
	printf("Priority Queue Is As Follows : ");
	for(i=0;i<=pq.rear;i++)
        printf("%d ",*(pq.q+i));
	
	printf("\n\n------------------------------------------------------------------------------------------------\n");
}

void Insert(struct PriorityQueue *pq,int x)
{
	int i,index=-1,j;
	
	if(pq->rear==pq->size-1)
	{
		printf("\nElement Can Not Be Inserted Because Priority Queue Is Full\n");
	    return;
	}
	
	for(i=0;i<=pq->rear;i++)
    {
    	if(x>*(pq->q+i))
    	{
    		index=i;
    		break;
		}
	}
	
	if(index==-1)
		index=pq->rear+1;
	
	else 
	{
	    for(j=pq->rear;j>=index;j--)
	        *(pq->q+j+1)=*(pq->q+j);
    }
    
	*(pq->q+index)=x;
	pq->rear++;
}

int Delete(struct PriorityQueue *pq)
{
	int x=-1;
	
	if(pq->rear==-1)
		printf("\nElement Can Not Be Deleted Because Priority Queue Is Empty\n");
	
	else
	{
		x=*(pq->q+pq->rear);
		pq->rear--;
	}
	
	return(x);
}

int Front(struct PriorityQueue pq)
{
	if(pq.rear==-1)
	{
	    printf("\nPriority Queue Is Empty\n");
		return(-1);
    }
    
	return(*pq.q);
}

int Rear(struct PriorityQueue pq)
{
	if(pq.rear==-1)
	{
	    printf("\nPriority Queue Is Empty\n");
		return(-1);
    }
    
    return(*(pq.q+pq.rear));
}

int main()
{
	struct PriorityQueue pq;
	
	create(&pq,4);
	
	Insert(&pq,15);
	Insert(&pq,27);
	Insert(&pq,39);
	Insert(&pq,50);
	Insert(&pq,60);
	
	Display(pq);
	
	printf("\nDeleted Element Is As Follows : %d\n",Delete(&pq));
	
	Display(pq);
	
	return(0);
}

