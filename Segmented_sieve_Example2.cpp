#include <bits/stdc++.h> 
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

/*
 Finding total number of divisors for every number in range from L to R
*/

const int c = 1e6+7;
int divisors[c];

int closest_greater_multiple(int l,int d)
{
	return ((l+d-1)/d)*d;
}

void segmented_sieve_1(int l,int r)
{
	for(int d=1;d<=1000006;d++)
	{
		for(ll num=closest_greater_multiple(l,d);num<=r;num+=d)
			divisors[num-l]++;
	}
	cout<<divisors[10-l]<<"\n"; 
}

bool is_perfect_square(int n)
{
	int num=sqrt(n);
	return num*num==n;
}

void segmented_sieve_2(int l,int r)
{
	for(int d=1;d<=1000006;d++)
	{
		for(ll num=closest_greater_multiple(l,d);num<=r;num+=d)
		{
			int d1=d;
			ll d2=num/d;
			if(d1<=d2) divisors[num-l]+=2;
		}
	}
	for(ll i=l;i<=r;i++)
		if(is_perfect_square(i)) divisors[i-l]--;
	
	cout<<divisors[10-l]<<"\n"; 
}

int main()
{
	FIO
	ll l=2,r=30;
	segmented_sieve_2(l,r);
	
	return(0);
}
