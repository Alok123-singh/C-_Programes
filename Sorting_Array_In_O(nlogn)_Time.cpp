#include <bits/stdc++.h>

#define n 4

using namespace std;

int main()
{
	int arr[n];
	
	cout<<"Enter Array :\n";
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	sort(arr,arr+n);
	
	cout<<"\nSorted Array : ";
	for(int i=0;i<n;i++)
	    cout<<arr[i]<<" ";
	
	return(0);
}
