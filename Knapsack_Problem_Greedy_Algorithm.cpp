#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n=7;
	float obj[3][n];
    
	printf("Enter %d Objects :\n",n);
	for(int i=0; i<n; i++)
		scanf("%f %f %f",&obj[0][i],&obj[1][i],&obj[2][i]);
    
	int capacity;
	printf("\nEnter capacity :\n");
	scanf("%d",&capacity);
    
	float *fraction=new float[n];
	float included[n]= {0};
    
	for(int i=0; i<n; i++)
		fraction[i]=(float)obj[1][i]/obj[2][i];
    
	while(capacity>0)
	{
		int maxp=max_element(fraction,fraction+n)-fraction;
        
		if(obj[2][maxp]<capacity)
			included[maxp]=1;
		else
			included[maxp]=(float)capacity/obj[2][maxp];
        
		capacity-=obj[2][maxp];
		fraction[maxp]=-1;
	}
    
	float maxprofit=0.0;
    
	for(int i=0; i<n; i++) 
	if(included[i]>0)
		maxprofit=maxprofit+obj[1][i]*included[i];
    
	printf("\nMaximum profit is : %0.2f\n",maxprofit);
	delete []fraction;
    
	return(0);
}
