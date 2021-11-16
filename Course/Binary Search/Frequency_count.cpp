#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

int lower_bound(vector<int> A,int key){ // O(logN)
	int s = 0;
	int e = A.size() - 1;
	
	int ans = -1;
	while(s <= e){
		int mid = (s+e)/2;
		if(A[mid] == key){
			ans = mid;
			e = mid - 1;
		}
		else if(A[mid] > key){
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	
	return(ans);
}

int upper_bound(vector<int> A,int key){ // O(logN)
	int s = 0;
	int e = A.size() - 1;
	
	int ans = -1;
	while(s <= e){
		int mid = (s+e)/2;
		
		if(A[mid] == key){
			ans = mid;
			s = mid + 1;
		}
		else if(A[mid] < key){
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
    vector<int> A{0,0,1,2,2,2,2,2,3,3,4,4,5,5,6,6,6,6};
    int key = 2;
    int l_b = lower_bound(A,key);
	int u_b = upper_bound(A,key);
	int f = u_b != -1 ? u_b - l_b + 1 : 0;
	
	cout<<"Lower bound of "<<key<<" is: "<<l_b<<endl;
	cout<<"Upper bound of "<<key<<" is: "<<u_b<<endl;
	// finding frequency using our own lower_bound and upper_bound functions as follows
	cout<<"\nFrequency of "<<key<<" is: "<<f<<endl;
	// finding frequency using stl lower_bound and upper_bound functions as follows
	cout<<"\nFrequency of "<<key<<" is: "<<upper_bound(A.begin(),A.end(),key) - lower_bound(A.begin(),A.end(),key);
	cout<<endl;
	
	return 0;
}
