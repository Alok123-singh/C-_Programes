#include <bits/stdc++.h>
using namespace std;

/* limitation of fast input output(I/O) is that when you will call cout before cin 
then cin will be called first then cout will be called during runtime */

int main()
{
	int *arr=new int[6];
	ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cout<<"Enter Array :\n";
	for(int i=0;i<6;i++)
	    cin>>*(arr+i);
	
	sort(arr,arr+6); /* it will sort the array (in O(nlogn) time) between index 0 and index 6 
	                    where 0 is inclusive and 6 is exclusive */
	
	cout<<"\nMaximum Element In Array : "<<*max_element(arr,arr+6); /* it will return
	the maximum element between index 4 and index 6 where 4 is inclusive and 6 is
	exclusive */
	
	cout<<"\nMinimum Element In Array : "<<*min_element(arr,arr+6); /* it will return
	the minimum element between index 4 and index 6 where 4 is inclusive and 6 is
	exclusive */
	
	cout<<"\n\nIndex Of Maximum Element In Array : "<<max_element(arr,arr+6)-arr;
	/* max_element(arr,arr+n) returns the address of the maximum element variable and we can
	get the index of that maximum variable element by subtracting address of first element 
	(i.e. arr) from max_element(arr,arr+n) */
	
	cout<<"\nIndex Of Minimum Element In Array : "<<min_element(arr,arr+6)-arr;
	/* min_element(arr,arr+n) returns the address of the minimu element varibale and we can
	get the index of that minimum variable element by subtracting address of first element 
	(i.e. arr) from min_element(arr,arr+n) */
	
	reverse(arr+4,arr+6); /* It will reverse the array between index 4 and index 6 
	                         where 4 is inclusive and 6 is exclusive */
	
	cout<<"\n\nReversed Array : ";
	for(int i=0;i<6;i++)
	    cout<<*(arr+i)<<" ";
	
	return(0);
}
