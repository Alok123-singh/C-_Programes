#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define hell 1e15
#define p_b push_back
using namespace std;
vector<pair<int,int>> adj[1000001];

/*
Bellman ford algorithm work in case of directed graph. Directed graph can contain +ve as well as -ve edges but it
must not contain negative cycle. If directed graph contains negative cycle then we can detect it using bellman
ford algorithm.
*/

vector<int> bellman_ford_algorithm(int src,int n,int m){ // Time Complexity : O(N*M) i.e. O(N^2)
	vector<int> dis(n,INT_MAX);
	dis[src] = 0;
	
	vector<vector<int>> edges(m,vector<int>(3));
	int cnt = 0;
	for(int i=1; i<=n-1; i++){
		for(auto choice: adj[i]){
			int cn = choice.first;
			int w = choice.second;
			edges[cnt][0] = i;
			edges[cnt][1] = cn;
			edges[cnt++][2] = w;
		}
	}
	
	for(int i=1; i<=n-1; i++){
		bool not_update = true;
		for(auto choice: edges){
			int u = choice[0];
			int v = choice[1];
			int w = choice[2];
			if(dis[u] != INT_MAX && dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				not_update = false;
			}
		}
		if(not_update) return (dis);
	}
	
	for(auto choice: edges){
		int u = choice[0];
		int v = choice[1];
		int w = choice[3];
		if(dis[u] != INT_MAX && dis[u] + w < dis[v]){
			return vector<int>{-1}; // this tells us that there is negative edge cycle present.
		}
	}
	
	return (dis);
}

int main() {
	FIO
	int n,m; cin>>n>>m;
	for(int i=0; i<m; i++){
		int u,v,w; cin>>u>>v>>w;
		adj[u].p_b({v,w});
	}
	
	int src; cin>>src;
	auto p = bellman_ford_algorithm(src,n,m);
	for(auto x: p) cout<<x<<" ";
	cout<<endl;
	
	return 0;
}
