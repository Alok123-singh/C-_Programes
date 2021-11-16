#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cycles(0);
vector<int> adj[1000006];
int parent[1000006];
bool already_visited[1000006];

bool is_cycle_present_dfs(int current_node,int par){ // detecting cycle using DFS algorithm
	already_visited[current_node] = true;
	for(int choice: adj[current_node])
	{
		if(choice == par) continue;
		if(!already_visited[choice])
		{
			// this is a dfs tree edge
			if(is_cycle_present_dfs(choice,current_node)) return (true);	
		}
		else
		{
			if(current_node > choice){
			    // this is a back edge
			    return (true);
			}
		}
	}
	return(false);
}

bool is_cycle_present_bfs(int node){ // detecting cycle using bfs algorithm
	queue<pair<int,int>> q;
	q.push({node,-1});
	already_visited[node] = true;
	
	while(!q.empty()){
		int node = q.front().first;
		int par = q.front().second;
		
		for(auto choice: adj[node]){
			if(!already_visited[choice]){
				q.push({choice,node});
				already_visited[choice] = true;
			}
			else if(choice != par){
				return (true);
			}
		}
	}
	
	return (false);
}

void extract_cycle(int current_node,int par)
{
	parent[current_node] = par;
	already_visited[current_node] = true;
	for(int choice: adj[current_node])
	{
		if(choice == par) continue;
		if(!already_visited[choice])
		{
			// this is a dfs tree edge
			extract_cycle(choice,current_node);
		}
		else
		{
			/*  The below condition (current_node > choice) is important because if we don't write this condition
			    then the algorithm can count double the actual number of cycles. For example if we found a 
				back edge from current_node1 > choice1 then we have obviously included that cycles in our ans
				but when the algorithm will come back and the current_node will become choice1 then it will see 
				that the current_node1 is already visited and it will count that cycle again. So that's why we 
				need to take care of that. 
			*/
			if(current_node > choice){
			    // this is a back edge
			    int node = current_node;
			    vector<int> v(0);
			    while(node != choice)
			    {
			        v.push_back(node);
			        node = parent[node];
		        }
			    v.push_back(choice);
			    cycles.push_back(v);
		    }
		}
	}
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
