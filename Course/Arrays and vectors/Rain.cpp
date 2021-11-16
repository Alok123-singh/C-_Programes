#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
using namespace std;

int rain(int height[],int n) // total time complexicity is O(N)
{
	if(n<=2) return(0);
	
    int left[n],right[n];
    left[0] = height[0];
    right[n-1] = height[n-1];
	
	for(int i=1; i<n; i++)
	{
		left[i] = max(left[i-1],height[i]);
		right[n-i-1] = max(right[n-i],height[n-i-1]);
	}
	
	int water = 0; for(int i=0; i<n; i++) water += min(left[i],right[i]) - height[i];
    
	return (water);
}

int main()
{
	FIO
    int t=1; //cin>>t;
    while(t--)
    {
    	int n = 12; //cin>>n;
    	int height[n] = {0,1,0,2,1,0,1,3,2,1,2,1}; //for(int i=0; i<n; i++) cin>>arr[i];
    	cout<<rain(height,n)<<endl;
	}
    
	return 0;
}

