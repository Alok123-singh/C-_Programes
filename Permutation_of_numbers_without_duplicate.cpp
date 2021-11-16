#include <bits/stdc++.h>
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
vector<vector<int>> ans(0);
ll tnpermut=0;

void permut(vector<int> &num,int idx)
{
	if(idx==num.size()-1)
	{
		ans.push_back(num);
		tnpermut++;
		return;
	}
	for(int i=idx;i<num.size();i++)
	{
		swap(num[i],num[idx]);
		permut(num,idx+1);
		swap(num[i],num[idx]);
	}
}

int main()
{
	FIO
	int n;
	//cout<<"Enter total number of elements :\n";
	cin>>n;
	
	vector<int> num(n);
    //cout<<"\nEnter elements :\n";
    for(auto &i : num) cin>>i;
    
    permut(num,0);
    
    //cout<<"\nPermutations are as follow :\n";
    for(auto v : ans)
    {
    	for(auto i : v) cout<<i<<" ";
    	cout<<endl;
	}
    cout<<"\nTotal number of permutations are : "<<tnpermut<<endl;
    
	return(0);
}
