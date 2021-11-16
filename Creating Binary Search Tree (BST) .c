#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
};

struct BST
{
	struct Node *root;
	int size;
};

struct Stack
{
	int rear;
	int size;
	struct Node **q;
};

void IStack(struct Stack *s,int size)
{
	int i;
	
	s->size=size;
	s->rear=-1;
	s->q=(struct Node **)malloc(size*sizeof(struct Node *));
	
	for(i=0;i<size;i++)
	    *(s->q+i)=NULL;
}

void Push(struct Stack *s,struct Node *add)
{
	if(s->rear==s->size-1)
	    printf("\nStack Overflow\n");
	    
	else
	{
	    s->rear++;
		*(s->q+s->rear)=add;
	}
}

struct Node * Pop(struct Stack *s)
{
	struct Node *p=NULL;
	
	if(s->rear==-1)
	    printf("\nStack Underflow\n");
	    
	else
	{
		p=*(s->q+s->rear);
		*(s->q+s->rear)=NULL;
		s->rear--;
	}
    
	return(p);
}

struct Node * StackTop(struct Stack s)
{
    if(s.rear==-1)
	    return(NULL);
		
	return(*(s.q+s.rear));	
}

bool isEmptyStack(struct Stack s)
{
	if(s.rear==-1)
	    return(true);
	    
	return(false);
}

bool isFullStack(struct Stack s)
{
	if(s.rear==s.size-1)
	    return(true);
	    
	return(false);
}

void I(struct BST *t,int size)
{
    t->root=NULL;
    t->size=0;
}

void IInsert(struct BST *t,int key)
{
	struct Node *r=NULL,*q=NULL,*p=t->root;
	
	if(p==NULL)
	{
		r=(struct Node *)malloc(sizeof(struct Node));
		r->lchild=r->rchild=NULL;
		r->data=key;
		t->root=r;
		t->size++;
	}
	
	else
	{
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
		r=r=(struct Node *)malloc(sizeof(struct Node));
		r->lchild=r->rchild=NULL;
		r->data=key;
		
		if(key<q->data)
		    q->lchild=r;
		else
		    q->rchild=r;
		
		t->size++;
	}
	
}

struct Node * RInsert(struct BST *t,struct Node *p,int key)
{
	if(p==NULL)
	{
		struct Node *temp=NULL;
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data=key;
		temp->lchild=temp->rchild=NULL;
		if(t->root==NULL)
		    t->root=temp;
        
        t->size++;
		return(temp);
	}
	
	if(key==p->data)
	    return p;
	    
	else if(key<p->data)
	    p->lchild=RInsert(t,p->lchild,key);
	    
	else
	    p->rchild=RInsert(t,p->rchild,key);
	    
	return(p);
}

struct Node * RSearch(struct Node *p,int key)
{
	if(p==NULL)
	    return(NULL);
	
	if(key==p->data)
	    return p;
	    
	else if(key<p->data)
	    return(RSearch(p->lchild,key));
	    
	else
	    return(RSearch(p->rchild,key));
	
}

struct Node * ISearch(struct Node *p,int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
		    return(p);
		    
		else if(key<p->data)
		    p=p->lchild;
		    
		else
		    p=p->rchild;
	}
	return(NULL);
}

struct Node * IInPre(struct Node *p)
{
	while(p->rchild)
	    p=p->rchild;
	    
	return(p);
}

struct Node * RInPre(struct Node *p)
{
	if(p->rchild==NULL)
	    return(p);
	    
	return RInPre(p->rchild);
}

struct Node * IInSucc(struct Node *p)
{
	while(p->lchild)
	    p=p->lchild;
	    
	return(p);
}

struct Node * RInSucc(struct Node *p)
{
    if(p->lchild==NULL)
	    return(p);
		
	return RInSucc(p->lchild);	
}

int Height(struct Node *p)
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

struct Node * RDelete(struct BST *t,struct Node *p,int key)
{
	struct Node *q=NULL;
	
	if(p==NULL)
	    return(NULL);
    
	if(p->lchild==NULL && p->rchild==NULL)
	{
		if(t->root==p)
		    t->root=NULL;
		
		free(p);
		t->size--;
		return(NULL);
	}
	
	if(key<p->data)
	    p->lchild=RDelete(t,p->lchild,key);
	
	else if(key>p->data)
	    p->rchild=RDelete(t,p->rchild,key);
	
	else
	{
		if(Height(p->lchild)>Height(p->rchild))
		{
			q=RInPre(p->lchild);
			p->data=q->data;
			p->lchild=RDelete(t,p->lchild,q->data);
		}
		else
		{
			q=RInSucc(p->rchild);
			p->data=q->data;
			p->rchild=RDelete(t,p->rchild,q->data);
		}
	}
	
	return(p);
}

void createPre(struct BST *t,int pre[],int n)
{
	struct Node *p=NULL,*temp=NULL;
	struct Stack stk;
	int i=0;
	
	IStack(&stk,n);
	t->root=(struct Node *)malloc(sizeof(struct Node));
	t->root->data=*(pre+i++);
	t->root->lchild=t->root->rchild=NULL;
	p=t->root;
	t->size++;
	
	while(i<n)
	{
		if(*(pre+i)<p->data)
		{
			temp=(struct Node *)malloc(sizeof(struct Node));
			temp->data=*(pre+i++);
			temp->lchild=temp->rchild=NULL;
			p->lchild=temp;
			Push(&stk,p);
			p=temp;
			t->size++;
		}
		
		else
		{
	        if(*(pre+i)>p->data && *(pre+i) < (isEmptyStack(stk) ? INT_MAX:StackTop(stk)->data))
		    {
		        temp=(struct Node *)malloc(sizeof(struct Node));
			    temp->data=*(pre+i++);
			    temp->lchild=temp->rchild=NULL;
			    p->rchild=temp;
			    p=temp;
			    t->size++;
		    }
		    
		    else
		        p=Pop(&stk);
	    }
	}
}

void createPost(struct BST *t,int post[],int n)
{
	struct Node *p=NULL,*temp=NULL;
	struct Stack stk;
	int i=n-1;
	
	IStack(&stk,n);
	t->root=(struct Node *)malloc(sizeof(struct Node));
	t->root->data=*(post+i--);
	t->root->lchild=t->root->rchild=NULL;
	p=t->root;
	t->size++;
	
	while(i>=0)
	{
		if(*(post+i)>p->data)
		{
			temp=(struct Node *)malloc(sizeof(struct Node));
			temp->data=*(post+i--);
			temp->lchild=temp->rchild=NULL;
			p->rchild=temp;
			Push(&stk,p);
			p=temp;
			t->size++;
		}
		
		else
		{
	        if(*(post+i)<p->data && *(post+i) > (isEmptyStack(stk) ? INT_MIN:StackTop(stk)->data))
		    {
		        temp=(struct Node *)malloc(sizeof(struct Node));
			    temp->data=*(post+i--);
			    temp->lchild=temp->rchild=NULL;
			    p->lchild=temp;
			    p=temp;
			    t->size++;
		    }
		    
		    else
		        p=Pop(&stk);
	    }
	}
}

void Inorder(struct Node *p,int size)
{
	static int i=0,count=0,j=0;
	if(j==0)
	{
        printf("\n---------------------------------------------------------------------------\n\n");
        printf("In Order Traversal Of This BST(Binary Search Tree) Is As Follows :\n");
	}
	
    if(p)
    {
    	j++;
		Inorder(p->lchild,size);
		
		printf("%d  ",p->data);
		count++;
    	++i;
    	Inorder(p->rchild,size);
	}
	
	if(count==size)
	{
	    printf("\n\nSize Of The Tree Is : %d",count);
	    count=0;
		printf("\n\n---------------------------------------------------------------------------\n");
	}
}

void Preorder(struct Node *p,int size)
{
	static int i=0,count=0;
	if(i==0)
	{
        printf("\n-----------------------------------------------------------\n\n");
        printf("Pre Order Traversal Of This Tree Is As Follows :\n");
	}
	
    if(p)
    {
		printf("%d  ",p->data);
    	
		count++;
    	++i;
    	Preorder(p->lchild,size);
    	Preorder(p->rchild,size);
	}
	
	if(count==size)
	{
	    printf("\n\nSize Of The Tree Is : %d",count);
	    count=0;
		printf("\n\n-----------------------------------------------------------\n");
	}
}

void Postorder(struct Node *p,int size)
{
	static int i=0,count=0,j=0;
	if(j==0)
	{
        printf("\n-----------------------------------------------------------\n\n");
        printf("Post Order Traversal Of This Tree Is As Follows :\n");
	}
	
    if(p)
    {
    	j++;
    	Postorder(p->lchild,size);
    	Postorder(p->rchild,size);
    	
		printf("%d ",p->data);
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

int main()
{
	struct BST t;
	int *post=NULL,size,i;
	/*
	printf("Enter Size Of Post order Array :\n");
	scanf("%d",&size);
	
    post=(int *)malloc(size*sizeof(int));
		
	for(i=0;i<size;i++)
	{
		printf("\nEnter %d Element :\n",i+1);
		scanf("%d",post+i);
	}
	*/
	I(&t,0);
	
	//createPost(&t,post,size);
	
	RInsert(&t,t.root,25);
	RInsert(&t,t.root,15);
	RInsert(&t,t.root,5);
	RInsert(&t,t.root,20);
	RInsert(&t,t.root,35);
	RInsert(&t,t.root,30);
	RInsert(&t,t.root,40);
	
	Preorder(t.root,t.size);
	
	//RDelete(&t,t.root,10);

	//printf("\nAfter Deletion :\n");
	//Preorder(t.root,t.size);
	
	return(0);
}









