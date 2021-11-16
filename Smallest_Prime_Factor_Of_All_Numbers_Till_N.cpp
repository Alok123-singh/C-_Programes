#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int c = 1e5+7;
bool is_prime[c];
int spf[c];

void process_spf_table(int n)
{
	for(int i=1;i<=n;i++) is_prime[i]=true;
    for(int i=1;i<=n;i++) spf[i]=i;
    
    for(int d=2;d<=n;d++)
    {
    	if(!is_prime[d]) continue;
    	
    	for(int num=2*d;num<=n;num+=d)
    	{
    		is_prime[num]=false;
    		spf[num]=min(spf[num],d);
		}
	}
}

int main()
{
	FIO
	int n=1e5;
	process_spf_table(n);
	
	return(0);
}
