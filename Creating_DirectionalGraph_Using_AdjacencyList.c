#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Graph
{
	int n;
	int e;
	struct Node **G;
};

struct Stack
{
	int last;
	int size;
	int *s;
};

void IStack(struct Stack *stk,int size)
{
	int i;
	
	stk->size=size;
	stk->last=-1;
	stk->s=(int *)malloc(size*sizeof(int));
    for(i=0;i<size;i++)
        *(stk->s+i)=-1;
}

void Push(struct Stack *stk,int key)
{
	if(stk->last==stk->size-1)
	    printf("\nStack Overflow\n");
	else
	{
		stk->last++;
		*(stk->s+stk->last)=key;
	}
}

int Pop(struct Stack *stk)
{
	int x=-1;
	
	if(stk->last==-1)
	    printf("\nStack Underflow\n");
	else
	{
		x=*(stk->s+stk->last);
		*(stk->s+stk->last)=-1;
		stk->last--;
	}
	return(x);
}

bool isEmptyStack(struct Stack stk)
{
	if(stk.last==-1)
	    return(true);
	return(false);
}

bool isFullStack(struct Stack stk)
{
	if(stk.last==stk.size-1)
	    return(true);
	return(false);
}

struct Queue
{
	int front;
	int rear;
	int size;
	int *q;
};

void IQueue(struct Queue *Q,int size)
{
	int i;
	
	Q->front=Q->rear=-1;
	Q->size=size;
	Q->q=(int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	    *(Q->q+i)=-1;
}

void Enqueue(struct Queue *Q,int key)
{
	if((Q->rear+1)%Q->size==Q->front)
	    printf("\nQueue Overflow\n");
	else
	{
		Q->rear=(Q->rear+1)%Q->size;
		*(Q->q+Q->rear)=key;
	}
}

int Dequeue(struct Queue *Q)
{
	int x=-1;
	
	if(Q->front==Q->rear)
	    printf("\nQueue Underflow\n");
	else
	{
		Q->front=(Q->front+1)%Q->size;
		x=*(Q->q+Q->front);
		*(Q->q+Q->front)=-1;
	}
	return(x);
}

bool isEmptyQueue(struct Queue Q)
{
	if(Q.front==Q.rear)
	    return(true);
	return(false);
}

bool isFullQueue(struct Queue Q)
{
	if((Q.rear+1)%Q.size==Q.front)
	    return(true);
	return(false);
}

void IGraph(struct Graph *Gr)
{
	Gr->G=NULL;
	Gr->e=Gr->n=0;
}

void CreateGraph(struct Graph *Gr)
{
	int i,j,k;
	struct Node *p=NULL,*temp=NULL;
	
	printf("\nEnter Total Number Of Vertices :\n");
	scanf("%d",&Gr->n);
	printf("\nEnter Total Number Of Edges :\n");
	scanf("%d",&Gr->e);
	
	Gr->G=(struct Node **)malloc((Gr->n+1)*sizeof(struct Node *));
	for(k=0;k<=Gr->n;k++)
	    *(Gr->G+k)=NULL;
	
	for(i=1;i<=Gr->n;i++)
	{
		j=1;
		printf("\nEnter Vertices Connected To %d :\n",i);
		p=*(Gr->G+i);
		temp=(struct Node *)malloc(sizeof(struct Node));
		printf("\nEnter %d Vertex :\n",j);
		scanf("%d",&temp->data);
		temp->next=NULL;
		p=*(Gr->G+i);
		while(temp->data!=-1)
		{
			if(p==NULL)
			{
	        	*(Gr->G+i)=temp;
	        	p=temp;
			}
			else
			{
				j++;
				temp=(struct Node *)malloc(sizeof(struct Node));
				printf("\nEnter %d Vertex :\n",j);
				scanf("%d",&temp->data);
				temp->next=NULL;
				if(temp->data!=-1)
				{
				    p->next=temp;
				    p=temp;
		        }
			}
			
		}
	}
}

int Indegree(struct Graph Gr,int v)
{
	int i,count=0;
	struct Node *p=NULL;
	
	for(i=1;i<=Gr.n;i++)
	{
		p=*(Gr.G+i);
		while(p)
		{
		    if(p->data==v)
		        count++;
		    p=p->next;
	    }
	}
	return(count);
}

int Outdegree(struct Graph Gr,int v)
{
	int count=0;
	struct Node *p=NULL;
	
	p=*(Gr.G+v);
	while(p)
	{
		if(p->data!=v)
		    count++;
		p=p->next;
	}
	
	return(count);
}

bool SelfLoop(struct Graph Gr,int v)
{
	struct Node *p=*(Gr.G+v);
	
	while(p)
	{
		if(p->data==v)
		    return(true);
	}
	return(false);
}

void BFS(struct Graph Gr,int v) // Breadth First Search
{
	int u;
	int visited[Gr.n],i;
	struct Queue Q;
	struct Node *p;
	
	for(i=0;i<Gr.n;i++)
	    visited[i]=0;
	
	IQueue(&Q,Gr.n+1);
	
	Enqueue(&Q,v);
	printf("\nBreadth First Search Is As Follows : ");
	printf("%d  ",v);
	visited[v-1]=1;
	while(!isEmptyQueue(Q))
	{
		u=Dequeue(&Q);
		p=*(Gr.G+u);
		while(p)
		{
			if(visited[p->data-1]==0)
			{
				printf("%d  ",p->data);
				Enqueue(&Q,p->data);
				visited[p->data-1]=1;
			}
			p=p->next;
		}
	}
	printf("\n");
}

void DFS(struct Graph Gr,int v) // Depth First Search
{
	int v1,x;
	int visited[Gr.n],i;
	struct Stack stk;
	struct Node *p=NULL;
	
	for(i=0;i<Gr.n;i++)
	    visited[i]=0;
	
	IStack(&stk,Gr.n);
	
	Push(&stk,v);
	printf("\nDepth First Search Is As Follows : ");
	printf("%d  ",v);
	visited[v-1]=1;
	while(!isEmptyStack(stk))
	{
        x=-1;
		v1=Pop(&stk);
        p=*(Gr.G+v1);
        
		while(p)
        {
        	if(visited[p->data-1]==0)
        	{
        		x=p->data;
        		break;
			}
			p=p->next;
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

void Display(struct Graph Gr)
{
	int i;
	struct Node *p=NULL;
	
	printf("\n-----------------------------------------------------------------------------\n\n");
	printf("Total Number Of Vertices Are : %d\n",Gr.n);
	printf("Total Number Of Edges Are : %d\n",Gr.e);
	printf("\nDirectional Graph Using Adjacency List Method Is As Follows : \n");
	for(i=1;i<=Gr.n;i++)
	{
		printf("\nVertices Connected To %d Are : ",i);
		p=*(Gr.G+i);
		if(p!=NULL)
		{
			while(p)
			{
				printf("%d  ",p->data);
				p=p->next;
			}
		}
		printf("\n");
	}
	printf("\n-----------------------------------------------------------------------------\n");
}

int main()
{
	struct Graph Gr;
	
	IGraph(&Gr);
	
	CreateGraph(&Gr);
	
	BFS(Gr,7);
	
	Display(Gr);
	
	return(0);
}
