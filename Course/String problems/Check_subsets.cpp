#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

bool check_subset(string str1,string str2)
{
	int i{0},j{0};
	
	while(i<str1.size())
	{
		if(str1[i] == str2[j]) i++,j++;
		else i++;
	}
	
	if(j == str2.length()) return (true);
	return (false);
	
}

int main()
{
	int t{1}; //cin>>t;
	while(t--)
	{
		string str1{"codingminutes"},str2{"cines"}; //cin>>str1>>str2;
		
		if(check_subset(str1,str2)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	return 0;
}

