#include <bits/stdc++.h>
#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
ll tnpermut=0;

void helper(vector<int> v,vector<vector<int>> &ans,int idx)
{
	if(idx==v.size()-1)
	{
		ans.push_back(v);
		tnpermut++;
		return;
	}
	for(int i=idx;i<v.size();i++)
	{
		if(i!=idx && v[i]==v[idx]) continue;
		swap(v[i],v[idx]);
		helper(v,ans,idx+1);
	}
}

vector<vector<int>> permut(vector<int> v)
{
	sort(v.begin(),v.end());
	vector<vector<int>> ans(0);
	helper(v,ans,0);
	
	return ans;
}

int main()
{
	FIO
	int n; 
	//cout<<"Enter total number of elements :\n";
	cin>>n;
	
	vector<int> v(n);
	//cout<<"\nEnter elements :\n";
	for(auto &i : v) cin>>i;
	
	vector<vector<int>> ans = permut(v);
	
	//cout<<"\nPermutations are as follows :\n";
	for(auto v : ans)
	{
		for(auto i : v) cout<<i<<" ";
		cout<<"\n";
	}
	cout<<"\nTotal number of permutations are : "<<tnpermut<<endl;
	
	return(0);
}
