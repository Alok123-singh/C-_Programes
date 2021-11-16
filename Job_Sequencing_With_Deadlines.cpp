#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	printf("Enter total jobs :\n");
	scanf("%d",&n);
	
	int profit[n];
	int deadline[n];
	
	printf("\nEnter profit of each job :\n");
	for(int i=0; i<n; i++)
	    scanf("%d",profit+i);
	
	printf("\nEnter deadline of each job :\n");
	for(int i=0; i<n; i++)
	    scanf("%d",deadline+i);
	
	int max=*max_element(deadline,deadline+n);
	
	int temp[n];
	for(int i=0;i<n;i++)
	    temp[i]=profit[i];
	
	int slot[max]={0};
	int te=0;
	while(te<max)
	{
		int index=max_element(temp,temp+n)-temp;
		int j=deadline[index]-1;
		while(j>=0)
		{
			if(slot[j]==0)
			{
				slot[j]=index;
				++te;
				break;
			}
			--j;
		}
		temp[index]=-1;
	}
	
	int maxprofit=0;
	for(int i=0; i<max; i++)
	    maxprofit+=profit[slot[i]];
	
	printf("\nMaximum profit is : %d\n",maxprofit);
	
	return(0);
}

