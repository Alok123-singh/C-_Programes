#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define hell 1e15
#define inf 1e18
#define p_b push_back
using namespace std;

vector<int> adj[1000001];
bool vis[1000001];
int ti[1000001];
int li[1000001];
int ssc = 0;
int timer = 0;
vector<int> nodes_in_ssc[1000001];
stack<int> stk;
bool on_stack[1000001];

void tarjans_algorithm(int node){
	vis[node] = true;
	stk.push(node);
	on_stack[node] = true;
	ti[node] = timer;
	li[node] = timer++;
	
	for(auto choice: adj[node]){
		if(!vis[choice]){
			tarjans_algorithm(choice);
			if(on_stack[choice]){
				li[node] = min(li[node],li[choice]);
			}
		}
		else{
			if(on_stack[choice]){
				li[node] = min(li[node],ti[choice]);
			}
		}
	}
	
	if(ti[node] == li[node]){
		ssc++;
		cout<<ssc<<": ";
		while(!stk.empty() && stk.top() != node){
			nodes_in_ssc[ssc].p_b(stk.top());
		    cout<<stk.top()<<" ";
			on_stack[stk.top()] = false;
			stk.pop();
		}
		nodes_in_ssc[ssc].p_b(stk.top());
		cout<<stk.top()<<endl;
		on_stack[stk.top()] = false;
		stk.pop();
	}
}

int main()
{
	FIO
	int n,m; cin>>n>>m;
	for(int i=1; i<=m; i++){
		int u,v; cin>>u>>v;
		adj[u].p_b(v);
	}
	
	memset(vis,false,sizeof(vis));
	memset(on_stack,false,sizeof(on_stack));
	for(int i=0; i<n; i++){
		if(!vis[i]){
			tarjans_algorithm(i);
		}
	}
	
	/*cout<<"Total ssc nodes: "<<ssc<<endl<<endl;
	for(int i=1; i<=ssc; i++){
		sort(nodes_in_ssc[i].begin(),nodes_in_ssc[i].end());
		cout<<"ssc "<<i<<": ";
		for(auto node: nodes_in_ssc[i]){
			cout<<node<<" ";
		}
		cout<<endl;
	}*/
	
	return 0;
}

