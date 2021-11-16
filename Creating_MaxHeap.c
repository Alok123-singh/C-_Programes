#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#ifndef nullptr

#define nullptr 0;

#endif

struct MaxHeap
{
	int *q;
	int size;
	int length;
};

void I(struct MaxHeap *mh,int size)
{
	int i;
	
	mh->q=(int *)malloc(size*sizeof(int));
	mh->size=size;
	mh->length=0;
	
	for(i=0;i<size;i++)
	    *(mh->q+i)=-1;
}

void Insert(struct MaxHeap *mh,int key)
{
	int i=mh->length;
	int temp=key;
	
	if(mh->length==mh->size)
	{
		printf("\nHeap Overflow\n");
		return;
	}
	
	*(mh->q+mh->length)=key;
	
	while(i>0 && temp>*(mh->q+(i%2==0?(i/2)-1:i/2)))
	{
		*(mh->q+i)=*(mh->q+(i%2==0?(i/2)-1:i/2));
		i=i%2==0?(i/2)-1:i/2;
	}
	
	mh->length++;
	*(mh->q+i)=key;
}

void createHeap(struct MaxHeap *mh)
{
	int length;
	int i,x;
	
	printf("Enter The Length Of The Max Binary Heap :\n");
	scanf("%d",&length);
	
	printf("\nEnter The Elements In Max Binary Heap :\n");
	for(i=0;i<length;i++)
	{
		printf("\nEnter %d Element :\n",i+1);
		scanf("%d",&x);
		Insert(mh,x);
	}
}

int Delete(struct MaxHeap *mh)
{
	int x=-1,i=0,j;
	int *A=(int *)malloc(mh->size*sizeof(int)),n=0,k,l;
	int temp=*(mh->q+mh->length-1),max,t;
	
	for(k=0,l=mh->length;*(mh->q+l)!=-1;k++,l++)
	{
	    *(A+k)=*(mh->q+l);
	    n++;
    }
    
	for(k=mh->length;*(mh->q+k)!=-1;k++)
	    *(mh->q+k)=-1;    
	
	if(mh->length>0)
	{
	    x=*(mh->q);
	    *(mh->q)=temp;
	    *(mh->q+mh->length-1)=-1;
    }
    else
        printf("\nHeap Underflow\n");
    
    while((*(mh->q+2*i+1)!=-1 && *(mh->q+2*i+2)!=-1) || (2*i+1<mh->size || 2*i+2<mh->size))
    {
    	j=i;
    	i=*(mh->q+2*i+1)>*(mh->q+2*i+2)?2*i+1:2*i+2;
    	max=*(mh->q+i);
    	
    	if(temp<max)
    	{
    		t=*(mh->q+j);
    		*(mh->q+j)=*(mh->q+i);
    		*(mh->q+i)=t;
		}
		else
		    break;
	}
	
	for(k=0,l=mh->length;k<n;k++,l++)
	    *(mh->q+l)=*(A+k);
	
	*(mh->q+mh->length-1)=x;
	mh->length--;
	
	return(x);
}

void HeapSort(struct MaxHeap *mh)
{
	int i,j,l=mh->length;
	
	printf("\n-------------------------------------------------------------------\n\n");
	for(i=1;i<=l;i++)
	   	Delete(mh);
	
	printf("After Heap Sort, the Max Binary Heap Is As Follows :\n");
	for(j=0;*(mh->q+j)!=-1;j++)
	    printf("%d  ",*(mh->q+j));
	printf("\n\n-------------------------------------------------------------------\n");
}

void Heapify(struct MaxHeap *mh)
{
	int i,j,k;
	int temp;
	
	printf("\nEnter Length Of The Max Binary Heap :\n");
	scanf("%d",&mh->length);
	
	printf("\nEnter The Elements In Max Binary Heap :\n");
	
	for(j=0;j<mh->length;j++)
	{
		printf("\nEnter %d Element :\n",j+1);
		scanf("%d",mh->q+j);
	}
	
	i=mh->length-1;
	while(i>=0)
	{
		if(*(mh->q+2*i+1)!=-1 || *(mh->q+2*i+2)!=-1)
		{
			k=i;
			while(2*k+1<mh->length || 2*k+2<mh->length)
			{
				j=k;
				k=*(mh->q+2*k+1)>*(mh->q+2*k+2)?2*k+1:2*k+2;
				
				if(*(mh->q+j)<*(mh->q+k))
				{
					temp=*(mh->q+j);
					*(mh->q+j)=*(mh->q+k);
					*(mh->q+k)=temp;
				}
				else
				    break;
			}
		}
		--i;
	}
	
}

void Display(struct MaxHeap mh)
{
	int i;
	
	printf("\n-------------------------------------------------------------------\n\n");
	printf("Length Of The Max Binary Heap Is : %d\n\n",mh.length);
	printf("Max Binary Heap Is As Follows :\n");
	if(mh.length!=0)
	    printf("%d  ",*(mh.q));
	for(i=0;i<mh.length;i++)
	{
		if((2*i+1)<mh.length)
		    printf("%d  ",*(mh.q+2*i+1));
		    
		if((2*i+2)<mh.length)
		    printf("%d  ",*(mh.q+2*i+2));
	}
	
	printf("\n\n-------------------------------------------------------------------\n");
}

bool isEmptyHeap(struct MaxHeap mh)
{
	if(mh.length==0)
	    return true;
	
	return(false);
}

bool isFullHeap(struct MaxHeap mh)
{
	if(mh.length==mh.size)
	    return(true);
	
	return(false);
}

int main()
{
	struct MaxHeap mh;
	
	I(&mh,40);
	
	Heapify(&mh);
	
	Display(mh);

    HeapSort(&mh);
    
	return(0);
}









