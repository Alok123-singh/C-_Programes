#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define I INT_MAX

using namespace std;

class Node
{
    public:
	    int data;
		Node *next;
		Node();
		Node(int data,Node *next);
};

class Stack
{
    private:
    	Node *first;
    	Node *last;
    	int size;
    public:
    	Stack();
    	Stack(int size);
    	Stack(Stack &stk);
    	void setfirst(Node *first);
    	void setlast(Node *last);
    	void setsize(int size);
    	Node * getfirst();
    	Node *getlast();
    	int getsize();
    	void Push(int key);
    	int Pop();
    	bool isEmpty();
    	bool isFull();
		virtual ~Stack();
};

class Queue
{
	private:
		int front;
		int rear;
		int *q;
		int size;
	public:
		Queue();
		Queue(int size);
		Queue(Queue &Q);
		void setfront(int front);
		void setrear(int rear);
		void setsize(int size);
		void setq(int q[]);
		int getfront();
		int getrear();
		int getsize();
		int* getq();
		void Enqueue(int key);
		int Dequeue();
		bool isEmpty();
		bool isFull();
		virtual ~Queue();
};

template<class T>
class Graph
{
	private:
		T Gr[8][8];
		int n;
		int e;
	public:
        Graph();
		Graph(int n,int e);
		Graph(Graph &G);
		void setvertices(int n);
		void setedges(int e);
		int getvertices();
		int getedges();
		void CreateGraph();
	    int Indegree(int v);
	    int Outdegree(int v);
	    bool SelfLoop(int v);
	    void BFS(int v);
	    void DFS(int v);
		void RDFS(int v);
		void PrimsMCST1();
		void PrimsMCST2();
		void Union(int set[],int u,int v);
		int Find(int set[],int u);
		int CollapsingFind(int set[],int u);
		void KruskalsMCST();
		void Display();
		template<class P>
		friend ostream & operator<<(ostream &o,Graph<P> &G);
		template<class P>
		friend istream & operator>>(istream &in,Graph<P> &G); 
		virtual ~Graph();		
};

template<class T>
ostream & operator<<(ostream &o,Graph<T> &G)
{
	int i,j;
	
	o<<"\n--------------------------------------------------------------------------\n\n";
	o<<"Total Number Of Vertices Are : "<<G.n<<endl;
	o<<"Total Number Of Edges Are : "<<G.e<<endl<<endl;
	o<<"Non Directional Graph Using Adjacency Matrix Method Is As Follows :\n";
	for(i=1;i<=G.n;i++)
	{
		o<<"\nVertices Connected To Vertex "<<i<<" Are : ";
		for(j=1;j<=G.n;j++)
		{
			if(G.Gr[i][j]!=I)
			    o<<j<<"  ";
		}
		o<<endl;
	}
	o<<"\n--------------------------------------------------------------------------\n";
	return(o);
}

template<class T>
istream & operator>>(istream &in,Graph<T> &G)
{
	int i,j;
	T temp;
	
	for(i=1;i<=G.n;i++)
	{
		cout<<"\nEnter 0 For Absence And Any Other Integer For Presence For The Vertex "<<i<<" :"<<endl;
		for(j=1;j<=G.n;j++)
		{
			cout<<"\nEnter Presence And Absence For Vertex "<<j<<" :"<<endl;
			in>>temp;
			if(temp==0)
			    G.Gr[i][j]=I;
			else
			    G.Gr[i][j]=temp;
		}
	}
	return(in);
}

int main()
{
	Graph<float> Gr1(7,9);
	
	cin>>Gr1;  // Gr1.CreateGraph();
    cout<<Gr1; // Gr1.Display();
	
	Gr1.PrimsMCST2();
	
	return(0);
}

Node::Node()
{
	data=0;
	next=NULL;
}

Node::Node(int data,Node *next)
{
	this->data=data;
	this->next=next;
}

Stack::Stack()
{
	int i;
	Node *temp=NULL;
	
	first=last=NULL;
	size=16;
	
	for(i=1;i<=16;i++)
	{
		temp=new Node(0,NULL);
		if(first==NULL)
			first=last=temp;
		else
		{
			last->next=temp;
			last=temp;
		}
	}
}

Stack::Stack(int size)
{
	int i;
	Node *temp=NULL;
	
	this->size=size;
	first=last=NULL;
	
	for(i=1;i<=size;i++)
	{
		temp=new Node(0,NULL);
		if(first==NULL)
		    first=last=temp;
		else
		{
			last->next=temp;
			last=temp;
		}
	}
}

Stack::Stack(Stack &stk)
{
	int i;
	Node *temp=NULL,*p=stk.first;
	
	size=stk.size;
	first=last=NULL;
	
	for(i=1;i<=size;i++)
	{
		temp=new Node(p->data,NULL);
		if(first==NULL)
		    first=last=temp;
		else
		{
			last->next=temp;
			last=temp;
		}
		p=p->next;
	}
}

void Stack::setfirst(Node *first)
{
	this->first=first;
}

void Stack::setlast(Node *last)
{
	this->last=last;
}

void Stack::setsize(int size)
{
	this->size=size;
}

Node * Stack::getfirst()
{
    return(first);	
}

Node * Stack::getlast()
{
	return(last);
}

int Stack::getsize()
{
	return(size);
}

void Stack::Push(int key)
{
	Node *temp=new Node(key,NULL);
	
	if(temp==NULL)
	    printf("\nStack Overflow\n");
	else
	{
		if(first==NULL)
		    first=last=temp;
		else
		{
		    last->next=temp;
		    last=temp;
		}
	}
}

int Stack::Pop()
{
	int x=-1;
	Node *temp=first;
	
	if(first==NULL)
        printf("\nStack Underflow\n");
    else
    {
    	x=last->data;
    	if(first==last)
    	{
    		first=last=NULL;
    		delete(temp);
		}
		else
		{
		    while(temp->next!=last)
    	        temp=temp->next;
    	    temp->next=NULL;
    	    delete last;
    	    last=temp;
        }  
	}
	return(x);
}

bool Stack::isEmpty()
{
	if(first==NULL)
	    return(true);
	return(false);
}

bool Stack::isFull()
{
	Node *test=NULL;

	test=new Node;
	if(test==NULL)
	    return(true);
	return(false);
}

Stack::~Stack()
{
	Node *p=first,*q=NULL;
	
	first=last=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        delete q;
	}
}

Queue::Queue()
{
	size=16;
	q=new int[16];
	front=rear=-1;
}

Queue::Queue(int size)
{
	this->size=size;
	q=new int[size];
	front=rear=-1;
}

Queue::Queue(Queue &Q)
{
	int x=Q.front+1;
	
	size=Q.size;
	q=new int[size];
	front=Q.front;
	rear=Q.rear;
	
	while((x+1)%size!=Q.front)
	{
		*(q+x)=*(Q.q+x);
		x=(x+1)%size;
	}
}

void Queue::setfront(int front)
{
	this->front=front;
}

void Queue::setrear(int rear)
{
	this->rear=rear;
}

void Queue::setsize(int size)
{
	this->size=size;
	delete q;
	q=new int[size];
}

void Queue::setq(int q[])
{
	this->q=q;
}

int Queue::getfront()
{
	return(front);
}

int Queue::getrear()
{
	return(rear);
}

int Queue::getsize()
{
	return(size);
}

int * Queue::getq()
{
	return(q);
}

void Queue::Enqueue(int key)
{
	if((rear+1)%size==front)
	    printf("\nQueue Overflow\n");
	else
	{
		rear=(rear+1)%size;
		*(q+rear)=key;
	}
}

int Queue::Dequeue()
{
    int x=-1;
	
	if(front==rear)
	    printf("\nQueue Underflow\n");
	else
	{
        front=(front+1)%size;
        x=*(q+front);
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
	if((rear+1)%size==front)
	    return(true);
	return(false);
}

Queue::~Queue()
{
	delete []q;
}

template<class T>
Graph<T>::Graph()
{
	n=7;
	e=9;
}

template<class T>
Graph<T>::Graph(int n,int e)
{
	this->n=n;
	this->e=e;
}

template<class T>
Graph<T>::Graph(Graph<T> &G)
{
	int i,j;
	
	n=G.n;
	e=G.e;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(G.Gr[i][j]!=I)
			    Gr[i][j]=G.Gr[i][j];
			else
			    Gr[i][j]=I;
		}
	}
}

template<class T>
void Graph<T>::setvertices(int n)
{
	this->n=n;
}

template<class T>
void Graph<T>::setedges(int e)
{
	this->e=e;
}

template<class T>
int Graph<T>::getvertices()
{
	return(n);
}

template<class T>
int Graph<T>::getedges()
{
	return(e);
}

template<class T>
void Graph<T>::CreateGraph()
{
	int i,j;
	T temp;
	
	for(i=1;i<=n;i++)
	{
		cout<<"\nEnter 0 For Absence And Any Other Integer For Presence For The Vertex "<<i<<" :"<<endl;
		for(j=1;j<=n;j++)
		{
			cout<<"\nEnter Presence And Absence For Vertex "<<j<<" :"<<endl;
			cin>>temp;
			if(temp==0)
			    Gr[i][j]=I;
			else
			    Gr[i][j]=temp;
		}
	}
}

template<class T>
void Graph<T>::Display()
{
	int i,j;
	
	cout<<"\n--------------------------------------------------------------------------\n\n";
	cout<<"Total Number Of Vertices Are : "<<n<<endl;
	cout<<"Total Number Of Edges Are : "<<e<<endl<<endl;
	cout<<"Non Directional Graph Using Adjacency Matrix Method Is As Follows :\n";
	for(i=1;i<=n;i++)
	{
		cout<<"\nVertices Connected To Vertex "<<i<<" Are : ";
		for(j=1;j<=n;j++)
		{
			if(Gr[i][j]!=I)
			    cout<<j<<"  ";
		}
		cout<<endl;
	}
	cout<<"\n--------------------------------------------------------------------------\n";
}

template<class T>
int Graph<T>::Indegree(int v)
{
	int count=0;
	int i;
	
	for(i=1;i<=n;i++)
	{
		if(Gr[i][v]!=I)
		    count++;
	}
	return(count);
}

template<class T>
int Graph<T>::Outdegree(int v)
{
	int count=0;
	int j;
	
	for(j=1;j<=n;j++)
	{
		if(Gr[v][j]!=I)
		    count++;
	}
	return(count);
}

template<class T>
bool Graph<T>::SelfLoop(int v)
{
	if(Gr[v][v]!=I)
	    return(true);
	return(false);
}

template<class T>
void Graph<T>::BFS(int v)
{
	Queue Q(n);
	int visited[n+1];
	int x,i;
	
	for(i=0;i<=n;i++)
	    visited[i]=0;
	
	cout<<"\n--------------------------------------------------------------------------\n\n";
	cout<<"Breadth First Search Is As Follows : ";
	cout<<v<<"  ";
	Q.Enqueue(v);
	visited[v]=1;
	while(!Q.isEmpty())
	{
		x=Q.Dequeue();
		for(i=1;i<=n;i++)
		{
			if(Gr[x][i]!=I && visited[i]==0)
			{
				cout<<i<<"  ";
				Q.Enqueue(i);
				visited[i]=1;
			}
		}
	}
	cout<<"\n\n--------------------------------------------------------------------------\n";
}

template<class T>
void Graph<T>::DFS(int v)
{
	int v1,x,i;
	Stack stk(0);
	int visited[n+1];
	
	for(i=0;i<=n;i++)
	    visited[i]=0;
	
	cout<<"\n--------------------------------------------------------------------------\n\n";
	cout<<"Depth First Search Is As Follows : ";
	cout<<v<<"  ";
	stk.Push(v);
	visited[v]=1;
	while(!stk.isEmpty())
	{
        v1==stk.Pop();
        x=-1;
		for(i=1;i<=n;i++)
		{
		    if(Gr[v1][i]!=I && visited[i]==0)
			{
			    x=i;
				break;   	
			}
		}
		
		if(x!=-1)
		{
		    cout<<x<<"  ";
			stk.Push(v1);
			stk.Push(x);
			visited[x]=1;	
		}	
	}
	cout<<"\n\n--------------------------------------------------------------------------\n";
}

template<class T>
void Graph<T>::RDFS(int v)
{
	static int visited[8]={0};
	int j;
	
	if(visited[v]==0)
	{
		cout<<v<<"  ";
		visited[v]=1;
		
		for(j=1;j<=n;j++)
		{
			if(Gr[v][j]!=I && visited[j]==0)
				RDFS(j);
		}
	}
}

template<class T>
void Graph<T>::PrimsMCST1()
{
	int t[2][n-1];
	int near[n+1],i,j;
	int u,v,min=I;
	
	for(i=0;i<=n;i++)
	    near[i]=I;
	
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(Gr[i][j]<min)
			{
				min=Gr[i][j];
				u=i;
				v=j;
			}
		}
	}
	
	t[0][0]=u;  t[1][0]=v;
	near[u]=near[v]=0;
	
	for(i=1;i<n-1;i++)
	{
		min=I;
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0)
			{
			    if(Gr[j][u]<Gr[j][v])
			        near[j]=u;
			    else
			        near[j]=v;
		    }
		}
		
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0)
			{
				if(Gr[j][near[j]]<min)
				{
					min=Gr[j][near[j]];
					u=j;
					v=near[j];
				}
			}
		}
		t[0][i]=u;
		t[1][i]=v;
		near[u]=0;
	}
	
	cout<<"\nEdges Of Minimum Cost Spanning Tree Using Prims Algorithms :\n";
	for(i=0;i<n-1;i++)
		cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
}

template<class T>
void Graph<T>::PrimsMCST2()
{
	int t[2][n-1];
	int near[n+1],i,j;
	int u,v,min=I;
	
	for(i=0;i<=n;i++)
	    near[i]=I;
	
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(Gr[i][j]<min)
			{
				min=Gr[i][j];
				u=i;
				v=j;
			}
		}
	}
	
	t[0][0]=u;  t[1][0]=v;
	near[u]=near[v]=0;
	
	for(i=1;i<=n;i++)
	{
		if(near[i]!=0)
		{
			if(Gr[i][u]<Gr[i][v])
			    near[i]=u;
			else
			    near[i]=v;
		}
	}
	
	for(i=1;i<n-1;i++)
	{
		min=I;
		for(j=1;j<=n;j++)
		{
			if(near[j]!=0)
			{
				if(Gr[j][near[j]]<min)
				{
					min=Gr[j][near[j]];
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
				if(Gr[j][u]<Gr[j][near[j]])
				    near[j]=u;
			}
		}
	}
	
	cout<<"\nEdges Of Minimum Cost Spanning Tree Using Prims Algorithms :\n";
	for(i=0;i<n-1;i++)
		cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
}

template<class T>
void Graph<T>::Union(int set[],int u,int v)
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

template<class T>
int Graph<T>::Find(int set[],int u)
{
	int x=u;
	
	while(*(set+x)>0)
	    x=*(set+x);
	
	return (x);
}

template<class T>
int Graph<T>::CollapsingFind(int set[],int u)
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

template<class T>
void Graph<T>::KruskalsMCST()
{
	int t[0][n-1];
	int included[e],set[n+1];
	int G[3][e];
	int i,j,k,min=I;
	
	cout<<"\nEnter Information About All The Edges Of The Graph :\n";
	for(i=0;i<e;i++)
	{
		j=1;
		cout<<"\nEnter The Information About "<<i+1<<" Edge :\n";
		cout<<"\nEnter Its "<<j<<" Vertex:\n";
		cin>>G[0][i];
		cout<<"\nEnter Its "<<j+1<<" Vertex :\n";
		cin>>G[1][i];
		cout<<"\nEnter The Cost Of This Edge :\n";
		cin>>G[2][i];
	}
	
	for(i=0;i<e;i++)
	    included[i]=0;
	
	for(i=0;i<=n;i++)	
	    set[i]=-1;
	
	i=0;
	while(i<n-1)
	{
		min=I;
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
	
	cout<<"\nEdges Of Minimum Cost Spanning Tree Using Kruskals Algorithms :\n";
	for(i=0;i<n-1;i++)
		cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
}

template<class T>
Graph<T>::~Graph(){}

