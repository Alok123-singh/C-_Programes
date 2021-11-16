#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

int main()
{
	int t=1; //cin>>t;
	while(t--)
	{
		int n=3; //cin>>n;
		vector<string> v{"92 022","82 12","77 13"}; //for(int i=0; i<n; i++) cin>>v[i];
		int key=2;
		string rev="false",comp="numeric";
		//cin>>key>>rev>>comp;
		
		vector<string> keys(0);
		for(int i=0; i<v.size(); i++)
		{
			int ct=0;
			stringstream ss(v[i]);
			
			string token;
			while(getline(ss,token,' '))
			{
				ct++;
				if(ct == key)
				{
					keys.p_b(token);
					break;
				}
			}
		}
		
		if(comp == "numeric")
		{
			vector<pair<int,string>> ans;
			vector<int> k; for(int i=0; i<keys.size(); i++) k.p_b(stoi(keys[i]));
			
			for(int i=0; i<k.size(); i++) ans.p_b({k[i],v[i]});
			sort(ans.begin(),ans.end());
			
			if(rev == "true") reverse(ans.begin(),ans.end());
			
			for(int i=0; i<ans.size(); i++) cout<<ans[i].second<<endl;
		}
		else
		{
			vector<pair<string,string>> ans;
			
			for(int i=0; i<keys.size(); i++) ans.p_b({keys[i],v[i]});
			sort(ans.begin(),ans.end());
			
			if(rev == "true") reverse(ans.begin(),ans.end());
			
			for(int i=0; i<ans.size(); i++) cout<<ans[i].second<<endl;
		}
	}
    
	return 0;
}

