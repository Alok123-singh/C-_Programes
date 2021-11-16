#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

struct HashTable
{
	struct Node **HT;
	int size;
	int ne;
};

void I(struct HashTable *H,int size)
{
    int i;
    
	H->size=size;
	H->ne=0;
	H->HT=(struct Node **)malloc(H->size*sizeof(struct Node *));
	
    for(i=0;i<size;i++)
        *(H->HT+i)=NULL;
}

int Hash(int key)
{
	return(key)%10;
}

void Insert(struct HashTable *H,int key)
{
	int index=Hash(key);
	struct Node *q=NULL,*p=*(H->HT+index),*temp=NULL;
	
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=key;
	temp->next=NULL;
	
	if(p==NULL)
		*(H->HT+index)=temp;
	else
	{
		while(p && key>=p->data)
		{
			q=p;
			p=p->next;
		}
		temp->next=p;
		if(q)
		    q->next=temp;
		else
		    *(H->HT+index)=temp;
	}
	H->ne++;
}

bool Search(struct HashTable H,int key)
{
	int index=Hash(key);
	struct Node *p=*(H.HT+index);
	
	if(p!=NULL)
	{
		while(p && key>=p->data)
		{
			if(key==p->data)
			    return(true);
			p=p->next;
		}
	}
	return(false);
}

int Delete(struct HashTable *H,int key)
{
	int x=-1,index=Hash(key);
	struct Node *p=*(H->HT+index),*q=NULL;
	
	if(p)
	{
		while(p && key>=p->data)
		{
			if(key==p->data)
			{
				x=p->data;
				if(q==NULL)
				{
					*(H->HT+index)=p->next;
					p->next=NULL;
					free(p);
				}
				else
				{
                    q->next=p->next;
					p->next=NULL;
					free(p);					
 				}
 				H->ne--;
			}
			q=p;
			p=p->next;
		}
	}
	return(x);
}

void Display(struct HashTable H)
{
	struct Node *p=NULL;
	int i;
	
	printf("\n----------------------------------------------------------------------------------------\n\n");
	printf("Total Number Of Elements In Hash Table Are : %d\n",H.ne);
	printf("Size Of The Hash Table Is : %d\n",H.size);
	printf("\nHash Table Is As Follows :\n");
	for(i=0;i<H.size;i++)
	{
		p=*(H.HT+i);
		printf("\nElements Having Last Digit As %d Are As Follows : ",i);
		while(p)
		{
            if(p)			
			    printf("%d  ",p->data);
			p=p->next;
		}
		printf("\n");
	}
	
	printf("\n----------------------------------------------------------------------------------------\n\n");
}

int main()
{
	struct HashTable H;
	int search=55,del=0;
	int i;
	
    I(&H,10);
	
    for(i=0;i<=150;i++)
        Insert(&H,i);
	
	Delete(&H,del);
	
	if(Search(H,search))
	    printf("\nElement %d is Found\n",search);
	else
	    printf("\nElement %d is Not Found\n",search);
	
	Display(H);
	
	return(0);
}

