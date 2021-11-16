#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int c = 1e6+7;

bool is_prime[c];
int spf[c];
vector<int> primes_list[c];

void process_spf_table(int n)
{
	for(int i=2;i<=n;i++) is_prime[i]=true; // we will start from 2 because 1 is not prime
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

void prime_factorisation(int n)
{
	for(int d=1;d<=n;d++)
	{
		int x=d;
		while(x!=1)
		{
			primes_list[d].push_back(spf[x]);
			x=x/spf[x];
		}
	}
	for(int x : primes_list[24])
	    cout<<x<<" ";
    cout<<"\n";
}

int main()
{
	FIO
	int n = 1e6;
	process_spf_table(n);
	prime_factorisation(n);
	
	return(0);
}
