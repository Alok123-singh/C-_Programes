#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
using namespace std;

int highest_peak(int arr[],int n)
{
    int longest = 0;
    
    for(int i=1; i<=n-2; )
    {
    	// if arr[i] is a peak or not
    	
    	if(arr[i] > arr[i-1] and arr[i] > arr[i+1])
    	{
    		// do some work
    		int cnt = 1;
    		int j = i;
    		// backward
    		while(j>=1 and arr[j] > arr[j-1])
    		{
    			j--;
    			cnt++;
			}
    		
    		// forward
    		while(i<=n-2 and arr[i] > arr[i+1])
    		{
    			i++;
    			cnt++;
			}
    		
    		longest = max(longest,cnt);
		}
		else
		{
			i++;
		}
	}
	return (longest);
}

int main()
{
	FIO
    int t=1; //cin>>t;
    while(t--)
    {
    	int n = 16; //cin>>n;
    	int arr[n] = {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4}; //for(int i=0; i<n; i++) cin>>arr[i];
    	cout<<highest_peak(arr,n)<<endl;
	}
    
	return 0;
}

