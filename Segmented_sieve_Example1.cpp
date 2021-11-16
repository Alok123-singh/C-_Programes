#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;

const int c = 1e6+7;
bool is_prime[c];

int closest_strictly_greater_multiple(ll l,int d)
{
	return (l/d+1)*d;
}

// r-l<=10^6

void segmented_seive(ll l,ll r)
{
	for(ll i=1;i<=c;i++) is_prime[i]=true;
	
	for(int d=2;d<=c;d++)
	{
		if(!is_prime[d]) continue;
		
		for(ll num=max(2*d,closest_strictly_greater_multiple(l,d));num<=r;num+=d)
		    is_prime[num-l]=false;
	}
	cout<<is_prime[15-l]<<"\n";
	cout<<is_prime[17-l]<<"\n";
}

int main()
{
	FIO
	ll l=2,r=30;
	segmented_seive(l,r);
	
	return(0);
}
