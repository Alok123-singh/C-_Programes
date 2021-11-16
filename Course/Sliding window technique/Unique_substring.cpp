#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

set<pair<int,string>> unique_substring(string str)
{
	int n = str.length();
	unordered_map<char,int> last_occ;
	set<pair<int,string>> ans;
	
	int start_window = -1;
	int window_len = 0;
	int max_window_len = 0;
	
	int i = 0,j = 0;
	while(j < n)
	{
		char ch = str[j];
		
		if(last_occ.count(ch) && last_occ[ch] >= i)
		{
			ans.insert({window_len,str.substr(i,window_len)});
			i = last_occ[ch] + 1;
			window_len = j - i;
		}
		
		last_occ[ch] = j;
		window_len++;
		j++;
		
		if(window_len > max_window_len)
	    {
	    	max_window_len = window_len;
	    	start_window = i;
		}
	}
	
	ans.insert({window_len,str.substr(i,window_len)});
	
	return(ans);
}

int main()
{
	int t{1}; //cin>>t;
	while(t--)
	{
	    string str{"prateekbhaiya"}; //cin>>str;
	    
		auto ans = unique_substring(str);
		for(auto p: ans)
		{
			cout<<p.second<<endl;
		}
	}
	
	return 0;
}

