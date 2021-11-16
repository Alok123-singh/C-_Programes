#include <bits/stdc++.h>
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int c = 1e7+7;
bool is_prime[c];
int total_primes[c];

void find_total_primes(int n)
{
	for(int i=1;i<=n;i++) is_prime[i]=true;
	
	int temp=0;
	for(int d=2;d<=n;d++)
	{
		if(!is_prime[d])
		{
			total_primes[d]=temp;
			continue;
		}
		else
		{
		    total_primes[d]+=temp;
		    temp+=1;
	    }
		for(int num=2*d;num<=n;num+=d)
		{
			is_prime[num]=false;
			total_primes[num]++;
		}
	}
	cout<<total_primes[n]<<"\n";
	cout<<is_prime[n]<<"\n";
}

int main()
{
	FIO
	int n = c-1;
    find_total_primes(n);
    
	return 0;
}

