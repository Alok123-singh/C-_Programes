#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<string,int> marksMap;
	
	marksMap["Alok"]=12;
	marksMap["Anand"]=20;
	marksMap["Alok"]=25;
	
	marksMap.insert({{"Rishav",14},{"Abhinav",17}});
	
	map<string,int>::iterator iter;
	for(iter=marksMap.begin();iter!=marksMap.end();iter++)
	    cout<<(*(iter)).first<<" "<<(*(iter)).second<<"\n";
	
	cout<<"\nThe Size Is : "<<marksMap.size()<<endl;
	cout<<"The Maximum Size Is : "<<marksMap.max_size()<<endl;
	cout<<"Return Type Of empty Function Is : "<<marksMap.empty()<<endl;
	
	return(0);
}
