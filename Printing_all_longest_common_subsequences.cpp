#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define p_b push_back
using namespace std;

int dp[1001][1001];

void lcs(string a,string b,int n,int m){
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0 || j==0) dp[i][j] = 0;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
}

set<string> Lcs;

void print_lcs(string a,string b,int i,int j,string output){
	if(i==0 || j==0){
		reverse(output.begin(),output.end());
		Lcs.insert(output);
		return;
	}
	
	if(a[i-1] == b[j-1]){
		print_lcs(a,b,i-1,j-1,output+a[i-1]);
	}
	else{
		if(dp[i-1][j] > dp[i][j-1]){
			print_lcs(a,b,i-1,j,output);
		}
		else if(dp[i-1][j] < dp[i][j-1]){
			print_lcs(a,b,i,j-1,output);
		}
		else{
			print_lcs(a,b,i-1,j,output);
			print_lcs(a,b,i,j-1,output);
		}
	}
}

int main()
{
	FIO
	string a = "abaaa",b = "baabaca"; //cin>>a>>b;
	
	lcs(a,b,a.length(),b.length());
	
	print_lcs(a,b,a.length(),b.length(),{""});
	
    set<string>::iterator iter;
    for(iter = Lcs.begin(); iter!=Lcs.end(); iter++){
    	cout<<*iter<<" ";
	}
	cout<<endl;
	
	return 0;
}

