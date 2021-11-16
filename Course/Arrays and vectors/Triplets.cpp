#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
using namespace std;

vector<pair<ll,ll>> pair_sum(ll arr[],int st,ll n,ll ts)
{
	vector<pair<ll,ll>> ans(0);
	
	ll i = st,j = n-1;
	while(i<j)
	{
		if(arr[i] + arr[j] < ts) i++;
		else if(arr[i] + arr[j] > ts) j--;
		else 
		{
			ans.push_back({arr[i],arr[j]});
			i++;
			j--;
		}
	}
	return(ans);
}

vector<vector<ll>> triplet_solve(ll arr[],ll n,ll ts)
{
	sort(arr,arr+n);
	vector<vector<ll>> ans(0);
	
	for(ll i=0; i<=n-3; i++)
	{
		if(ts - arr[i] < 0) break;
		vector<ll> v(0);
		v.push_back(arr[i]);
		auto p = pair_sum(arr,i+1,n,ts - arr[i]);
	    for(auto x: p)
	    {
	    	v.push_back(x.first);
	    	v.push_back(x.second);
		}
		ans.push_back(v);
	}
	return(ans);
}

int main()
{
	FIO
	int t=1; //cin>>t;
	while(t--)
	{
		ll n=10,ts=18; //cin>>n>>ts;
		ll arr[n] = {1,2,3,4,5,6,7,8,9,15}; //for(int i=0; i<n; i++) cin>>arr[i];
		
		auto ans = triplet_solve(arr,n,ts);
		
		for(auto v: ans) for(int i=1; i<v.size(); i+=2) cout<<"("<<v[0]<<","<<v[i]<<","<<v[i+1]<<")"<<endl;
	}
	
	return 0;
}

