#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<int,std::less<>> set={1,3,2,4,5,1,2,3,4,5};
	
	std::set<int>::iterator itr;
	
	for(itr=set.begin();itr!=set.end();itr++)
	    cout<<*itr<<" ";
	
	set.erase(set.find(2),set.find(3));
	
	if(!set.empty())
	    printf("\nAfter Erasing :\n");
	for(itr=set.begin();itr!=set.end();itr++)
	    cout<<*itr<<" ";
	
	return(0);
}
