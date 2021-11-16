#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
    int data;
	struct Node *next;	
};

struct Stack
{
    struct Node *first;
	struct Node *last;
	int size;	
};

void IStack(struct Stack *stk)
{
    stk->size=0;
    stk->first=stk->last=NULL;
}

void Push(struct Stack *stk,int key)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=key;
	temp->next=NULL;
	
	if(temp==NULL)
		printf("\nStack Overflow\n");
	else
	{
		if(stk->first==NULL)
			stk->first=stk->last=temp;
		else
		{
            stk->last->next=temp;
            stk->last=temp;
	    }
		stk->size++;			
	}
}

int Pop(struct Stack *stk)
{
	int x=-1;
	struct Node *p=stk->first,*q=stk->last;
	
	if(p==NULL)
	    printf("\nStack Underflow\n");
	else
	{
		x=q->data;
		if(p==q)
		{
			stk->first=stk->last=NULL;
			free(q);
		}
		else
		{
			while(p->next!=q)
			    p=p->next;
			stk->last=p;
			p->next=NULL;
			free(q);
		}
		stk->size--;
	}
	return(x);
}

bool isEmptyStack(struct Stack stk)
{
	if(stk.first==NULL)
	    return(true);
	return(false);
}

bool isFullStack(struct Stack stk)
{
	struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
	    return(true);
	return(false);
}

struct Queue
{
	struct Node *first;
	int size;
};

void IQueue(struct Queue *q)
{
	q->first=NULL;
	q->size=0;
}

void Enqueue(struct Queue *q,int key)
{
	struct Node *temp=NULL,*p=q->first;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=key;
	temp->next=NULL;
	
	if(temp==NULL)
		printf("\nQueue Overflow\n");
	else
	{
		if(q->first==NULL)
			q->first=temp;
		else
		{
			while(p->next)
			    p=p->next;
			p->next=temp;
		}
		q->size++;
	}
}

int Dequeue(struct Queue *q)
{
	int x=-1;
	struct Node *p=q->first;
	
	if(p==NULL)
	    printf("\nQueue Underflow\n");
	else
	{
		x=p->data;
		if(q->first->next==NULL)
		{
			q->first=NULL;
			free(p);
		}
		else
		{
			q->first=q->first->next;
			p->next=NULL;
			free(p);
		}
		q->size--;
	}
    return(x);
}

bool isEmptyQueue(struct Queue q)
{
	if(q.first==NULL)
	    return(true);
	return(false);
}

bool isFullQueue(struct Queue q)
{
	struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
	    return(true);
	return(false);
}

void CreateGraph(int **G,int *n,int *e)
{
	int size,i;
	int temp,j,k;
	int s;
	
	printf("\nEnter Total Number Of Vertices :\n");
	scanf("%d",n);
	printf("\nEnter Total Number Of Edges :\n");
	scanf("%d",e);
	
	size=*n+2*(*e)+1+1;
	
	*G=(int *)malloc(size*sizeof(int));
	for(s=0;s<size;s++)
	    *(*G+s)=-1;
	
	i=1;
	j=*n+2;
	*(*G+*n+1)=size;
	while(i<=*n)
	{
		k=1;
		printf("\nEnter The Vertices Connected To %d :\n",i);
		printf("\nEnter %d Vertex :\n",k);
		scanf("%d",&temp);
		*(*G+i)=j;
		if(temp!=-1)    
			*(*G+j)=temp;
		while(temp!=-1 && j<size)
		{
			k++;
			j++;
			printf("\nEnter %d Vertex :\n",k);
		    scanf("%d",&temp);
		    if(temp!=-1)
		        *(*G+j)=temp;
		}
		i++;
	}
}

int Outdegree(int G[],int v)
{
	int count=0,i;
	
	for(i=*(G+v);i<*(G+v+1);i++)
	    count++;
	return(count);
}

int Indegree(int G[],int n,int v)
{
	int count=0,j;
	
	for(j=n+2;j<*(G+n+1);j++)
	{
		if(*(G+j)==v)
		    count++;
	}
	return(count);
}

bool SelfLoop(int G[],int v)
{
	int j;
	
	for(j=*(G+v);j<*(G+v+1);j++)
	{
		if(*(G+v)==v)
		    return(true);
	}
	return(false);
}

void BFS(int Gr[],int n,int v) // Breadth First Search
{
	int u,v1;
	int visited[n],i;
	struct Queue Q;
	
	for(i=0;i<n;i++)
	    visited[i]=0;
	
	IQueue(&Q);
	
	Enqueue(&Q,v);
	printf("\nBreadth First Search Is As Follows : ");
	printf("%d  ",v);
	visited[v-1]=1;
	while(!isEmptyQueue(Q))
	{
		u=Dequeue(&Q);
		for(v1=*(Gr+u);v1<*(Gr+u+1);v1++)
		{
			if(visited[*(Gr+v1)-1]==0)
			{
				printf("%d  ",*(Gr+v1));
				Enqueue(&Q,*(Gr+v1));
				visited[*(Gr+v1)-1]=1;
			}
		}
	}
	printf("\n");
}

void DFS(int Gr[],int n,int v) // Depth First Search
{
	int v1,x,i,j;
	int visited[n];
	struct Stack stk;
	
	for(i=0;i<n;i++)
	    visited[i]=0;
	
	IStack(&stk);
	
	Push(&stk,v);
    printf("\nDepth First Search Is As Follows : ");
    printf("%d  ",v);
    visited[v-1]=1;
	while(!isEmptyStack(stk))
	{
		x=-1;
		v1=Pop(&stk);
		
		for(j=*(Gr+v1);j<*(Gr+v1+1);j++)
		{
			if(visited[*(Gr+j)-1]==0)
			{
				x=*(Gr+j);
				break;
			}
		}
		
		if(x!=-1)
		{
			printf("%d  ",x);
			Push(&stk,v1);
			Push(&stk,x);
			visited[x-1]=1;
		}
	}
	printf("\n");
}

void Dispaly(int G[],int n,int e)
{
	int i,j=n+2;
	
	printf("\n-----------------------------------------------------------------------------\n\n");
	printf("Total Number Of Vertices Are : %d\n",n);
	printf("Total Number Of Edges Are : %d\n",e);
	printf("\nNon Directional Graph Using Compact List Method Is As Follows :\n");
	for(i=1;i<=n;i++)
	{
		printf("\nVertices Connected To %d Are : ",i);
		while(j<*(G+i+1))
		{
			if(*(G+j)!=-1)    
				printf("%d  ",*(G+j));
			j++;
		}
		printf("\n");
	}
	printf("\n-----------------------------------------------------------------------------\n");
}

int main()
{
	int *G=NULL,n,e;
	
	CreateGraph(&G,&n,&e);
	
	Dispaly(G,n,e);
	
	return(0);
}
