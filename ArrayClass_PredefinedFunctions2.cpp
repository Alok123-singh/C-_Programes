#include <bits/stdc++.h>

using namespace std;

int main()
{
	array<int,6> arr={1,2,3,4,5,6};
	int n,max;
	arr.fill(0);
	
	cout<<"Enter Number :\n";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		max=INT_MIN;
		int k;
		for(int i=0;i<6;i++)
		{
			if(arr[i]>max)
			{
				max=arr[i];
				k=i;
			}
		}
		arr.at(k)=-1;
	}
	
	cout<<n<<" Largest Number Is : "<<max<<endl;
	return(0);
}

