#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000006];
bool already_visited[1000006];
int heighest_back_edge[1000006];
int parent[1000006];
int height[1000006];
vector<pair<int,int>> bridge(0),back_edges(0);

void dfs(int current_node,int par,int ht = 1)// not working
{
    parent[current_node] = par;
	already_visited[current_node] = true;
	height[current_node] = ht;
	for(int choice: adj[current_node])
	{
		if(choice == parent[current_node]) continue;
		if(!already_visited[choice])
		{
			dfs(choice,current_node,ht+1);
			heighest_back_edge[current_node] = min(heighest_back_edge[current_node],heighest_back_edge[choice]);
		}
		else
		{
			if(current_node > choice)
			{
				heighest_back_edge[current_node] = min(heighest_back_edge[current_node],height[choice]);
				back_edges.push_back(make_pair(current_node,choice));
			}
		}
	}
	if(par!=-1 && heighest_back_edge[current_node] > height[par]) bridge.push_back(make_pair(current_node,par));
}

int ti[1000001]; // time of insertion array
int li[1000001]; // lowest time of insertioon array
bool vis[1000001];
int t = 1; // time
vector<pair<int,int>> bridges;

void find_bridges(int node,int par){ // working algorithm
	vis[node] = true;
	ti[node] = t;
	li[node] = t++;
	
	for(auto choice: adj[node]){
		if(choice == par) continue;
		if(!vis[choice]){
			find_bridges(choice,node);
			li[node] = min(li[node],li[choice]);
			if(li[choice] > ti[node]){
				bridges.push_back({node,choice});
			}
		}
		else{
			li[node] = min(li[node],li[choice]);
		}
	}
}

int main()
{
	int n,m; cin>>n>>m;
	for(int i{1}; i<=m; i++)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i{}; i<1000006; i++) heighest_back_edge[i] = height[i] = INT_MAX;
	parent[1] = -1;
	for(int node{1}; node<=n; node++) if(!already_visited[node]) height[node]=1,dfs(node,parent[node],height[node]);
	
	cout<<"Bridges Are :\n";
	for(int i{}; i<bridge.size(); i++) cout<<bridge[i].first<<" "<<bridge[i].second<<endl;
	cout<<"Back edges are :\n";
	for(int i{}; i<back_edges.size(); i++) cout<<back_edges[i].first<<" "<<back_edges[i].second<<endl;
	
	return(0);
}
