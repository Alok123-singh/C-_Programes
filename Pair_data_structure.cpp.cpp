#include <bits/stdc++.h>
using namespace std;

int main()
{
	pair<int,string> obj1(10,"Alok");
	pair<int,string> obj2=make_pair(20,"Anand");
	pair<int,string> obj3=(pair<int,string>(30,"Rishav"));
	pair<int,string> obj4=(pair<int,string>(40,"Raman"));
	pair<int,string> obj5(obj4);
	pair<int,string> obj6=obj5;
	
	if(obj1<obj2)
	    printf("Before Swap :\n\n");
	printf("First Pair : ");
	cout<<obj1.first<<" "<<obj1.second<<"\n";
	printf("Second Pair : ");
	cout<<obj2.first<<" "<<obj2.second<<"\n";
	printf("Third Pair : ");
	cout<<obj3.first<<" "<<obj3.second<<"\n";
	printf("Fourth Pair : ");
	cout<<obj4.first<<" "<<obj4.second<<"\n";
	
	obj1.swap(obj2); // it will swap the objects obj1 and obj2
	obj3.swap(obj4); // it will swap the objects obj3 and obj4
	
	if(obj5==obj6)
	    printf("\nAfter Swap :\n\n");
	printf("First Pair : ");
	cout<<obj1.first<<" "<<obj1.second<<"\n";
	printf("Second Pair : ");
	cout<<obj2.first<<" "<<obj2.second<<"\n";
	printf("Third Pair : ");
	cout<<obj3.first<<" "<<obj3.second<<"\n";
	printf("Fourth Pair : ");
	cout<<obj4.first<<" "<<obj4.second<<"\n";
	
	return(0);
}
