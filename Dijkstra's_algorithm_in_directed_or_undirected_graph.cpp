#include <bits/stdc++.h>
#define ll long long int
#define inf 1e10
using namespace std;

vector<pair<int,int>> adj[1000006];
int parent[1000006];
int n;

vector<ll> dijkstra_1(int src)
{
	vector<ll> d(n+1,inf);
	int mark[n+1] = {0};
	d[src] = 0;
	
	for(int i=1; i<=n; i++)
	{
		ll min = inf;
		int j = 0;
		for(int i=1; i<=n; i++) if(!mark[i] && d[i] <= min) min = d[i], j = i;
		
		mark[j] = true;
		
		for(auto choice: adj[j])
		{
			int nb = choice.first, w = choice.second;
			
			if(d[j] + w < d[nb])
			{
				parent[nb] = j;
				d[nb] = d[j] + w;
			}
		}
	}
	
	return(d);
}

vector<ll> dijkstra_2(int src)
{
	vector<ll> d(n+1,inf);
	set<pair<int,int>> s;
	
	s.insert({0,src});
	d[src] = 0;
	
	while(!s.empty())
	{
		auto it = s.begin();
		int node = it->second;
		s.erase({d[node],node}); // s.erase(it); is more preferable statement
		
		for(auto choice: adj[node])
		{
			int nb = choice.first, w = choice.second;
			
			if(d[node] + w < d[nb])
			{
				parent[nb] = node;
				s.erase({d[nb],nb}); /*auto it = s.find({d[nb],nb}); s.erase(it); is more preferable for deletion*/
				d[nb] = d[node] + w;
				s.insert({d[nb],nb});
			}
		}
	}
	
	return(d);
}

vector<ll> mult_dijkstra(vector<int>& source)
{
	vector<ll> d(n+1,inf);
	set<pair<int,int>> s;
	
	for(auto src: source)
	{
        s.insert({0,src});
        d[src] = 0;
    }
    
	while(!s.empty())
	{
		auto it = s.begin();
		int node = (*it).second;
		s.erase({d[node],node});
		
		for(auto choice: adj[node])
		{
			int nb = choice.first, w = choice.second;
			
			if(d[node] + w < d[nb])
			{
				s.erase({d[nb],nb});
				d[nb] = d[node] + w;
				s.insert({d[nb],nb});
			}
		}
	}
	
	return(d);
}

void getPath(int src)
{
	for(int node=1; node<=n; node++)
	{
		if(parent[node] == -1) cout<<node<<": No path exist"<<endl;
		else
		{
			int temp = node;
			cout<<node<<": ";
			while(temp != src)
			{
				cout<<temp<<" -> ";
				temp = parent[temp];
			}
			cout<<src;
			cout<<endl;
		}
	}
}

int main()
{
	int m; cin>>n>>m;
	// undirected graph
	for(int i=1; i<=m; i++)
	{
		int u,v,w; cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
		adj[v].push_back(make_pair(u,w));
	}
	
	for(int i=0; i<1000006; i++) parent[i] = -1;
	parent[1] = 0;
	vector<ll> d = dijkstra_1(1);
	for(int i=1; i<=n; i++) cout<<i<<": "<<d[i]<<endl;
	
	getPath(1);
	cout<<endl;
	
	return (0);
}
/*
9 12
1 2 7
1 3 15
1 6 16
2 4 18
2 3 5
3 4 11
3 6 2
6 5 9
5 4 6
7 8 1
8 9 2
9 7 3
*/
