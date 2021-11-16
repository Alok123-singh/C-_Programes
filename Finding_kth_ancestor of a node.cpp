#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

int n;
vector<int> adj[100005];
int parent[100005][21];
bool vis[100005];

void dfs(int node, int par) // O(N+E)
{
	vis[node] = true;
	parent[node][0] = par;
	for(auto child: adj[node])
	{
		if(child == par) continue;
		else
		{
		    if(!vis[child]) dfs(child,node);
        }
	}
}

/*
void preorder(Node *node,int par)
{
	if(node)
	{
		parent[node->data][0] = par;
		preorder(node->left,node->data);
		preorder(node->right,node->data);
	}
}
*/

void find_ancestors() // O(NlogN)
{
	for(int i=1; i<=20; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
		}
	}
}

int kth_ancestor1(int node,int k) // O(logN) - using binary lifting method
{	
	for(int i=10; i>=0; i--)
	{
		if((1<<i) & k)
        {
        	if(node != -1) node = parent[node][i];
		}
	}
	return(node);
}

int kth_ancestor2(int node,int k) // O(N) - using linear approach
{
	for(int i=1; i<=k; i++)
	{
		if(node != -1) node = parent[node][0];
	}
	return(node);
}

int main()
{
	int e;
	cin>>n>>e;
	
	for(int i=1; i<=e; i++)
	{
		int u,v; cin>>u>>v;
		adj[u].p_b(v);
		adj[v].p_b(u);
	}
	
	int node,k; cin>>node>>k;
	
	dfs(1,-1);
	find_ancestors(); // O(NlogN)
	
	cout<<kth_ancestor1(node,k)<<endl;
	cout<<kth_ancestor2(node,k)<<endl;
	
	return 0;
}

