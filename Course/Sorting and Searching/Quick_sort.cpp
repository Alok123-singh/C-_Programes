#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;
// Quick Sort is a divide and conquer algorithm
void swap(vector<int> &arr,int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
/*
   quick sort - average time complexicity is O(NlogN) and worst case time complexicity is O(N^2)
*/
void quick_sort(vector<int> &arr,int st,int en)
{
	// base condition
	if(st >= en){
		return;
	}
	
	int pivot = en;
	int i=st-1;
	int j=st;
	
	/* collecting all elements smaller than the pivot element on one side(left) and elements greater than the pivot
	   element on other side(right). */
	while(j<pivot)
	{
		if(arr[j] > arr[pivot]) j++;
		else
		{
			i++;
			swap(arr,i,j);
			j++;
		}
	}
	// now putting the pivot element on its right position
	swap(arr,i+1,pivot);
	
	// now sorting the elements on left side of pivot element
	quick_sort(arr,st,i);
	// now sorting the elements on right side of pivot element
	quick_sort(arr,i+1,j);
}

int main()
{
	vector<int> arr{10,5,2,0,7,6,4}; // unsorted array
	
	quick_sort(arr,0,arr.size()-1);// after quick sort array is sorted
	
	for(auto x: arr) cout<<x<<" ";
    cout<<endl;
    
	return(0);
}
