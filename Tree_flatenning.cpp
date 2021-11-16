#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define pb push_back
using namespace std;
int values[100001];
vector<int> adj[100001];
vector<int> flattened_tree;
int start_pos[100001];
int en_pos[100001];
int gcd[100001];

void dfs(int node,int par)
{
	flattened_tree.pb(node);
	start_pos[node] = flattened_tree.size()-1;
	for(auto choice: adj[node])
	{
		if(choice != par)
		{
			dfs(choice,node);
		}
	}
	en_pos[node] = flattened_tree.size()-1;
}

void update(int node,int x)
{
	values[node] = x;
}

int query(int node)
{
	int i = start_pos[node];
	int ans = values[flattened_tree[i++]];
	while(i <= en_pos[node]) ans = __gcd(ans,values[flattened_tree[i++]]);

	return(ans);
}

int main()
{
	FIO
    int n,q; cin>>n>>q; for(int i=1; i<=n; i++) cin>>values[i];
    for(int i=1; i<n; i++)
    {
    	int u,v; cin>>u>>v;
    	adj[u].pb(v);
        adj[v].pb(u);
	}
    
    dfs(1,-1);
    
    while(q--)
    {
    	int type; cin>>type;
    	if(type == 1)
    	{
    		int i,x; cin>>i>>x;
    		update(i,x);
		}
		else
		{
			int i; cin>>i;
			cout<<query(i)<<endl;
		}
	}
    
	return 0;
}

