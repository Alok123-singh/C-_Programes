#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000006];
vector<int> revadj[1000006];
int ssc[1000006];
bool already_visited[1000006],vis[1000006];
vector<int> condensed_graph[1000006];
vector<int> topo_sort(0);
int label = 0;
int N,M = 0; // for condensed graph

void dfs_topo_sort(int node) // finding reverse topo sort using dfs algorithm
{
	vis[node] = true;
	for(auto choice: adj[node])
	{
		if(!vis[choice]) dfs_topo_sort(choice);
	}
	topo_sort.push_back(node);
}

vector<int> bfs_topo_sort(int V) // finding topo sort using bfs algorithm also known as Kahn's algorithm
{
	int indegree[V] = {0};
	
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
	
	vector<int> topo_sort;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		topo_sort.push_back(node);
		
		for(auto choice: adj[node]){
			indegree[choice]--;
			if(indegree[choice] == 0){
				q.push(choice);
			}
		}
		
	}
	
	return (topo_sort);
}

void dfs(int node)
{
	already_visited[node] = true;
	ssc[node] = label;
	for(auto choice: revadj[node])
	{
		if(!already_visited[choice]) dfs(choice);
	}
}

int main()
{
	int n,m; cin>>n>>m;
	for(int i=1; i<=m; i++)
	{
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
	}
	/*for(int node=1; node<=n; node++) for(int choice : adj[node]) revadj[choice].push_back(node);
	
	for(int node=1; node<=n; node++) if(!vis[node]) dfs_topo_sort(node);
	reverse(topo_sort.begin(),topo_sort.end());
	for(int i=0; i<topo_sort.size(); i++) if(!already_visited[topo_sort[i]]) label++,dfs(topo_sort[i]);
	N = label;
	
	for(int i=0; i<topo_sort.size(); i++)
	{
		for(auto node: adj[i])
		{
			if(ssc[node] == ssc[i])
			{
				// not contributing to condensed graph
			}
			else
			{
				condensed_graph[ssc[i]].push_back(ssc[node]);
				M++;
			}
		}
	}
	
	cout<<"Nodes and edges in condensed graph are : "<<N<<" and "<<M<<" respectively"<<endl;
	for(int node=1; node<=N; node++)
	{
	    if(condensed_graph[node].size()>0)
	    {
		    cout<<node<<": ";
		    for(auto choice: condensed_graph[node]) cout<<choice<<" ";
	        cout<<endl;
        }
    }*/
    
    auto topo_sort = bfs_topo_sort(n);
    for(auto x: topo_sort) cout<<x<<" ";
    cout<<endl;
    
	return(0);
}
