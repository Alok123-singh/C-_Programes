#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;
// Merge Sort is a Divide and Conquer method
void merge(int arr[],int s,int e) // O(N+M)
{
	int i=s;
	int mid = (s+e)/2;
	int j = mid+1;
	vector<int> temp;
	
	while(i<=mid && j<=e)
	{
		if(arr[i] < arr[j]){
			temp.push_back(arr[i++]);
		}
		else{
			temp.push_back(arr[j++]);
		}
	}
	
	// copy the remaining elements from array 1
	while(i<=mid){
		temp.push_back(arr[i++]);
	}
    
    // copy the remaining elements from array 2
    while(j<=e){
    	temp.push_back(arr[j++]);
	}
	
	// copy all the elements of temp into arr array
	int k=0;
	for(int idx = s; idx<=e; idx++) arr[idx] = temp[k++];
}

void merge_sort(int arr[],int s,int e) // O(NlogN)
{
	//base condition is if only one element is present between s and e then that element is already sorted
	if(s >= e) return;
	
	// at first divide the current array in two parts through mid
	int mid = (s+e)/2;
	
	// now sorting all the elements on left side of mid
	merge_sort(arr,s,mid);
	
	// now sorting all the elements on right side of mid
	merge_sort(arr,mid+1,e);
	
	// now merging left and right side to get a combined sorted array of both sides
	merge(arr,s,e);
}

int main()
{
	int n = {7}; //cin>>n;
	int arr[n] = {10,5,2,0,7,6,4}; //for(int i=0; i<n; i++) cin>>arr[i]; 
	
	merge_sort(arr,0,n-1);
	
	for(auto x: arr) cout<<x<<" ";
	cout<<endl;
	
	return 0;
}

