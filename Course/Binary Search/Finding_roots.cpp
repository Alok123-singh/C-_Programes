#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

double finding_root(int n,int p){
	int s = 0;
	int e = n;
	
	double r;
	while(s <= e){
		int mid = (s+e)/2;
		
		if(mid*mid == n){
			return (mid);
		}
        else if((mid*mid) < n){
        	r = (double)mid;
        	s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	
	double inc = 0.1L;
	for(int i=1; i<=p; i++){
		
		while(r*r <= n){
			r += inc;
		}
		
		r = r - inc;
		inc = inc/10.0;
	}
	
	return (r);
}

int main()
{
    cout<<finding_root(10,10)<<endl;
	
	return 0;
}
