#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

int merge(int arr[],int s,int e) // O(N+M)
{
	int i=s;
	int mid = (s+e)/2;
	int j = mid+1;
	vector<int> temp;
	
	int cnt = 0;
	while(i<=mid && j<=e)
	{
		if(arr[i] <= arr[j]){
			temp.push_back(arr[i++]);
		}
		else{
			cnt += mid - i + 1;
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
	
	return(cnt);
}

int inversion_count(int arr[],int s,int e) // O(NlogN)
{
	//base condition is if only one element is present between s and e then that element is already sorted
	if(s >= e) return 0;
	
	int mid = (s+e)/2;
	int C1 = inversion_count(arr,s,mid);
	int C2 = inversion_count(arr,mid+1,e);
	int CI = merge(arr,s,e);
	return (C1+C2+CI);
}

int main()
{
	int n = {5}; //cin>>n;
	int arr[n] = {0,5,2,3,1}; //for(int i=0; i<n; i++) cin>>arr[i];
	
	cout<< inversion_count(arr,0,n-1) <<endl;
	
	return 0;
}

