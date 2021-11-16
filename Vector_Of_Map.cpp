#include <bits/stdc++.h>
using namespace std;
const int c=8e4+999;

int main()
{
	vector<map<string,int>> vmap[c];
	map<string,int> m;
	m["Alok"]=12;
	m["Anand"]=24;
	m["Damp"]=36;
	m["Rocky"]=48;
	
	vmap[0].emplace_back(m);
	
	vmap[0][0].insert({{"Rishav",60},{"Sandeep",72},{"Raman",84},{"Alok",87}});
	
	map<string,int>::iterator iter;
	for(iter=vmap[0][0].begin();iter!=vmap[0][0].end();iter++)
	    cout<<(*(iter)).first<<" "<<(*(iter)).second<<"\n";
    
	return(0);
}
