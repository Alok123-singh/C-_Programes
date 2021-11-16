#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

void merge(vector<string> &strarr,int st,int mid,int en)
{
	int i=st;
	int j=mid+1;
	
	vector<string> temp;
	
	while(i<=mid && j<=en){
		string x = strarr[i],y = strarr[j];
		if(x+y < y+x){
			temp.push_back(strarr[i++]);
		}
		else{
			temp.push_back(strarr[j++]);
		}
	}
	
	while(i<=mid){
		temp.push_back(strarr[i++]);
	}
	
	while(j<=en){
		temp.push_back(strarr[j++]);
	}
	
	int k=0;
	for(int idx=st; idx<=en; idx++){
		strarr[idx] = temp[k++];
	}
}

void merge_sort(vector<string> &strarr,int st,int en)
{
	// base condition
	if(st >= en){
		return;
	}
	
	int mid = (st+en)/2;
	merge_sort(strarr,st,mid);
	merge_sort(strarr,mid+1,en);
	
	merge(strarr,st,mid,en);
}

int main()
{
	vector<string> strarr{"a","ab","aba"};
	
	merge_sort(strarr,0,strarr.size()-1);
	
	string ans{}; for(auto str: strarr) ans += str;
	cout<<ans<<endl;
	
	return(0);
}
