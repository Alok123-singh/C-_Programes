#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cycles(0);
vector<int> adj[1000006];
int parent[1000006];
bool already_visited[1000006];
bool dfs_finished[1000006];

bool is_cycle_present_dfs(int node,int par){ // detecting cycle using dfs algorithm
	already_visited[node] = true;
	for(int choice: adj[node])
	{
		if(!already_visited[choice])
		{
			// this is a dfs tree edge
			if(is_cycle_present_dfs(choice,node)) return (true);
		}
		else
		{
			if(!dfs_finished[choice]){
				// this is a back edge
				return (true);
			}
            
		}
	}
	dfs_finished[node] = true;
	return (false);
}

bool is_cycle_present_bfs(int V) // detecting cycle using bfs algorithm or using kahn's algorithm
{
	int indegree[V];
	for(int i=0; i<V; i++){
		for(auto choice: adj[i]){
			indegree[choice]++;
		}
	}
	
	queue<int> q;
	for(int i=0; i<V; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	
	int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		cnt++;
		
		for(auto choice: adj[node]){
			indegree[choice]--;
			if(indegree[choice] == 0){
				q.push(choice);
			}
		}
	}
	
	if(cnt == V) return (false); // it means cycle is present
	return (true); // it means cycle is not present
}

bool extract_cycle(int node,int par)
{
	already_visited[node] = true;
	parent[node] = par;
	for(int choice: adj[node])
	{
		if(!already_visited[choice])
		{
			// this is a dfs tree edge
			extract_cycle(choice,node);
		}
		else
		{
			if(!dfs_finished[choice]){
				// this is a back edge
				int temp = node;
				vector<int> cycle;
				while(temp != choice){
					cycle.push_back(temp);
					temp = parent[temp];
				}
				cycle.push_back(choice);
				cycles.push_back(cycle);
			}
            
		}
	}
	dfs_finished[node] = true;
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
    	int u,v; cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
	}
	for(int node{1}; node<=n; node++) if(!already_visited[node]) extract_cycle(node,parent[node]);
	
	if(!cycles.size()) cout<<"No cycles found"<<endl;
	else
	{
		cout<<"There are total "<<cycles.size()<<" number of cycles as follows :\n";
		for(vector<int> cycle: cycles)
		{
			for(int node: cycle) cout<<node<<" ";
			cout<<endl;
		}
	}
	return(0);
} 
