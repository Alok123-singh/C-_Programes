#include <iostream>
#include <limits.h>
#include <stdbool.h>

using namespace std;

int n=3,e=3;
int Gr[4][4];

class Stack
{
    private:
	    int ne;
		int size;
		int top;
		int *q;
	public:
	    Stack();
		Stack(int size);
		void Push(int key);
		int Pop();
		bool isFull();
		bool isEmpty();
		int StackTop();
		~Stack();	
};

class Queue
{
    private:
	    int ne;
		int size;
		int front;
		int rear;
		int *q;
	public:
	    Queue();
		Queue(int size);
		void Enqueue(int key);
		int Dequeue();
		bool isEmpty();
		bool isFull();
		~Queue();	
};

void CreateGraph()
{
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Any Integer For Presence And 0 For Absence Of Vertex "<<i<<"\n";
		for(int j=1;j<=n;j++)
		{
			int temp;
			cout<<"\nEnter Presence And Absence For Vertex "<<j<<endl;
			cin>>temp;
			if(temp!=0)
			    Gr[i][j]=temp;
			else
			    Gr[i][j]=INT_MAX;
		}
		cout<<endl;
	}
}

void Display()
{
	cout<<"\n----------------------------------------------------------------\n\n";
	cout<<"Total Number Of Vertices In Graph Are : "<<n<<endl;
	cout<<"Total Number Of Edges In Graph Are : "<<e<<endl;
	cout<<"\nNon Directional Graph Is As Follows :\n";
	for(int i=1;i<=n;i++)
	{
		cout<<"\nVertices Connected To Vertex "<<i<<" Are : ";
		for(int j=1;j<=n;j++)
		{
			if(Gr[i][j]!=INT_MAX)
			    cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<"\n----------------------------------------------------------------\n";
}

int Indegree(int v)
{
	int count=0;
	
	for(int i=1;i<=n;i++)
	{
		if(Gr[i][v]!=0)
		    count++;
	}
	return(count);
}

int Outdegree(int v)
{
	int count=0;
	
	for(int j=1;j<=n;j++)
	{
		if(Gr[v][j]!=0)
		    count++;
	}
	return(count);
}

bool SelfLoop(int v)
{
	if(Gr[v][v]!=0)
	    return(true);
	return(false);
}

void BFS(int v) // Breadth First Search
{
	Queue Q(n);
	int visited[n+1]={0};
	
	cout<<"\nBreadth First Search : ";
	cout<<v<<" ";
	Q.Enqueue(v);
	visited[v]=1;
	
	while(!Q.isEmpty())
	{
		int x=Q.Dequeue();
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
			    if(Gr[x][i]!=INT_MAX)
				{
					Q.Enqueue(i);
					cout<<i<<" ";
					visited[i]=1;
				}
			}
		}
	}
	cout<<endl;
}

void DFS(int v) // Depth First Search
{
	Stack stk(n);
	int visited[n+1]={0};
	
	cout<<"\nDepth First Search : ";
	cout<<v<<" ";
	visited[v]=1;
	stk.Push(v);
	
	while(!stk.isEmpty())
	{
		int x=stk.Pop();
		int flag=0;
		int i;
		
		for(i=1;i<=n;i++)
		{
			if(visited[i]==0)
			{
				if(Gr[x][i]!=INT_MAX)
				{
					flag=1;
					break;
				}
			}
		}
		
		if(flag==1)
		{
			stk.Push(x);
			stk.Push(i);
			cout<<i<<" ";
			visited[i]=1;
		}
	}
	cout<<endl;
}

void RDFS(int v) // Recursive Depth First Search
{
	static int visited[INT_MAX/2]={0};
	static int flag=0;
	int i,flag1=0;
	
	if(flag==0)
	{
		cout<<"\nDepth First Search : ";
		cout<<v<<" ";
		visited[v]=1;
		flag=1;
	}
	
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			if(Gr[v][i]!=INT_MAX)
			{
				visited[i]=1;
				cout<<i<<" ";
				flag1=1;
				break;
			}
		}
	}
	if(flag1==1)
	    RDFS(i);
}

void PrimsMCST() // Prim's Algorithm To Find Minimum Cost Spanning Tree
{
	int near[n+1];
	int t[2][n-1];
	int u,v;
	int min=INT_MAX;
	
	for(int i=1;i<=n;i++)
	    near[i]=INT_MAX;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(Gr[i][j]<min)
			{
				min=Gr[i][j];
				u=i;
				v=j;
			}
		}
	}
	
	t[0][0]=u; t[1][0]=v;
	near[u]=near[v]=0;
	
	for(int i=1;i<=n;i++)
	{
		if(near[i]!=0)
		{
			if(Gr[i][u]<Gr[i][v])
			    near[i]=u;
			else
			    near[i]=v;
		}
	}
	
	for(int i=1;i<n-1;i++)
	{
		min=INT_MAX;
		for(int i1=1;i1<=n;i1++)
		{
			if(near[i1]!=0)
			{
				if(Gr[i1][near[i1]]<min)
				{
					min=Gr[i1][near[i1]];
					u=i1;
					v=near[i1];
				}
			}
		}
		t[0][i]=u;
		t[1][i]=v;
		near[u]=near[v]=0;
		
		for(int i1=1;i1<=n;i1++)
		{
			if(Gr[i1][u]<Gr[i1][v])
			    near[i1]=u;
			else
			    near[i1]=v;
		}
	}
	int sum=0;
	
	for(int i=0;i<n-1;i++)
	    sum+=Gr[t[0][i]][t[1][i]];
	
	cout<<"\nMinimum Cost Spanning Tree With Cost = "<<sum<<" Is As Follows : \n";
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<n-1;j++)
		    cout<<t[i][j]<<" ";
		cout<<endl;
	}
}

void WeightedUnion(int set[],int u,int v)
{
	if(set[u]<set[v])
	{
		set[u]=set[u]+set[v];
		set[v]=u;
	}
	else
	{
		set[v]=set[v]+set[u];
		set[u]=v;
	}
}

int Find(int set[],int u)
{
	int x=u;
	
	while(set[x]>0)
	    x=set[x];
	
	return(x);
}

int CollapsingFind(int set[],int u)
{
	int x=u;
	
	while(set[x]>0)
	    x=set[x];
	
	while(set[u]>0)
	{
		int temp=u;
		u=set[u];
		set[temp]=x;
	}
	
	return(x);
}

void KruskalsMCST()
{
	int Gr[3][e];
	int t[2][n-1];
	int set[n+1]={-1};
	int included[e]={0};
	int u,v,i=0;
	
	int k=1;
	for(int i=0;i<e;i++)
	{
		cout<<"\nEnter The Information About "<<k<<" Edge :\n";
		cout<<"\nEnter First Vetex :\n";
		cin>>Gr[0][i];
		cout<<"\nEnter Second Vertex :\n";
		cin>>Gr[1][i];
		cout<<"\nEnter Cost Of This Edge :\n";
		cin>>Gr[2][i];
		k++;
	}
	
	while(i<n-1)
	{
		int min=INT_MAX;
        int k;
		for(int i1=0;i1<e;i1++)
		{
			if(included[i1]!=1)
			{
				if(Gr[2][i1]<min)
				{
					min=Gr[2][i1];
					u=Gr[0][i1];
					v=Gr[1][i1];
					k=i1;
				}
			}
		}
		
		if(Find(set,u)!=Find(set,v))
		{
			t[0][i]=u;
			t[1][i]=v;
			WeightedUnion(set,Find(set,u),Find(set,v));
			i++;
		}
		
		included[k]=1;
	}
	
	cout<<"\nMinimum Cost Spanning Tree Is As Follows : \n";
	for(int i=0;i<=1;i++)
	{
		for(int j=0;j<n-1;j++)
		    cout<<t[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	CreateGraph();
	
	Display();
	//DFS(1);
	RDFS(1);
	
	//KruskalsMCST();
	//PrimsMCST();
	
	return(0);
}

Stack::Stack(int size)
{
	this->size=size;
	ne=0;
	top=-1;
	q=new int[size];
}

Stack::Stack() : Stack(50)
{
	
}

void Stack::Push(int key)
{
	if(top==size-1)
	    cout<<"\nStack Overflow\n";
	else
	{
		top++;
		*(q+top)=key;
	}
}

int Stack::Pop()
{
	int x=0;
	
	if(top==-1)
	    cout<<"\nStack Underflow\n";
	else
	{
		x=*(q+top);
		top--;
	}
	return(x);
}

int Stack::StackTop()
{
	if(top==-1)
	    return(-1);
	return(*(q+top));
}

bool Stack::isEmpty()
{
	if(top==-1)
	    return(true);
	return(false);
}

bool Stack::isFull()
{
	if(top==size-1)
	    return(true);
	return(false);
}

Stack::~Stack()
{
	delete []q;
}

Queue::Queue(int size)
{
	this->size=size;
    front=rear=0;
    ne=0;
    q=new int[size];
}

Queue::Queue() : Queue(50)
{
	
}

void Queue::Enqueue(int key)
{
    if(rear==size)
        cout<<"\nQueue Overflow\n";
    else
    {
    	*(q+rear)=key;
    	rear++;
	}
}

int Queue::Dequeue()
{
	int x=0;
	
	if(front==rear)
	    cout<<"\nQueue Underflow\n";
	else
	{
		x=*(q+front);
		front++;
		ne--;
	}
	return(x);
}

bool Queue::isEmpty()
{
	if(front==rear)
	    return(true);
	return(false);
}

bool Queue::isFull()
{
	if(rear==size)
	    return(true);
	return(false);
}

Queue::~Queue()
{
	delete []q;
}

