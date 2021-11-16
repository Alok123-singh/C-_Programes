#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll c=8e4+999;
ll n,sum=0,sub[c];
vector<pair<ll,ll>> adj[c];

void dfs(ll node = 1,ll par = 1)
{
	for(pair<ll,ll> it:adj[node])
	if(it.first!=par)
	{
		dfs(it.first,node);
		sub[node]=sub[node]+sub[it.first];
		sum=sum+sub[it.first]*(n-sub[it.first])*it.second;
	}
	sub[node]++;
}

int main()
{
	for(ll i=0;i<c;i++)
	    sub[i]=0;
	printf("Enter Vertices :\n");
	scanf("%lld",&n);
	
	printf("\nEnter %lld Edges :\n",n-1);
	ll x=n;
	while(x-- > 1)
	{
		ll u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		
		adj[u].emplace_back(pair<int,int>(v,w));
		adj[v].emplace_back(pair<int,int>(u,w));
		//x--;
	}
	
	dfs();
	
	printf("\nAnswer is : %d\n",sum);
	return(0);
}

