#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> v{"022","12","13"};
	
	vector<int> num; for(int i=0; i<v.size(); i++) num.push_back(stoi(v[i]));
	
	sort(num.begin(),num.end());
	for(int n: num) cout<<n<<" ";
	cout<<endl;
	
	return(0);
}
