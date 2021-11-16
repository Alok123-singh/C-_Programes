#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

void subsequences(string input,string o,vector<pair<int,string>> &v) // O(2^n)
{
	if(input.size() == 0)
	{
		v.p_b({o.size(),o});
		return;
	}
	
	char ch = input[0];
	string reduced_input = input.substr(1);
	
	// includes
	subsequences(reduced_input,o + ch,v);
	
	// excludes
	subsequences(reduced_input,o,v);
}

int main()
{
	int t{1}; //cin>>t;
	while(t--)
	{
		string str="abcd"; //cin>>str;
		string output{""};
		vector<pair<int,string>> v;
		subsequences(str,output,v);
		
		sort(v.begin(),v.end());
		
		for(auto p: v) cout<<p.second<<", ";
		cout<<endl;
	}
	
	return 0;
}

