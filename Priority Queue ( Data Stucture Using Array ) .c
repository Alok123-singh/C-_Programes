#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <string.h>

struct Queue
{
    int size;
	int front;
	int rear;
	int prio;
	char *q;	
};

struct PriorityQueue
{
    struct Queue *q1;
    struct Queue *q2;
    struct Queue *q3;
};

bool isEmpty(struct Queue *);
bool isFull(struct Queue *);

int prioch(char ch)
{
	if((ch>=65 && ch<72) || (ch>=97 && ch<104))
	    return(1);
	    
	else if((ch>=72 && ch<80) || (ch>=104 && ch<112))
	    return(2);
	    
	else if((ch>=80 && ch<=90) || (ch>=112 && ch<=122))
	    return(3);
}

void create(struct PriorityQueue *pq,char ch[])
{
	int i,j,x,len;
	
	for(i=0;i<40;i++)
	    *(ch+i)=48;
	
	printf("Do You Want To Initialize String? Enter 1 For Yes And 0 For No:\n");
	scanf("%d",&x); fflush(stdin);
	
	if(x==1)
	{
	    printf("\nEnter Expression :\n");
	    scanf("%s",ch);
	    len=3*strlen(ch);
    }
    
    else if(x==0)
        len=50;
    
    pq->q1=(struct Queue *)malloc(sizeof(struct Queue));
    pq->q2=(struct Queue *)malloc(sizeof(struct Queue));
    pq->q3=(struct Queue *)malloc(sizeof(struct Queue));
    
    pq->q1->front=pq->q1->rear=0; pq->q1->prio=1;
	pq->q2->front=pq->q2->rear=0; pq->q2->prio=2;
	pq->q3->front=pq->q3->rear=0; pq->q3->prio=3;
	
    pq->q1->size=len;
    pq->q1->q=(char *)malloc(pq->q1->size*sizeof(char));
    
    pq->q2->size=len;
    pq->q2->q=(char *)malloc(pq->q2->size*sizeof(char));
    
    pq->q3->size=len;
    pq->q3->q=(char *)malloc(pq->q3->size*sizeof(char));
    
    
    if(*ch!=48)
    {
    	for(j=0;*(ch+j)!='\0';j++)
    	{
		    if(!isFull(pq->q1) && prioch(*(ch+j))==pq->q1->prio)
		    {
		    	pq->q1->rear=(pq->q1->rear+1)%pq->q1->size;
		    	*(pq->q1->q+pq->q1->rear)=*(ch+j);
			}
			
			else if(!isFull(pq->q2) && prioch(*(ch+j))==pq->q2->prio)
			{
				pq->q2->rear=(pq->q2->rear+1)%pq->q2->size;
				*(pq->q2->q+pq->q2->rear)=*(ch+j);
			}
			
			else if(!isFull(pq->q3) && prioch(*(ch+j))==pq->q3->prio)
			{
				pq->q3->rear=(pq->q3->rear+1)%pq->q3->size;
				*(pq->q3->q+pq->q3->rear)=*(ch+j);
			}
        }
	}
}

void Display(struct PriorityQueue pq)
{
	int sz1,sz2,sz3;
	int i=(pq.q1->front+1)%pq.q1->size,j=(pq.q2->front+1)%pq.q2->size,k=(pq.q3->front+1)%pq.q3->size;
	
	printf("\n------------------------------------------------------------------------------------------------\n\n");
	
	if(pq.q1->rear>pq.q1->front)
	    sz1=pq.q1->rear-pq.q1->front;
	    
	else if(pq.q1->rear<pq.q1->front)
	    sz1=pq.q1->size=pq.q1->front+pq.q1->rear;
	    
	if(pq.q2->rear>pq.q2->front)
	    sz2=pq.q2->rear-pq.q2->front;
	    
	else if(pq.q2->rear<pq.q2->front)
	    sz2=pq.q2->size=pq.q2->front+pq.q2->rear;
	
	if(pq.q3->rear>pq.q3->front)
	    sz3=pq.q3->rear-pq.q3->front;
	    
	else if(pq.q3->rear<pq.q3->front)
	    sz3=pq.q3->size=pq.q3->front+pq.q3->rear;
	
	if(pq.q1->front==pq.q1->rear)
	    printf("Size Of Queue Of Priority 1 Is : 0\n\n");
	    
	else
	    printf("Size Of Queue Of Priority 1 Is : %d\n\n",sz1);
	    
	if(pq.q2->front==pq.q2->rear)
	    printf("Size Of Queue Of Priority 2 Is : 0\n\n");
	    
	else
	    printf("Size Of Queue Of Priority 2 Is : %d\n\n",sz2);
	
	if(pq.q3->front==pq.q3->rear)
	    printf("Size Of Queue Of Priority 3 Is : 0\n\n");
	    
	else
	    printf("Size Of Queue Of Priority 3 Is : %d\n\n",sz3);
	
	printf("Queue Priority 1 Is As Follows : ");
	while(i!=(pq.q1->rear+1)%pq.q1->size)
	{
		printf("%c ",*(pq.q1->q+i));
		i=(i+1)%pq.q1->size;
	}
	
	printf("\n\nQueue Priority 2 Is As Follows : ");
    while(j!=(pq.q2->rear+1)%pq.q2->size)
	{
		printf("%c ",*(pq.q2->q+j));
		j=(j+1)%pq.q2->size;
	}
	
	printf("\n\nQueue Priority 3 Is As Follows : ");
	while(k!=(pq.q3->rear+1)%pq.q3->size)
	{
		printf("%c ",*(pq.q3->q+k));
		k=(k+1)%pq.q3->size;
	}
	
	printf("\n\n------------------------------------------------------------------------------------------------\n");
}

bool isEmpty(struct Queue *qu)
{
	if(qu->front==qu->rear)
	    return(true);
	    
	return(false);
}

bool isFull(struct Queue *qu)
{
	if((qu->rear+1)%qu->size==qu->front)
	    return(true);
	    
	return(false);
}

void Insert(struct PriorityQueue *pq,char ch)
{
    if(prioch(ch)==pq->q1->prio)
	{
	    if(isFull(pq->q1))
		{    
			printf("\nElement Can Not Be Inserted Because Queue Of Priority 1 Is Full\n");	
            return;
		}
		
		else
		{
		    pq->q1->rear=(pq->q1->rear+1)%pq->q1->size;
			*(pq->q1->q+pq->q1->rear)=ch;	
		}
	}	
	
	else if(prioch(ch)==pq->q2->prio)
	{
		if(isFull(pq->q2))
		{
			printf("\nElement Can Not Be Inserted Because Queue Of Priority 2 Is Full\n");	
            return;
		}
		
		else
		{
			pq->q2->rear=(pq->q2->rear+1)%pq->q2->size;
			*(pq->q2->q+pq->q2->rear)=ch;
		}
	}
	
	else if(prioch(ch)==pq->q3->prio)
	{
		if(isFull(pq->q3))
		{
			printf("\nElement Can Not Be Inserted Because Queue Of Priority 3 Is Full\n");	
            return;
		}
		
		else
		{
			pq->q3->rear=(pq->q3->rear+1)%pq->q3->size;
			*(pq->q3->q+pq->q3->rear)=ch;
		}
	}
}

int Delete(struct PriorityQueue *pq)
{
	int x=48,i;
	
	if(!isEmpty(pq->q1))
	{
		pq->q1->front=(pq->q1->front+1)%pq->q1->size;
		x=*(pq->q1->q+pq->q1->front);
	}
	
	else if(!isEmpty(pq->q2))
	{
		pq->q2->front=(pq->q2->front+1)%pq->q2->size;
		x=*(pq->q2->q+pq->q2->front);
	}
	
	else if(!isEmpty(pq->q3))
	{
		pq->q3->front=(pq->q2->front+1)%pq->q3->size;
		x=*(pq->q3->q+pq->q3->front);
	}
	
	else
	    printf("\nElement Can Not Be Deleted Because Priority Queue Is Empty\n");
	
	return(x);
}

int main()
{
	char ch[50];
	struct PriorityQueue pq;
	
	create(&pq,ch);
	
	Insert(&pq,'A');
	Insert(&pq,'N');
	Insert(&pq,'A');
	Insert(&pq,'N');
	Insert(&pq,'D');
	Insert(&pq,'P');
	Insert(&pq,'R');
	Insert(&pq,'A');
	Insert(&pq,'T');
	Insert(&pq,'A');
	Insert(&pq,'P');
	Insert(&pq,'S');
	Insert(&pq,'I');
	Insert(&pq,'N');
	Insert(&pq,'G');
	Insert(&pq,'H');
	
	
	Display(pq);
	
	printf("\nDeleted Element Is : %c\n",Delete(&pq));
	printf("\nDeleted Element Is : %c\n",Delete(&pq));
	printf("\nDeleted Element Is : %c\n",Delete(&pq));
	
	Display(pq);
	
	return(0);
}



