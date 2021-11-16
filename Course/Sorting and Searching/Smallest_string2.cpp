#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

bool comparator(string x,string y){
	return x+y < y+x;
}

int main()
{
    vector<string> strarr{"a","ab","aba"};
    
    sort(strarr.begin(),strarr.end(),comparator);
    
    string ans{}; for(auto str: strarr) ans += str;
	cout<<ans<<endl;
    
    return(0);
}
