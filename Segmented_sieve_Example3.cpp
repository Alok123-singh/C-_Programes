#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;

/*
 Finding Prime Factorization of every number between range L to R
*/

const int c = 1e6+7;
bool is_prime[c]; // we dont need to use offset  
vector<int> primes_list[c]; // we do need to use offset as the numbers can be pretty big

int closest_greater_multiple(int l,int d)
{
	return ((l+d-1)/d)*d;
}

void segmented_sieve(int l,int r)
{
	for(int i=1;i<=c;i++) is_prime[i]=true;
	for(int d=2;d<=c;d++)
	{
		if(!is_prime[d]) continue;
		
		for(int num=closest_greater_multiple(l,d);num<=r;num+=d)
		{
			if(num>=2*d) is_prime[num]=false;
			int copy_num=num;
			while(copy_num%d==0)
			{
				primes_list[num-l].emplace_back(d);
				copy_num = copy_num/d;
			}
		}
	}
	for(auto x : primes_list[10-l])
	    cout<<x<<" ";
	cout<<"\n";
}

int main()
{
	FIO
	int l=2,r=1000006;
	segmented_sieve(l,r);
	
	return(0);
}
