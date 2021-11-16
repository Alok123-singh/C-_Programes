#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define pb push_back
using namespace std;

pair<int,int> subarray_sort(int arr[],int n)
{
	int smallest = INT_MAX,largest = INT_MIN;
	for(int i=0; i<n; i++)
	{
		if(i+1<n and arr[i] > arr[i+1])
		{
			smallest = min(smallest,arr[i]);
			largest = max(largest,arr[i]);
		}
		if(i-1>=0 and arr[i] < arr[i-1])
		{
			smallest = min(smallest,arr[i]);
			largest = max(largest,arr[i]);
		}
	}
	
	if(smallest == INT_MAX) return {-1,-1};
	
	int st_pos = 0; while(st_pos<n and arr[st_pos] <= smallest) st_pos++;
    int en_pos = n-1;  while(en_pos >= 0 and arr[en_pos] >= largest) en_pos--;
    
    return {st_pos,en_pos};
}

int main()
{
	FIO
    int t = 1; //cin>>t;
    while(t--)
    {
	    int n = 10; //cin>>n;
	    int arr[n] = {1,2,3,4,5,8,6,7,10,11}; //for(int i=0; i<n; i++) cin>>arr[i];
	    auto ans = subarray_sort(arr,n);
	    cout<<ans.first<<" "<<ans.second<<endl;
	}
    
	return 0;
}

