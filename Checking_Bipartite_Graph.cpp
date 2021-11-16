#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define vi vector<int>
#define p_b push_back
using namespace std;

vector<int> adj[1000001];

bool is_bipartite_bfs(int color[],int node){
	queue<int> q;
	q.push(node);
	color[node] = 0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(auto choice: adj[node]){
			if(color[choice] == -1){
				color[choice] = 1 - color[node];
				q.push(choice);
			}
			else if(color[choice] == color[node]) return (false);
		}
	}
	return (true);
}

bool is_bipartite_dfs(int node,int color[],int c){
	color[node] = c;
	
	for(auto choice: adj[node]){
		if(color[choice] == -1){
			int o_c = c == 1 ? 0 : 1;
			if(!is_bipartite_dfs(choice,color,o_c)) return (false);
		}
		else{
			if(color[choice] == color[node]) return (false);
		}
	}
	return (true);
}

int main(){
	int n,m; cin>>n>>m;
	
	for(int i=0; i<m; i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int color[1000001];
	memset(color,-1,sizeof(color));
	
	bool is_bipartite = true;
	for(int i=0; i<n; i++){
		if(color[i] == -1){
			if(!is_bipartite_bfs(color,i)){
				is_bipartite = false;
				break;
			}
		}
	}
	
	if(is_bipartite) cout<<"Yes";
	else cout<<"No";
	
	return (0);
}
