#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

int Binary_search(vector<string> &strarr,string key) /* Average time complexicity is O(logN) and worst case 
time complexity is O(N) */
{
	int i=0;
	int j=strarr.size()-1;
	bool vis[100005] = {0}; // to check whether an index is already visited or not 
	
	while(i<=j){
		int mid = (i+j)/2;
		int l=mid-1,r=mid+1;
		
		while(l>=0 and r<=strarr.size()-1 && !vis[l] && !vis[r]){
			if(strarr[l] == "") l--;
			else{
				mid = l;
				break;
			}
			
			if(strarr[r] == "") r++;
			else{
				mid = r;
				break;
			}
		}
		
		vis[mid] = true;
		if(strarr[mid] == key) return(mid+1);
		else if(strarr[mid] > key) j = mid-1;
		else i = mid+1;
	}
	return(-1);
}

int main()
{
	vector<string> strarr{"ai","","","bat","","","car","cat","","","dog",""};
	string key{"bat"};
	
	cout<<Binary_search(strarr,key)<<endl;
	
	return (0);
}
