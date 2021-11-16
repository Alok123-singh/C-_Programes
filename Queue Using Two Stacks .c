#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Stack
{
    int size;
	struct Node *front;
	struct Node *rear;
};

void create(struct Stack *st)
{
	struct Node *temp=NULL;
	int i;
	
	printf("Enter Size Of The Stack :\n");
	scanf("%d",&st->size);
	
	if(st->size==0)
	{
		st->front=st->rear=NULL;
		return;
	}
	
	st->front=(struct Node *)malloc(sizeof(struct Node));
	
	printf("\nEnter Information About Elements Of Stack :\n");
	printf("\nEnter 1 Element :\n");
	scanf("%d",&st->front->data);
	st->front->next=st->front->prev=NULL;
	st->rear=st->front;
	
	for(i=1;i<st->size;i++)
	{
	    temp=(struct Node *)malloc(sizeof(struct Node));
	    printf("\nEnter %d Element :\n",i+1);
	    scanf("%d",&temp->data);
	    temp->next=st->rear->next;
	    temp->prev=st->rear;
	    st->rear->next=temp;
	    st->rear=temp;
	}
}

void I(struct Stack *st,int size)
{
    struct Node	*temp=NULL;
    
    st->size=size;
    if(size==0)
    	st->front=st->rear=NULL;
	
	else
	{
		int i;
		
		st->front=(struct Node *)malloc(sizeof(struct Node));
	    st->front->data=0;
	    st->front->next=st->front->prev=NULL;
	    st->rear=st->front;
	    
	    for(i=1;i<size;i++)
	    {
	    	temp=(struct Node *)malloc(sizeof(struct Node));
	    	temp->data=0;
	    	temp->next=st->rear->next;
	    	temp->prev=st->rear;
	    	st->rear->next=temp;
	    	st->rear=temp;
		}
	}
}

void Display(struct Stack st)
{
	struct Node *p=st.front;
	
	printf("\n---------------------------------------------------------------\n\n");
	printf("Size Of The Stack Is As Follows : %d\n\n",st.size);
	
	printf("Stack Is As Follows : ");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}

	printf("\n\n---------------------------------------------------------------\n");
}

void Push(struct Stack *st,int x)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	if(temp==NULL)
	{
		printf("\nStack Overflow\n");
	    return;
	}
	
	temp->data=x;
	temp->next=temp->prev=NULL;
	if(st->front==NULL && st->rear==NULL)
		st->front=st->rear=temp;
	
	else
	{
		st->rear->next=temp;
		temp->prev=st->rear;
	    st->rear=temp;
	}
	
	st->size++;
}

int Pop(struct Stack *st)
{
	int x=0,i;
	struct Node *p=st->front;
	
	if(st->front==NULL)
	    printf("\nStack Underflow\n");
	
	else
	{
		if(st->front==st->rear)
		{
			st->front=st->rear=NULL;
			x=p->data;
			free(p);
		}
		
		else
		{
			for(i=1;i<st->size;i++)
				p=p->next;
			
			st->rear=st->rear->prev;
			st->rear->next=NULL;
			x=p->data;
			free(p);
		}
		st->size--;
	}
	
	return(x);
}

int Peek(struct Stack st,int pos)
{
	int x=0,i;
	struct Node *p=NULL;
	
	if(pos<0 || pos>st.size)
		printf("\nPosition Is Invalid\n");
	
	else
	{
		p=st.front;
		for(i=1;i<st.size;i++)
		    p=p->next;
		    
		x=p->data;
	}
	
	return(x);
}

bool isEmpty(struct Stack st)
{
	if(st.front==NULL)
	    return(true);
	    
	return(false);
}

bool isFull(struct Stack st)
{
	struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
	    return(true);
	    
	return(false);
}

struct Queue
{
    struct Stack st1;
	struct Stack st2; 	
};

void createQueue(struct Queue *qu)
{
	printf("Enter The Information About Stack 1 Of Queue :\n\n");
	create(&qu->st1);
	
	I(&qu->st2,0);
}

void DisplayQueue(struct Queue qu)
{
	int sz=0;
	struct Node *p=NULL,*q=NULL;
	
	p=qu.st1.front;
	q=qu.st2.rear;
	
	while(p!=NULL || q!=NULL)
	{
      	if(p!=NULL)
      	{ 
		    sz++;
		    p=p->next;
        }
        
      	if(p==NULL && q!=NULL)
      	{   
		    sz++;
		    q=q->prev;
        }
    }
    
	p=qu.st1.front;
	q=qu.st2.rear;
	
	printf("\n---------------------------------------------------------------\n\n");
	printf("Size Of The Queue Is : %d",sz);
	
	printf("\n\nQueue Is As Follows :\n");
	while(p!=NULL || q!=NULL)
	{
		if(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->prev;
		}
		
		if(q==NULL && p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
	}
	
	printf("\n\n---------------------------------------------------------------\n");
}

void Enqueue(struct Queue *qu,int x)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	if(temp==NULL)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	
	temp->data=x;
	temp->next=qu->st1.rear->next;
	temp->prev=qu->st1.rear;
	qu->st1.rear->next=temp;
	qu->st1.rear=temp;
}

int Dequeue(struct Queue *qu)
{
	int x=0;
	struct Node *p=NULL;
	
	if(qu->st1.front==NULL && qu->st2.rear==NULL)
	    printf("\nQueue Underflow\n");
	    
	else
	{
		if(qu->st2.rear!=NULL)
		{
			x=qu->st2.rear->data;
		    qu->st2.rear=qu->st2.rear->prev;
			free(qu->st2.rear->next);
			qu->st2.rear->next=NULL;    
		}
		
		else
		{
			p=qu->st1.rear;

			while(p!=NULL)
			{
				Push(&qu->st2,p->data);
				p=p->prev;
			}
			
			free(qu->st1.front);
			qu->st1.front=qu->st1.rear=NULL;
			qu->st1.size=0;
		    
		    x=Pop(&qu->st2);
		}
	}
	
	return(x);
}

bool isEmptyQueue(struct Queue qu)
{
	if(qu.st1.front==NULL && qu.st2.rear==NULL)
	    return(true);
	    
	return(false);
}

bool isFullQueue(struct Queue qu)
{
	struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
	    return(true);
	    
	return(false);
}

int main()
{
	struct Queue qu1;
	
	createQueue(&qu1);
	
	Enqueue(&qu1,72);
	
	printf("\n\nFirst Deleted Element Is : %d\n",Dequeue(&qu1));
	printf("Second Deleted Element Is : %d\n\n",Dequeue(&qu1));
	
	DisplayQueue(qu1);
	
	return(0);
}
