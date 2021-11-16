#include <stdio.h>
#include <stdlib.h>
#ifndef SIZE
#define SIZE 11
#endif

struct HashTable
{
	int *HT;
	int size;
	int ne;
};

void I(struct HashTable *H)
{
	int i;
	
	H->size=SIZE;
	H->ne=0;
	H->HT=(int *)malloc(SIZE*sizeof(int));
	for(i=0;i<SIZE;i++)
	    *(H->HT+i)=-1;
}

int Hash(int key)
{
	return(key)%10;
}

int Probe(struct HashTable *H,int key)
{
	int index=Hash(key);
	int i=0;
	
	while(*(H->HT+(index+i)%SIZE)!=-1)
	    i++;	
    return ((index+i)%SIZE);	
}

void Insert(struct HashTable *H,int key)
{
    int index=Hash(key);
    
	if(*(H->HT+index)!=-1)
	    index=Probe(H,key);
	    
	*(H->HT+index)=key;
	H->ne++;
}

int Search(struct HashTable H,int key)
{
	int index=Hash(key);
	int i=0;
	
	while(*(H.HT+(index+i)%SIZE)!=key)
	{
		if(*(H.HT+(index+i)%SIZE)==-1)
		    return(-1);
		i++;
	}
	
	return(index+i);
}

void Display(struct HashTable H)
{
	int i;
	
	printf("\n-----------------------------------------------------------------------------\n\n");
	printf("Size Of The Hash Table Is As Follows : %d\n",H.size);
    printf("Total Number Of Elements In The Hash Table Are As Follows : %d\n",H.ne);
	printf("\nHash Table Created By Using Linear Probing Is As Follows :\n");
	for(i=0;i<H.size;i++)
	{
	    printf("\nElement At Index %d Is As Follows : ",i);
		if(*(H.HT+i)!=-1)
		    printf("%d",*(H.HT+i));
		printf("\n");
	}
	printf("\n-----------------------------------------------------------------------------\n\n");
}

int main()
{
	struct HashTable H;
	int x=26;
	
	I(&H);
	
	Insert(&H,12);
	Insert(&H,25);
	Insert(&H,35);
	Insert(&H,26);
	
    printf("\nElement %d Is Found At %d\n",x,Search(H,x));
	
	Display(H);	
	
	return(0);
}
