#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "math.h"
#define nullptr NULL

struct Element
{
	struct Element *lchild;
	struct Element *rchild;
	int data;
};

struct Tree
{
    struct Element *root;
	int size;
};

struct Node
{
    struct Element *data;
	struct Node *next;	
};

struct Queue
{
    struct Node *first;
    struct Node *rear;
    int size;
};

struct Stack
{
    int size;
	int top;
	struct Element **q;	
};

void createStack(struct Stack *s)
{
	int i;
	
	printf("Enter Size Of The Stack :\n");
	scanf("%d",&s->size);
	
	s->q=(struct Element **)malloc(s->size*sizeof(struct Element *));
	
	s->top=-1;
	
	printf("Enter Information About The Elements Of The Stack :\n");
	
	for(i=0;i<s->size;i++)
	{
		printf("\nEnter Data In %d Element :\n",i+1);
		s->top++;
		scanf("%d",s->q+i);
		
	}
}

void IStack(struct Stack *s,int size)
{
	int i;
	
	s->size=size;
	s->top=-1;
	
	s->q=(struct Element **)malloc(size*sizeof(struct Element *));
	
	for(i=0;i<size;i++)
	    *(s->q+i)=0;
}

void Push(struct Stack *s,long long add)
{
	if(s->top==s->size-1)
	    printf("\nStack Overflow :\n");
	
	else
	{
		s->top++;
		*(s->q+s->top)=(struct Element *)add;
	}
}

long long Pop(struct Stack *s)
{
    long long x=0;
	
	if(s->top==-1)
	    printf("Stack Underflow :\n");
	
	else
	{
	    x=(long long)*(s->q+s->top);
		*(s->q+s->top)=NULL;
		s->top--;	
	}
	return(x);
}

bool isEmptyStack(struct Stack s)
{
	if(s.top==-1)
	    return(true);
	    
	return false;
}

bool isFullStack(struct Stack s)
{
	if(s.top==s.size-1)
	    return(true);
	    
	return(false);
}

void create(struct Queue *q)
{
	struct Node *temp=NULL;
	int i;
	
	printf("Enter The Size Of The Queue :\n");
	scanf("%d",&q->size);
	
	if(q->size==0)
		q->first=q->rear=NULL;
    
    else
    {
        printf("Enter Information About Elements Of The Queue :\n\n");
        printf("Enter 1 Element :\n");
    
        q->first=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&q->first->data);
        q->first->next=NULL;
        q->rear=q->first;
    
        for(i=1;i<q->size;i++)
        {
		    temp=(struct Node *)malloc(sizeof(struct Node));
		    printf("\nEnter %d Element :\n",i+1);
		    scanf("%d",temp->data);
		    temp->next=q->rear->next;
		    q->rear->next=temp;
		    q->rear=temp;
	    }
	}
	
}

void I(struct Queue *q,int size)
{
	struct Node *temp=NULL;

	if(size==0)
		q->first=q->rear=NULL;
	
    else
    {
    	temp=q->first;
    	while(temp!=NULL)
    	{
    		temp->data=NULL;
    		temp=temp->next;
		}
	}
	q->size=size;
}

void Enqueue(struct Queue *q,struct Element *add)
{
	struct Node *temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	
	if(temp==NULL)
	    printf("\nQueue Overflow\n");
	
	temp->data=add;
	temp->next=NULL;
	
	if(q->size==0)
	    q->first=q->rear=temp;
	
	else
	{
		q->rear->next=temp;
		q->rear=temp;
	}
	
	q->size++;
}

struct Element * Dequeue(struct Queue *q)
{
	struct Element *data=NULL;
	struct Node *p=NULL;
	
	if(q->size==0)
	    printf("\nQueue Underflow\n");
	
	else
	{
		p=q->first;
        q->first=q->first->next;
        
		if(p->next==NULL)
		    q->rear=NULL;		    
		
		data=p->data;
		free(p);
		q->size--;
	}
	
	return(data);
}

bool isEmpty(struct Queue q)
{
	if(q.size==0)
	    return(true);
	    
	return(false);
}

bool isFull(struct Queue q)
{
	struct Node *test=NULL;
	
	test=(struct Node *)malloc(sizeof(struct Node));
	
	if(test==NULL)
	    return(true);
	    
	return(false);
}

void createTree(struct Tree *t)
{
    struct Element *temp=NULL;
    struct Queue q;
    int x,i;
    
    I(&q,0);
    t->root=NULL;
    
    printf("Enter Total Number Of Nodes Present In The Tree :\n");
    scanf("%d",&t->size);
    
    printf("\nEnter Information About The Nodes Present In The Tree :\n");
    
	for(i=1;i<=t->size;i++)
	{
		if(i==1)
		{
		    t->root=(struct Element *)malloc(sizeof(struct Element));
			printf("\nEnter Data In Root Node :\n");
		    scanf("%d",&x);
			t->root->data=x;
			t->root->lchild=t->root->rchild=NULL;
			Enqueue(&q,t->root);
		}
		    
		temp=Dequeue(&q);
		
        printf("\nEnter Data In Left Child Of %d :\n",temp->data);
        scanf("%d",&x);
        if(x!=-1)
        {
        	temp->lchild=(struct Element *)malloc(sizeof(struct Element));
        	temp->lchild->data=x;
        	temp->lchild->lchild=temp->lchild->rchild=NULL; 
        	Enqueue(&q,temp->lchild);
		}
		
		printf("\nEnter Data In Right Child Of %d :\n",temp->data);
		scanf("%d",&x);
		if(x!=-1)
		{
			temp->rchild=(struct Element *)malloc(sizeof(struct Element));
			temp->rchild->data=x;
			temp->rchild->lchild=temp->rchild->rchild=NULL;
			Enqueue(&q,temp->rchild);
		} 
    }
    
}

void Preorder(struct Element *e,int size)
{
	static int i=0,count=0;
	if(i==0)
	{
        printf("\n-----------------------------------------------------------\n\n");
        printf("Pre Order Traversal Of This Tree Is As Follows :\n");
	}
	
    if(e)
    {
    	if(count!=0 || i==0)
		    printf("%d ",e->data);
    	
		count++;
    	++i;
    	Preorder(e->lchild,size);
    	Preorder(e->rchild,size);
	}
	
	if(count==size)
	{
	    printf("\n\nSize Of The Tree Is : %d",count);
	    count=0;
		printf("\n\n-----------------------------------------------------------\n");
	}
}

void Inorder(struct Element *e,int size)
{
	static int i=0,count=0,j=0;
	if(j==0)
	{
        printf("\n-----------------------------------------------------------\n\n");
        printf("In Order Traversal Of This Tree Is As Follows :\n");
	}
	
    if(e)
    {
    	j++;
    	Inorder(e->lchild,size);
    	if(count!=0 || i==0)
		    printf("%d ",e->data);
		
		count++;
    	++i;
		Inorder(e->rchild,size);
	}
	
	if(count==size)
	{
	    printf("\n\nSize Of The Tree Is : %d",count);
	    count=0;
		printf("\n\n-----------------------------------------------------------\n");
	}
}

void Postorder(struct Element *e,int size)
{
	static int i=0,count=0,j=0;
	if(j==0)
	{
        printf("\n-----------------------------------------------------------\n\n");
        printf("Post Order Traversal Of This Tree Is As Follows :\n");
	}
	
    if(e)
    {
    	j++;
    	Postorder(e->lchild,size);
    	Postorder(e->rchild,size);
    	
		if(count!=0 || i==0)
		    printf("%d ",e->data);
		    
    	++i;
    	count++;
	}
	
	if(count==size)
	{
	    printf("\n\nSize Of The Tree Is : %d",count);
	    count=0;
		printf("\n\n-----------------------------------------------------------\n");
	}
}

void IPreorder(struct Tree t)
{
	struct Element *p=t.root;
	struct Stack s;
	
	IStack(&s,t.size);
	
	printf("\n---------------------------------------------------------------\n\n");
	printf("Size Of The Tree Is As Follows : %d\n\n",t.size);
	printf("Pre Order Traversal Of This Tree Is As Follows :\n");
	
	while(p!=NULL || !isEmptyStack(s))
	{
		if(p)
		{
			printf("%d ",p->data);
			Push(&s,(long long)p);
			p=p->lchild;
		}
		
		else
		{
			p=(struct Element *)Pop(&s);
			p=p->rchild;
		}
	}
	
	printf("\n\n---------------------------------------------------------------\n");
}

void IInorder(struct Tree t)
{
	struct Element *p=t.root;
	struct Stack s;
	
	IStack(&s,t.size);
	
	printf("\n---------------------------------------------------------------\n\n");
	printf("Size Of The Tree Is As Follows : %d\n\n",t.size);
	printf("In Order Traversal Of This Tree Is As Follows :\n");
	
	while(p!=NULL || !isEmptyStack(s))
	{
		if(p)
		{
			Push(&s,(long long)p);
			p=p->lchild;
		}
		
		else
		{
			p=(struct Element *)Pop(&s);
			printf("%d ",p->data);
			p=p->rchild;
		}
	}
	
	printf("\n\n---------------------------------------------------------------\n");
}

void IPostorder(struct Tree t)
{
	struct Element *p=t.root;
	struct Stack stk;
	long long temp;
	
	IStack(&stk,t.size);
	
	printf("\n---------------------------------------------------------------\n\n");
	printf("Size Of The Tree Is As Follows : %d\n\n",t.size);
	printf("Post Order Traversal Of This Tree Is As Follows :\n");
	
	while(p!=NULL || !isEmptyStack(stk))
	{
		if(p)
		{
			Push(&stk,(long long)p);
			p=p->lchild;
		}
		
		else
        {
			temp=Pop(&stk);
			if(temp>0)
			{
				Push(&stk,-temp);
				p=((struct Element *)temp)->rchild;
			}
			
			else
			{
				printf("%d ",((struct Element *)temp)->data);
				p=NULL;
			}
		}
	}
	printf("\n\n---------------------------------------------------------------\n");
}

void Levelorder(struct Tree t)
{
	struct Element *p=t.root;
	struct Queue q;
	
	I(&q,0);
	
	printf("\n---------------------------------------------------------------\n\n");
	printf("Size Of The Tree Is As Follows : %d\n\n",t.size);
	printf("Level Order Traversal Of This Tree Is As Follows :\n");
	
	printf("%d ",p->data);
	Enqueue(&q,p);
	
	while(!isEmpty(q))
	{
	    p=Dequeue(&q);
		if(p->lchild)
		{
		    printf("%d ",p->lchild->data);
			Enqueue(&q,p->lchild);     	
		}
		
		if(p->rchild)
		{
			printf("%d ",p->rchild->data);
			Enqueue(&q,p->rchild);
		}
	}
	
	printf("\n\n---------------------------------------------------------------\n");
}

int countTotalNodes(struct Element *p)
{
    int x,y;
	
	if(p!=NULL)
	{
		x=countTotalNodes(p->lchild);
		y=countTotalNodes(p->rchild);
		return(x+y+1);
	}
	return(0);
} 

int countNodesMaximumDegree(struct Element *p)
{
	int x,y;
	
	if(p!=NULL)
	{
		x=countNodesMaximumDegree(p->lchild);
		y=countNodesMaximumDegree(p->rchild);
		if(p->lchild && p->rchild)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

int countInternalNodes(struct Element *p)
{
	int x,y;
	
	if(p!=NULL)
	{
		x=countInternalNodes(p->lchild);
		y=countInternalNodes(p->rchild);
		if(p->lchild || p->rchild)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

int countExternalNodes(struct Element *p)
{
	int x,y;
	
	if(p!=NULL)
	{
		x=countExternalNodes(p->lchild);
		y=countExternalNodes(p->rchild);
		if(p->lchild==NULL && p->rchild==NULL)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

int countNodesDegree1(struct Element *p)
{
	int x,y;
	
	if(p!=NULL)
	{
		x=countNodesDegree1(p->lchild);
		y=countNodesDegree1(p->lchild);
		if((p->lchild==NULL && p->rchild) || (p->lchild && p->rchild==NULL)) // if(p->lchild ^ p->rchild)
		    return(x+y+1);
		else
		    return(x+y);
	}
	return(0);
}

int Height(struct Element *p)
{
	int x,y;
	
	if(p!=NULL)
	{
		x=Height(p->lchild);
		y=Height(p->rchild);
		if(x>y)
		    return(x+1);
		else
		    return(y+1);
	}
	return(0);
}

struct Element * RSearch_BST(struct Element *p,int key)
{
	if(p==NULL)
	    return(NULL);
	
	if(key==p->data)
	    return(p);
	    
	else if(key<p->data)
	    return RSearch_BST(p->lchild,key);
	
	else
	    return RSearch_BST(p->rchild,key);
}

struct Element * ISearch_BST(struct Element *p,int key)
{
	while(p)
	{
		if(key==p->data)
		    return p;
		    
		else if(key<p->data)
		    p=p->lchild;
		
		else
		    p=p->rchild;
	}
    return (NULL);	
}

void IInsert_BST(struct Tree *t,int key)
{
	struct Element *q=NULL,*p=t->root;
	
	if(t->root==NULL)
	{
		t->root=(struct Element *)malloc(sizeof(struct Element));
		t->root->data=key;
		t->root->lchild=t->root->rchild=NULL;
	}
	
	while(p)
	{
		q=p;
		if(key==p->data)
		    return;
		    
		else if(key<p->data)
		    p=p->lchild;
		
		else
		    p=p->rchild;
	}
	
	p=(struct Element *)malloc(sizeof(struct Element));
	p->data=key;
	p->lchild=p->rchild=NULL;
	
	if(key<q->data)
	    q->lchild=p;
	    
	else
	    q->rchild=p;
	
	t->size++;
}

struct Element * RInsert_BST(struct Tree *t,struct Element *p,int key)
{
	if(p==NULL)
	{
		struct Element *temp=NULL;
		temp=(struct Element *)malloc(sizeof(struct Element));
		temp->data=key;
		temp->lchild=temp->rchild=NULL;
		if(t->root==NULL)
		    t->root=temp;
		
		return(temp);
	}
	
	if(key==p->data)
	    return p;
	    
	else if(key<p->data)
	    p->lchild=RInsert_BST(t,p->lchild,key);
	    
	else
	    p->rchild=RInsert_BST(t,p->rchild,key);
	    
	return(p);
	
}

int main()
{
    struct Tree t;
    struct Element *e=NULL;
    int key;
    
    createTree(&t);
    
    
    IPreorder(t);
    
	printf("Enter A Key :\n");
    scanf("%d",&key);
    
	e=RSearch_BST(t.root,key);
	
	if(e)
	    printf("\n%d is Found\n",key);
	    
	else
	    printf("\n%d is Not Found\n",key);
	
	return(0);
}
