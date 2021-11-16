#include <bits/stdc++.h>
using namespace std;

const int c=8e4+999;
int n,k;
vector<int> adj[c],col[c];
int a[c],ans[c];

void dfs(int node = 1,int par = -1)
{
	int sz=(int)col[a[node]].size();
    
	if(sz<k)
	    ans[node] = -1;
	else
	    ans[node] = col[a[node]][sz-k];
	
	col[a[node]].emplace_back(node);
    
	for(int it : adj[node])
    if(it!=par)
	    dfs(it,node);
	
	col[a[node]].pop_back();
}

int main()
{
    scanf("%d %d",&n,&k);

	for(int i=1;i<=n;i++)
	    scanf("%d ",a+i);
    
	int x=n;
	while(x-- > 1)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
    
    dfs(1,-1);
    
	for(int i=1;i<=n;i++)
	    printf("%d ",ans[i]);
    
	return(0);
}
