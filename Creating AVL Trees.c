#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <conio.h>

#ifdef NULL

#define nullptr NULL

#endif

struct Node
{
	struct Node *lchild;
	int data;
	int height;
	struct Node *rchild;
};

struct AVL
{
	struct Node *root;
	int size;
};

void I(struct AVL *avl,int size)
{
	avl->root=NULL;
	avl->size=size;
}

int NodeHeight(struct Node *p)
{
	int hl,hr;
	
	hl=(p && p->lchild)?p->lchild->height:0;
	hr=(p && p->rchild)?p->rchild->height:0;
	
	return hl>hr?hl+1:hr+1;
}

int BalanceFactor(struct Node *p)
{
	int hl,hr;
	
	hl=(p && p->lchild)?p->lchild->height:0;
	hr=(p && p->rchild)?p->rchild->height:0;
	
	return hl-hr;
}

struct Node * LLRotation(struct AVL *avl,struct Node *p)
{
	struct Node *pl=p->lchild;
	
	p->lchild=pl->rchild;
	pl->rchild=p;
	
	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);
	
	if(avl->root==p)
	    avl->root=pl;
	
	return(pl);
}

struct Node * LRRotation(struct AVL *avl,struct Node *p)
{
	struct Node *pl=p->lchild;
	struct Node *plr=pl->rchild;
	
	p->lchild=plr->rchild;
	pl->rchild=plr->lchild;
	plr->lchild=pl;
	plr->rchild=p;
	
	p->height=NodeHeight(p);
	pl->height=NodeHeight(pl);
	plr->height=NodeHeight(plr);
	
	if(avl->root==p)
	    avl->root=plr;
	
	return(plr);
}

struct Node * RLRotation(struct AVL *avl,struct Node *p)
{
	struct Node *pr=p->rchild;
	struct Node *prl=pr->lchild;
	
	p->rchild=prl->lchild;
	pr->lchild=prl->rchild;
	prl->lchild=p;
	prl->rchild=pr;
	
	p->height=NodeHeight(p);
	pr->height=NodeHeight(pr);
	prl->height=NodeHeight(prl);
	
	if(avl->root==p) {
	    avl->root=prl;
    }
	return(prl);
}

struct Node * RRRotation(struct AVL *avl,struct Node *p)
{
	struct Node *pr=p->rchild;
	
	p->rchild=pr->lchild;
	pr->lchild=p;
	
	p->height=NodeHeight(p);
	pr->height=NodeHeight(pr);
	
	if(avl->root==p)
	    avl->root=pr;
	
	return(pr);
}

struct Node * RInsert(struct AVL *avl,struct Node *p,int key)
{
	if(p==NULL)
	{
		struct Node *temp=NULL;
		temp=(struct Node *)malloc(sizeof(struct Node));
		temp->data=key;
		temp->lchild=temp->rchild=NULL;
		temp->height=1;
		
		if(avl->root==NULL)
		    avl->root=temp;
		
		avl->size++;
		return(temp);
	}
	
	if(key==p->data)
	    return(p);
	
	else if(key<p->data)
	    p->lchild=RInsert(avl,p->lchild,key);
	
	else if(key>p->data)
	    p->rchild=RInsert(avl,p->rchild,key);
	
	p->height=NodeHeight(p);
	
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
	    return (LLRotation(avl,p));
	
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
	    return (LRRotation(avl,p));
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
	    return (RLRotation(avl,p));
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
	    return (RRRotation(avl,p));
	
	return(p);
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

struct Node * RDelete(struct AVL *avl,struct Node *p,int key)
{
	struct Node *q=NULL;
	
	if(p==NULL)
	    return(NULL);
	    
	if(p->lchild==NULL && p->rchild==NULL)
	{
		if(avl->root==p)
		    avl->root=NULL;
		
		free(p);
		avl->size--;
		return(NULL);	
	}    
	
	if(key==p->data)
	{
		if(Height(p->lchild)>Height(p->rchild))
		{
			q=IInPre(p->lchild);
			p->data=q->data;
			p->lchild=RDelete(avl,p->lchild,q->data);
		}
		else
		{
			q=IInSucc(p->rchild);
			p->data=q->data;
			p->rchild=RDelete(avl,p->rchild,q->data);
		}
	}
	
	else if(key<p->data)
	    p->lchild=RDelete(avl,p->lchild,key);
	
	else if(key>p->data)
	    p->rchild=RDelete(avl,p->rchild,key);
	
	p->height=NodeHeight(p);
	
	if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1) // L1 Rotation
	    return LLRotation(avl,p);
	
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1) // L-1 Rotation
	    return LRRotation(avl,p);
    
	else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0) // L0 Rotaion
	    return LLRotation(avl,p); // or LRRotation(avl,p);
    
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1) //R1 Rotation
	    return RLRotation(avl,p);
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1) //R-1 Rotation
	    return RRRotation(avl,p);
	
	else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0) //R0 Rotation
	    return RLRotation(avl,p); // or RRRotation(avl,p);
	
	return(p);
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
	struct AVL avl;
	
	I(&avl,0);
	
	RInsert(&avl,avl.root,15);
	RInsert(&avl,avl.root,10);
	RInsert(&avl,avl.root,5);
	
	Preorder(avl.root,avl.size);
	
	RDelete(&avl,avl.root,15);
	
	printf("After Deletion :\n");
	Postorder(avl.root,avl.size);
	
	return(0);
}




