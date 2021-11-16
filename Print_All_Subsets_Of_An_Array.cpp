#include <bits/stdc++.h>
using namespace std;
int tnsubsets=0;
/*
subset and subsequence is same. And subarray is a special type of subsequence in which all the
elements are adjacent/contiguous.
*/
void PrintSubset(int ssa[],int cssi)
{
	printf("{");
	for(int i=0;i<cssi;i++)
	    printf("%d ",ssa[i]);
	printf("}\n");
}
// ci is current index,ssa is subsequence array and cssi is current subsequence index
void PrintAllSubsets(int arr[],int n,int ci,int ssa[],int cssi)
{
	if(ci>=n)
	{
		PrintSubset(ssa,cssi);
		tnsubsets++;
		return;
	}
	PrintAllSubsets(arr,n,ci+1,ssa,cssi);
	ssa[cssi]=arr[ci];
	PrintAllSubsets(arr,n,ci+1,ssa,cssi+1);
}

int main()
{
	int arr[]={1,2,3};
	int ssa[3];
	
	PrintAllSubsets(arr,3,0,ssa,0);
	printf("\nTotal number of subsets/subsequences are : %d\n",tnsubsets);
	return(0);
}
