#include <bits/stdc++.h>
using namespace std;

int main()
{
	array<int,4> arr1,arr2;
	array<int,4>::iterator iter;
	cout<<"Enter 1st Array :\n";
	for(int i=0;i<4;i++)
	    cin>>arr1[i];
	
	cout<<"\nEnter 2nd Array :\n";
	for(int i=0;i<4;i++)
	    cin>>arr2[i];
	
	arr1.swap(arr2); //swaps array a and array bwith each other
	
	cout<<"\nFirst Array : ";
    for(int i=0;i<4;i++)
        cout<<arr1[i]<<" ";
    
    cout<<endl<<"\nSecond Array : ";
    for(int i=0;i<4;i++)
        cout<<arr2[i]<<" ";
    cout<<endl;
	
	return(0);
}
