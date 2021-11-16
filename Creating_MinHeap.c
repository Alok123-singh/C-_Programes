#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#ifndef nullptr

#define nullptr 0;

#endif

struct MinHeap
{
	int *q;
	int size;
	int length;
};

void I(struct MinHeap *mh,int size)
{
	int i;
	
	mh->q=(int *)malloc(size*sizeof(int));
	mh->size=size;
	mh->length=0;
	
	for(i=0;i<size;i++)
	    *(mh->q+i)=INT_MAX;
}

void Insert(struct MinHeap *mh,int key)
{
	int i=mh->length;
	int temp=key;
	
	if(mh->length==mh->size)
	{
		printf("\nHeap Overflow\n");
		return;
	}
	
	*(mh->q+mh->length)=key;
	
	while(i>0 && temp<*(mh->q+(i%2==0?(i/2)-1:i/2)))
	{
		*(mh->q+i)=*(mh->q+(i%2==0?(i/2)-1:i/2));
		i=i%2==0?(i/2)-1:i/2;
	}
	
	*(mh->q+i)=key;
    mh->length++;
}

void createHeap(struct MinHeap *mh)
{
	int length;
	int i,x;
	
	printf("Enter The Length Of The Min Binary Heap :\n");
	scanf("%d",&length);
	
	printf("\nEnter The Elements In Min Binary Heap :\n");
	for(i=0;i<length;i++)
	{
		printf("\nEnter %d Element :\n",i+1);
		scanf("%d",&x);
		Insert(mh,x);
	}
}

int Delete(struct MinHeap *mh)
{
	int x=-1,i=0,j;
	int *A=(int *)malloc(mh->size*sizeof(int)),n=0,k,l;
	int temp=*(mh->q+mh->length-1),t;
	
	for(k=0,l=mh->length;*(mh->q+l)!=INT_MAX;k++,l++)
	{
	    *(A+k)=*(mh->q+l);
	    n++;
    }
    
	for(k=mh->length;*(mh->q+k)!=INT_MAX;k++)
	    *(mh->q+k)=INT_MAX;  
	
	if(mh->length>0)
	{
	    x=*(mh->q);
	    *(mh->q)=temp;
	    *(mh->q+mh->length-1)=INT_MAX;
    }
    else
    {
        printf("\nHeap Underflow\n");
        return (x);
	}
    
    while((*(mh->q+2*i+1)!=INT_MAX && *(mh->q+2*i+2)!=INT_MAX) || (2*i+1<mh->size || 2*i+2<mh->size))
    {
    	j=i;
    	i=*(mh->q+2*i+1)<*(mh->q+2*i+2)?2*i+1:2*i+2;
    	
    	if(temp>*(mh->q+i))
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

void HeapSort(struct MinHeap *mh)
{
	int i,j,l=mh->length;
	
	printf("\n-------------------------------------------------------------------\n\n");
	for(i=1;i<=l;i++)
	   	Delete(mh);
	
	printf("After Heap Sort, the Min Binary Heap Is :\n");
	for(j=0;*(mh->q+j)!=INT_MAX;j++)
	    printf("%d  ",*(mh->q+j));
	printf("\n\n-------------------------------------------------------------------\n");
}

void Heapify(struct MinHeap *mh)
{
	int i,j,k,l;
	int temp;
	
	printf("Enter Length Of The Min Binary Heap :\n");
	scanf("%d",&mh->length);
	
	printf("\nEnter The Elements In Min Binary Heap :\n");
	
	for(j=0;j<mh->length;j++)
	{
		printf("\nEnter %d Element :\n",j+1);
		scanf("%d",mh->q+j);
	}
	
	i=mh->length-1;
	while(i>=0)
	{
		if(*(mh->q+2*i+1)!=INT_MAX || *(mh->q+2*i+2)!=INT_MAX)
		{
			k=i;
			while(2*k+1<mh->length || 2*k+2<mh->length)
			{
				j=k;
				k=*(mh->q+2*k+1)<*(mh->q+2*k+2)?2*k+1:2*k+2;
				
				if(*(mh->q+j)>*(mh->q+k))
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

void Display(struct MinHeap mh)
{
	int i;
	
	printf("\n-------------------------------------------------------------------\n\n");
	printf("Length Of The Min Binary Heap Is : %d\n\n",mh.length);
	printf("Min Binary Heap Is As Follows :\n");
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

bool isEmptyHeap(struct MinHeap mh)
{
	if(mh.length==0)
	    return true;
	    
	return(false);
}

bool isFullHeap(struct MinHeap mh)
{
	if(mh.length==mh.size)
	    return(true);
	    
	return(false);
}

int main()
{
	struct MinHeap mh;
	
	I(&mh,40);
	
	Heapify(&mh);
	
	Display(mh);

    HeapSort(&mh);
    
	return(0);
}









