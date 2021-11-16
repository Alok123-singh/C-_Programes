#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

vector<pair<int,int>> total_subarray1(int arr[],int n,int k) // O(n) and this is sliding window solution
{
	int i{0},j{0};
	
	vector<pair<int,int>> ans;
	int sum{0};
	while(j<n)
	{
		sum += arr[j];
		j++;
		
		while(sum > k && i < j)
		{
			sum -= arr[i];
			i++;
		}
		
		if(sum == k)
		{
			ans.push_back({i,j-1});
		}
	}
	
	return(ans);
}

vector<pair<int,int>> total_subarray2(int arr[],int n,int k) // O(nlogn)
{
	int prefix_sum[n];
	prefix_sum[0] = arr[0];
	for(int i=1; i<n; i++) prefix_sum[i] = prefix_sum[i-1] + arr[i];
	
	map<int,int> index;
	for(int i=0; i<n; i++) index[prefix_sum[i]] = i;
	
	vector<pair<int,int>> ans;
	for(int i=0; i<n-1; i++)
	{
		if(binary_search(prefix_sum+i+1,prefix_sum+n,k+prefix_sum[i])) ans.p_b({i+1,index[k+prefix_sum[i]]});
	}
	
	return (ans);
}

vector<pair<int,int>> total_subarray3(int arr[],int n,int k) // O(n^2) and this is a brute force solution
{
    int prefix_sum[n];
	prefix_sum[0] = arr[0];
	for(int i=1; i<n; i++) prefix_sum[i] = prefix_sum[i-1] + arr[i];
	
	vector<pair<int,int>> ans;
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			if(i>0)
			{
				if(prefix_sum[j] - prefix_sum[i-1] == k) ans.p_b({i,j});
			}
			else
			{
				if(prefix_sum[j] == k) ans.p_b({i,j});
			}
		}
	}
	
	return (ans);
}

vector<pair<int,int>> total_subarray4(int arr[],int n,int k) // O(n^3) ans this is also a brute force solution
{
	vector<pair<int,int>> ans;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i; j<n; j++)
		{
			int sum{};
			for(int k=i; k<=j; k++) sum += arr[k];
			if(sum == k) ans.p_b({i,j});
		}
	}
	return (ans);
}

int main()
{
	int t{1}; //cin>>t;
	while(t--)
	{
		int n=11; //cin>>n;
		int arr[n] = {1,3,2,1,4,1,3,2,1,1,2}; //for(int i=0; i<n; i++) cin>>arr[i];
		int k=8; //cin>>k;
		
		auto ans = total_subarray1(arr,n,k);
		for(auto p: ans) cout<<p.first<<" "<<p.second<<endl;
	}
	
	return 0;
}

