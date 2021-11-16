#include <stdio.h>
#define ll long int 

ll fact(ll x)
{
	long ll fact=1;
	ll i;
	
	for(i=1;i<=x;i++)
	    fact=fact*i;
	
	return(fact);
}

ll CountShapes(ll i,ll n)
{
	static ll res;
	static ll c=0;
	
	if(i==n && c==0)
	{
		c=1;
		return(0);
	}
	
	if(c==1)
        return((fact(2*i)/(fact(i)*fact(i)*(i+1))));
	
	res=CountShapes(i+1,n);
	
	return(CountShapes(i,n)*CountShapes(n-i-1,n)+res);
}

int main()
{
	printf("Total Number Of Shapes (Permutations) Possible Are : %lld\n",CountShapes(0,17));
	
	return(0);
}
