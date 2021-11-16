#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	int *arr1=NULL,*arr2=NULL;
	int sz1,i,j,k,l;
	int min,y;
	
	printf("Enter Size Of Unsorted Array :\n");
	scanf("%d",&sz1);
	
	arr1=(int *)malloc(sz1*sizeof(int));
	arr2=(int *)malloc(sz1*sizeof(int));
	
	printf("Enter Elements In Unsorted Manner :\n");
	for(i=0;i<sz1;i++)
	{
		printf("\nEnter %d Element :\n",i+1);
		scanf("%d",arr1+i);
	}
	
	for(j=0;j<sz1;j++)
	{
		min=INT_MAX;
		for(k=0;k<sz1;k++)
		{
			if(*(arr1+k)<min && *(arr1+k)!=-1)
			{
				min=*(arr1+k);
				y=k;
			}
		}
		
		*(arr2+j)=min;
		*(arr1+y)=-1;
	}
	
	printf("\nSorted Array Is As Follows : ");
	for(l=0;l<sz1;l++)
		printf("%d ",*(arr2+l));
		
	printf("\n");
	
	return(0);
}




