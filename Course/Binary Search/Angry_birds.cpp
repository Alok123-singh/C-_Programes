#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

int angry_birds(vector<int> pos,int birds){
	int s = 0;
	int e = *(--pos.end()) - *pos.begin();
	
	int ans = -1;
	while(s <= e){
		int mid = (s+e)/2;
		
		int cnt = 1;
		int last_occ = 0;
		for(int i=1; i<pos.size(); i++){
			if(pos[i] - pos[last_occ] >= mid){
				cnt++;
				last_occ = i;
				if(cnt >= birds){
					break;
				}
			}
		}
		
		if(cnt == birds){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	
	return (ans);
}

int main()
{
    int n = 5,birds = 3;
	vector<int> pos{1,2,4,8,9};
	
	sort(pos.begin(),pos.end());
	cout<<angry_birds(pos,birds)<<endl;
	
	return 0;
}
