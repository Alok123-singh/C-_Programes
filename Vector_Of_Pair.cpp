#include <bits/stdc++.h>
using namespace std;
const int c=8e4+999;
int main()
{
	vector<pair<int,int>> v[c];
	int n;
	
	printf("Enter Total Vertices :\n");
	scanf("%d",&n);
	
	int x=n;
	printf("\nEnter %d Edges :\n",n-1);
	while(x>1)
	{
		int u1,v1,w;
		scanf("%d %d %d",&u1,&v1,&w);
		
		v[u1].emplace_back(pair<int,int>(v1,w));
		v[v1].emplace_back(pair<int,int>(u1,w));
		x--;
	}
	
	printf("\nGraph :\n");
	for(int i=1;i<=n;i++)
	{
		printf("\n%d ",i);
		for(int j=0;j<v[i].size();j++)
		    cout<<"Vertex:"<<v[i][j].first<<" "<<"Weight:"<<v[i][j].second<<"  ";
	}
	
	return(0);
}
