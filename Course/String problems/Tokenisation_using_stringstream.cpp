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
    string str{"  abc  def"};
    //getline(cin,str);
    
    stringstream ss(str);
    string token;
    
    vector<string> tokens(0);
    
    while(getline(ss,token,' ')) //getline(ss,token,delimeter)
    {
    	tokens.p_b(token);
	}
    
    for(auto token: tokens) cout<<token<<",";
    cout<<endl;
    
	return 0;
}

