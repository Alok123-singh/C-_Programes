#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<float> v(1);
	
	v[0]=12;
	
	v.push_back(24);
	
	cout<<"Vector Before Pop : ";
	for(int i=0;i<v.size();i++)
	    cout<<v[i]<<" ";
	
	v.pop_back();
	
	cout<<"\nVector After Pop  : ";
	for(int i=0;i<v.size();i++)
	    cout<<v[i]<<" ";
	
	cout<<endl;
	
	return(0);
}

