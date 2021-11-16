#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000006];
bool already_visited[1000006],is_articulation[1000006];
int heighest_back_edge[1000006];
int parent[1000006];
int height[1000006];

void dfs(int current_node,int par,int ht = 1) // not working
{
    parent[current_node] = par;
	already_visited[current_node] = true;
	height[current_node] = ht;
	is_articulation[current_node] = true;
	bool flag = false;
    
	for(int choice: adj[current_node])
	{
		if(choice == parent[current_node]) continue;
		if(!already_visited[choice])
		{
			flag = true;
			dfs(choice,current_node,ht+1);
			if(heighest_back_edge[choice] < height[current_node]) is_articulation[current_node] = false;
			/* Here for checking whether a point is an articulation point or not, we just bother about
			the heighest back edge from choices of current_node not the back edge form current_node
			because if a current_node is an articulation point then the back edge of current_node will 
			also be removed when that point is detached so it doesn't contribute to the fact that a 
			point is an articulation point or not*/
		}
		else
		{
			if(current_node > choice)
			{
				heighest_back_edge[current_node] = min(heighest_back_edge[current_node],height[choice]);
			}
		}
	}
	if(!flag) is_articulation[current_node] = false;
}

int ti[1000001]; // time of insertion of node
int li[1000001]; // lowest time of insertion of node
bool is_artiulation[1000001];
bool vis[1000001];
int t = 1; // time

void find_articulation_points(int node,int par){ // working algorithm
	vis[node] = true;
	ti[node] = t;
	li[node] = t++;
	
	int individual_childs = 0;
	for(auto choice: adj[node]){
		if(choice == par) continue;
		if(!vis[choice]){
			find_articulation_points(choice,node);
			li[node] = min(li[node],li[choice]);
			if(li[choice] >= ti[node] && par != -1){
				is_articulation[node] = true;
			}
			individual_childs++;
		}
		else{
			li[node] = min(li[node],ti[choice]);
		}
	}
	
	if(par == -1 && individual_childs > 1){
		is_articulation[node] = true;
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
	for(int i{}; i<1000006; i++) heighest_back_edge[i]= height[i] = INT_MAX;
	parent[1] = -1;
	for(int node{1}; node<=n; node++) if(!already_visited[node])
	{
	    height[node]=1,dfs(node,parent[node],height[node]);
	    if(adj[node].size() >= 2) is_articulation[node] = true;
	    else is_articulation[node] = false;
    }
	cout<<"Articulation points Are :\n";
	for(int i{1}; i<=n; i++) if(is_articulation[i]) cout<<i<<" ";
	cout<<endl;
	
	return(0);
}
