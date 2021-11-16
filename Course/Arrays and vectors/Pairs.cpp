#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
using namespace std;

vector<pair<ll,ll>> pair_solve(ll arr[],ll n,ll ts)
{
	unordered_set<ll> is_present; // if duplicates are not present in arr otherwise use unordered_multiset
	vector<pair<ll,ll>> ans(0);
	
	for(ll i=0; i<n; i++)
	{
		ll temp = ts - arr[i];
		if(is_present.find(temp) != is_present.end()) ans.push_back({arr[i],temp});
		is_present.insert(arr[i]);
	}
	return(ans);
}

int main()
{
	FIO
	int t=1; //cin>>t;
	while(t--)
	{
		ll n=7,ts=4; //cin>>n>>ts;
		ll arr[n] = {10,5,2,3,-6,9,11}; //for(int i=0; i<n; i++) cin>>arr[i];
		auto p = pair_solve(arr,n,ts);
		
		if(!p.size()) cout<<"No pairs"<<endl;
		else
		{
			for(auto ans: p) cout<<"("<<ans.first<<","<<ans.second<<") ";
			cout<<endl;
		}
	}
	return 0;
}

