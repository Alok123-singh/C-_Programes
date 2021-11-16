#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

map<int,int> pos;
bool completed[100001];

int minSwaps(vector<int>&nums) // Time complexicity of this function is O()
{
    int n = nums.size();
    
    bool flag = true; for(int i=0; i<n-1; i++) if(nums[i] > nums[i+1]) flag = false;
    if(flag) return(0);
    
    vector<int> aux(nums);
    sort(aux.begin(),aux.end());
    for(int i=0; i<n; i++) pos[aux[i]] = i;
    
    int min_swaps = 0;
    for(int i=0; i<n; i++)
    {
        if(!completed[i])
        {
            if(pos[nums[i]] == i)
            {
                completed[i] = true;
                continue;
            }
            int j = i;
            completed[j] = true;
            while(!completed[pos[nums[j]]])
            {
                completed[pos[nums[j]]] = true;
                j = pos[nums[j]];
                min_swaps++;
            }
        }
    }
    return(min_swaps);
}

int main()
{
	int t=1; //cin>>t;
	while(t--)
	{
		int n; //cin>>n;
		vector<int> v{10,11,5,4,3,2,1}; //for(int i=0; i<n; i++) cin>>v[i];
		cout<<"Total number of minimum swaps are : "<<minSwaps(v)<<endl;
	}
    
	return 0;
}

