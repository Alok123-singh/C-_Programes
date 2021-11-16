#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
using namespace std;

int longest_band(int arr[],int n) // total time complexicity is O(N)
{
    int longest = 0;
    unordered_set<int> s; for(int i=0; i<n; i++) s.insert(arr[i]);
    
    for(int i=0; i<n; i++) // O(N)
    {
    	// check if it is the head of band or not
    	
		if(s.find(arr[i]-1) == s.end()) // arr[i] is the head of a band
		{
			int cnt = 1,temp = arr[i];
			while(s.find(temp+1) != s.end()) cnt++,temp++; // this while loop is O(N) for all the elements of arr
			longest = max(longest,cnt);
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
    	int n = 12; //cin>>n;
    	int arr[n] = {1,9,3,0,18,5,2,4,10,7,12,6}; //for(int i=0; i<n; i++) cin>>arr[i];
    	cout<<longest_band(arr,n)<<endl;
	}
    
	return 0;
}

