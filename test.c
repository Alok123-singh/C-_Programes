#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ifact(int x)
{
	int f=1,i;
	
	for(i=1;i<=x;i++)
	    f=f*i;
	    
	return(f);
}

int RcountShapes(int i,int n)
{
	static int fres;
    int res1,res2,res;
	
	if(i==n)
	    return(0);
	    
	fres=RcountShapes(i+1,n);
	
	res1=ifact(2*i)/((ifact(i)*ifact(i))*(i+1));
	res2=ifact(2*(n-i-1))/((ifact(n-i-1)*ifact(n-i-1))*(n-i));
	
	res=res1*res2;
	
	return (fres+res);
}

int main()
{
	int count;
	
	count=RcountShapes(0,10);
	
	printf("Total Number Of Shapes Are : %d\n",count);
	
	return(0);
}







