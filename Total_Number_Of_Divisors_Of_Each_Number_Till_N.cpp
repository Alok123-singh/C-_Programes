#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
using namespace std;

const int c=1e5+7;
int divisors[c];
ll sum_divisors[c];

void find_total_divisors(int n)
{
	for(int d=1;d<=n;d++)
	{
		for(int num=d;num<=n;num+=d)
		{
		    divisors[num]++;
		    sum_divisors[num]+=d;
        }
	}
	cout<<divisors[4]<<" "<<sum_divisors[4]<<"\n";
}

int main()
{
	FIO
	int n=1e5;
	find_total_divisors(n);
	
	return(0);
}
