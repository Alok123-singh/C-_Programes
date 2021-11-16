#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef nullptr

#define nullptr 0

#endif

struct Node
{
	struct Node *fchild;
	int data1;
	struct Node *schild;
	int data2;
	struct Node *tchild;
};

struct B3
{
    struct Node *root;
};

void I(struct B3 *b3)
{
	b3->root=NULL;
}

struct Node * RInsert(struct B3 *b3,struct Node *p,int key)
{
	struct Node *q=NULL,*r=NULL;
	static int res=1,ins=0;
	int x=-1;
	
	if(b3->root==NULL)
	{
		b3->root=(struct Node *)malloc(sizeof(struct Node));
		b3->root->data1=key;
		b3->root->data2=-1;
		b3->root->fchild=b3->root->schild=b3->root->tchild=NULL;
	}
	
	if(p==NULL)
	    return(NULL);
	
	if(key<p->data1)
	    q=RInsert(b3,p->fchild,key);
	    
	else if(key>p->data1 && key<p->data2)
	    q=RInsert(b3,p->schild,key);
	    
	else if(key>p->data2)
	    q=RInsert(b3,p->tchild,key);
	    
	else if(key==p->data1 || key==p->data2)
	    res=0;
	    
	if(res!=0)
	{
		if(q!=NULL)
		{
			int y=-1;
			if(q->data1<p->data1)
			    y=p->data1;
			    
			else if(q->data1<p->data2)
			    y=p->data2;
			    
			if(p->data2==-1)
			{
				p->data2=p->data1;
				p->data1=q->data1;
			}
			
			else if(y==-1)
			    p->data2=q->data1;
			
			if(q->fchild->data1<p->data1)    
			    p->fchild=q->fchild;
			    
			else if(q->fchild->data1>p->data1 && q->fchild->data1<p->data2)
			    p->schild=q->fchild;
			
		    if(q->schild->data1>p->data1 && q->schild->data1<p->data2)
		        p->schild=q->schild;
		        
		    else if(q->schild->data1>p->data2)
		        p->tchild=q->schild;
		        
		    key=q->data1;
		}
		
        if(key<p->data1)
            x=p->data1;
            
        else if(key<p->data2)
            x=p->data2;
            
        if(p->data2==-1)
        {
        	if(x==p->data1 && ins==0)
        	{
        		p->data2=p->data1;
        		p->data1=key;
			}
			else if(x==p->data2 && ins==0)
		    	p->data2=key;
		    ins=1;
		}
		else
		{
		    q=(struct Node *)malloc(sizeof(struct Node));
			r=(struct Node *)malloc(sizeof(struct Node));
			if(x==p->data1)
			{
			    q->data1=p->data1;
				r->data1=p->data2;
				p->data1=key;
			}
			else if(x==p->data2)
			{
				q->data1=key;
				r->data1=p->data2;
			}
			else if(x==-1)
			{
				q->data1=p->data2;
				r->data1=key;
			}
			p->data2=q->data2=r->data2=-1;
			
			q->fchild=p;
			q->schild=r;
			
			q->tchild=NULL;
			p->fchild=p->schild=p->tchild=NULL;
			r->fchild=r->schild=r->tchild=NULL;
			
			if(b3->root==q->fchild || b3->root==q->schild)
			    b3->root=q;
			ins=1;
		}
	    
	}
	
	return(q);
}

void RDisplay(struct Node *p)
{
	if(p)
	{
		if(p->data1!=-1)
		    printf("%d  ",p->data1);
		if(p->data2!=-1)
		    printf("%d  ",p->data2);
		RDisplay(p->fchild);
        RDisplay(p->schild);
		RDisplay(p->tchild);
		
	}
}

int main()
{
	struct B3 b3;
	
	I(&b3);
	
	RInsert(&b3,b3.root,10);
	RInsert(&b3,b3.root,20);
	RInsert(&b3,b3.root,30);
	RInsert(&b3,b3.root,25);
	//RInsert(&b3,b3.root,35);
	
	printf("\n2-3 Tree Is As Follows :\n");
	//printf("%d  %d  %d",b3.root->fchild->data1,b3.root->data1,b3.root->tchild->data1);
	RDisplay(b3.root);
	printf("\n");
	
	return(0);
}









