#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

int rotated_search(vector<int> A,int key){ // O(logN)
	int s = 0;
	int e = A.size() - 1;
	
	while(s <= e){
		int mid = (s+e)/2;
		
		if(A[mid] == key){
			return mid;
		}
		
		// checking whether mid is present on left side with respect to pivot point or not
		if(A[mid] >= A[s]){
			if(key >= A[s] && key <= A[mid]){ // checking whether key is present on left side of mid or not
				e = mid - 1;
			}
			else{
				s = mid + 1;
			}
		}
		
		// checking whether mid is present on right side with respect to pivot point or not
		if(A[mid] < A[e]){
			if(key >= A[mid] && key <= A[e]){ // checking whether key is present on right side of mid or not
				s = mid + 1;
			}
			else{
				e = mid - 1;
			}
		}
	}
	
	return (-1);
}

int main()
{
    vector<int> A{4,5,6,7,0,1,2,3};
    int key = 4;
    
    cout<<rotated_search(A,key)<<endl;
	
	return 0;
}
