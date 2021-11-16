#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;

const int c = 1e9+7;
bool is_prime[c];
int operations=0;

void seive(int n)
{
	for(int i=1;i<=n;i++) is_prime[i]=true;
    for(int d=2;d<=n;d++)
    {
    	if(is_prime[d] == false) continue;
    	for(ll num=d*d;num<=n;num+=d) // for(int num=2*d;num<=n;num+=d)
    	{
    		is_prime[num]=false;
    		operations++;
		}
	}
	cout<<operations<<"\n";
}

int main()
{
	FIO
	int n = 1e4 ;
	seive(n);
	
	return(0);
}
