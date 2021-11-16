#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Queue
{
	int size;
	struct Node *first;
};

void IQueue(struct Queue *Q)
{
	Q->size=0;
	Q->first=NULL;
}

void Enqueue(struct Queue *Q,int key)
{
	struct Node *p=NULL,*q=NULL;
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=key;
	p->next=NULL;
	if(p==NULL)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	
	if(Q->first==NULL)
		Q->first=p;
	else
	{
		q=Q->first;
		while(q->next!=NULL)
		    q=q->next;
		q->next=p;
	}
	Q->size++;
}

int Dequeue(struct Queue *Q)
{
	struct Node *p=NULL;
	int x=-1;
	
	if(Q->first==NULL)
	    printf("\nQueue Underflow\n");
	else
	{
		p=Q->first;
		Q->first=Q->first->next;
		x=p->data;
		free(p);
		Q->size--;
	}
	return(x);
}

bool isEmptyQueue(struct Queue Q)
{
	if(Q.first==NULL)
	    return(true);
	return(false);
}

bool isFullQueue(struct Queue Q)
{
	struct Node *test=NULL;
	test=(struct Node *)malloc(sizeof(struct Node));
	if(test==NULL)
	    return(true);
	return(false);
}

struct Stack
{
    int size;
    struct Node *first;
	struct Node *rear;	
};

void IStack(struct Stack *s)
{
	s->first=s->rear=NULL;
	s->size=0;
}

void Push(struct Stack *s,int key)
{
	struct Node *p=NULL;
	
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=key;
	p->next=NULL;
	
	if(p==NULL)
		printf("\nStack Overflow\n");
	else
	{
		if(s->first==NULL)
		    s->first=s->rear=p;
	    else
	    {
		    s->rear->next=p;
		    s->rear=p;
	    }
		s->size++;
	}
}

int Pop(struct Stack *s)
{
	int x=-1;
	struct Node *p=s->first,*q=s->rear;
	
	if(s->first==NULL)
		printf("\nStack Underflow\n");
	else
	{
		while(p->next && p->next!=s->rear)
		    p=p->next;
		x=q->data;
		p->next=NULL;
		
		if(s->first==s->rear)
			s->first=s->rear=NULL;
		else
		    s->rear=p;
		free(q);
		s->size--;
	}
	return(x);
}

bool isEmptyStack(struct Stack s)
{
	if(s.first==NULL)
	    return(true);
	return(false);
}

bool isFullStack(struct Stack s)
{
	struct Node *test=NULL;
	test=(struct Node *)malloc(sizeof(struct Node));
	if(test==NULL)
	    return(true);
	return(false);
}

int n=7,e=9;

/*void I()
{
	printf("\nEnter Total Number Of Vertices :\n");
	scanf("%d",&n);
	printf("\nEnter Total Number Of Edges  :\n");
	scanf("%d",&e);
}*/

int Gr[7][7];

void CreateGraph()
{
	int i,j,temp;
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter Any Integer For The Presence And 0 For Absence Of The Vertex %d :\n",i+1);
		for(j=0;j<n;j++)
		{
			printf("\nEnter Presence And Absence For Vertex %d :\n",j+1);
			scanf("%d",&temp);
			if(temp!=0)
			    Gr[i][j]=temp;
			else
			    Gr[i][j]=INT_MAX;
		}
	}
}

int Indegree(int v)
{
	int count=0,i;
	
	for(i=0;i<n;i++)
	{
		if(Gr[i][v-1]!=INT_MAX)
		    count++;
	}
	return(count);
}

int Outdegree(int v)
{
	int count=0,j;
	
	for(j=0;j<n;j++)
	{
		if(Gr[v-1][j]!=INT_MAX)
		    count++;
	}
	return(count);
}

bool SelfLoop(int v)
{
	if(Gr[v-1][v-1]!=INT_MAX)
	    return(true);
	return(false);
}

void BFS(int v) // Breadth First Search
{
    int visited[n],i;
    struct Queue Q;
    int u,v1;
    
    for(i=0;i<n;i++)
        visited[i]=0;
    
    IQueue(&Q);
    
    Enqueue(&Q,v);
    visited[v-1]=1;
    printf("\nBreadth First Search Is As Follows : ");
    printf("%d  ",v);
    while(!isEmptyQueue(Q))
    {
    	u=Dequeue(&Q);
    	for(v1=1;v1<=n;v1++)
    	{
    		if(Gr[u-1][v1-1]!=INT_MAX && visited[v1-1]==0)
    		{
    			printf("%d  ",v1);
    			Enqueue(&Q,v1);
    			visited[v1-1]=1;
			}
		}
	}
	printf("\n");
}

void DFS(int v) // Depth First Search
{
	int x,i,v1,j;
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
		
		for(j=0;j<n;j++)
		{
		    if(Gr[v1-1][j]!=INT_MAX && visited[j]==0)
		    {
		        x=j+1;
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

void RDFS(int v) // Recursive Depth First Search
{
	static int visited[7]={0};
	int j;
	
	if(visited[v-1]==0)
	{
		printf("%d  ",v);
		visited[v-1]=1;
		
		for(j=1;j<=n;j++)
		{
			if(Gr[v-1][j-1]!=INT_MAX && visited[j-1]==0)
			    RDFS(j);
		}
	}
}

void PrimsMCST1()
{
	int i=0,k,k1;
	int near[n+1],j;
	int A[2][n-1];
	int min=INT_MAX;
	
	for(j=0;j<=n;j++)
	    near[j]=INT_MAX;
	
	for(k=0;k<n;k++)
	{
		for(k1=k+1;k1<n;k1++)
		{
			if(Gr[k][k1]<min)
			{
				min=Gr[k][k1];
				A[0][i]=k+1;
				A[1][i]=k1+1;
			}
		}
	}
	near[A[0][i]]=near[A[1][i]]=0;
	i++;
	
	while(i<n-1)
	{
		for(k=1;k<=n;k++)
		{
			if(near[k]!=0)
			{
				if(Gr[k-1][A[0][i-1]-1] < Gr[k-1][A[1][i-1]-1])
				    near[k]=A[0][i-1];
				else
				    near[k]=A[1][i-1];
			}
		}
		min=INT_MAX;
		for(k1=1;k1<=n;k1++)
		{
			if(near[k1]!=0)
			{
			    if(Gr[k1-1][near[k1]-1]<min)
			    {
				    min=Gr[k1-1][near[k1]-1];
				    A[0][i]=k1;
				    A[1][i]=near[k1];
			    }
		    }
		}
		if(near[A[0][i]]!=0)
		    near[A[0][i]]=0;
		if(near[A[1][i]]!=0)
		    near[A[1][i]]=0;
		i++;
	}
	
	printf("\nEdges Of Minimum Cost Spanning Tree Using Prims Algorithms :\n");
	for(k=0;k<n-1;k++)
		printf("(%d,%d)\n",A[0][k],A[1][k]);
}

void PrimsMCST2()
{
	int i,j,u,v,min=INT_MAX;
	int near[n+1];
	int t[2][n-1];
	
	for(i=0;i<=n;i++)
	    near[i]=INT_MAX;
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(Gr[i][j]<min)
			{
				min=Gr[i][j];
				u=i+1;
				v=j+1;
			}
		}
	}
	
	t[0][0]=u;  t[1][0]=v;
	near[u]=near[v]=0;
	
	for(i=1;i<=n;i++)
	{
		if(near[i]!=0)
		{
			if(Gr[i-1][u-1]<Gr[i-1][v-1])
			    near[i]=u;
			else
			    near[i]=v;
		}
	}
	
	for(i=1;i<n-1;i++)
	{
		min=INT_MAX;
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0)
			{
				if(Gr[j-1][near[j]-1]<min)
				{
					min=Gr[j-1][near[j]-1];
					u=j;
					v=near[j];
				}
			}
		}
		
		t[0][i]=u;  t[1][i]=v;
		near[u]=0;
		
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0)
			{
				if(Gr[j-1][u-1]<Gr[j-1][near[j]-1])
				    near[j]=u;
			}
		}
	}
	
	printf("\nEdges Of Minimum Cost Spanning Tree Using Prims Algorithms :\n");
	for(i=0;i<n-1;i++)
		printf("(%d,%d)\n",t[0][i],t[1][i]);
}

void Union(int set[],int u,int v)
{
	if(*(set+u)<*(set+v))
	{
		*(set+u)=*(set+u)+*(set+v);
		*(set+v)=u;
	}
	else
	{
		*(set+v)=*(set+v)+*(set+u);
		*(set+u)=v;
	}
}

int Find(int set[],int u)
{
	int x=u;
	
	while(*(set+x)>0)
	    x=*(set+x);
	    
	return(x);
}

int CollapsingFind(int set[],int u)
{
	int x=u,v;
	while(*(set+x)>0)
	    x=*(set+x);
    
	while(u!=x)
	{
	    v=*(set+u);
		*(set+u)=x;
		u=v;	
	}	
	return(x);
}

void KruskalsMCST()
{
	int G[3][e],i,j,k;
	int set[n+1]={-1};
	int included[e]=0;
	int t[2][n-1],min;
	
	printf("\nEnter Information About All The Edges Of The Graph :\n");
	for(i=0;i<e;i++)
	{
		j=1;
		printf("\nEnter The Information About %d Edge :\n",i+1);
		printf("\nEnter Its %d Vertex:\n",j);
		scanf("%d",&G[0][i]);
		printf("\nEnter Its %d Vertex :\n",j+1);
		scanf("%d",&G[1][i]);
		printf("\nEnter The Cost Of This Edge :\n");
		scanf("%d",&G[2][i]);
	}
	/*
	for(i=0;i<e;i++)
	    included[i]=0;
	
	for(i=0;i<=n;i++)
	    set[i]=-1;
	*/
	i=0;
	while(i<n-1)
	{
		min=INT_MAX;
		for(j=0;j<e;j++)
		{
			if(included[j]==0 && G[2][j]<min)
			{
				min=G[2][j];
				k=j;
			}
		}
		
		if(CollapsingFind(set,G[0][k])!=CollapsingFind(set,G[1][k]))
		{
			t[0][i]=G[0][k];
			t[1][i]=G[1][k];
			Union(set,CollapsingFind(set,t[0][i]),CollapsingFind(set,t[1][i]));
		    i++;
		}
		included[k]=1;
	}
	
	printf("\nEdges Of Minimum Cost Spanning Tree Using Kruskals Algorithms :\n");
	for(i=0;i<n-1;i++)
		printf("(%d,%d)\n",t[0][i],t[1][i]);
}

void Display()
{
	int i,j;
	
	printf("\n--------------------------------------------------------------------------\n\n");
    printf("Total Number Of Vertices Are : %d\n",n);
    printf("Total Number Of Edges Are : %d\n",e);
    printf("\nNon Directional Graph Using Adjacency Matrix Method Is As Follows :\n");
    for(i=0;i<n;i++)
	{
	    printf("\nVertices Connected To Vertex %d Are : ",i+1);
		for(j=0;j<n;j++)
		{
		    if(Gr[i][j]!=INT_MAX)
		        printf("%d  ",j+1);
		}
		printf("\n");	
	}	
	printf("\n--------------------------------------------------------------------------\n");
}

int main()
{
	CreateGraph();
	
	PrimsMCST1();
	//KruskalsMCST();
	
	Display();
	
	return(0);
}
