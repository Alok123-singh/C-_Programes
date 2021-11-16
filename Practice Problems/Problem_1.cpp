#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define hell 1e15
#define inf 1e18
#define p_b push_back
using namespace std;

/*
  Given a sorted array initially.There is a person who is swapping in the array as follows -:
  (i) - First he chooses two odd indices which were not choosen before
  (ii) - Second he swaps the values present in those indices
  And he continues this process some number of times.
  Now our task is that we need to check whether an element (key) is present in the array or not.
   
   1 <= T <= 1e5
   1 <= N <= 1e6
   where T is no. of test cases and N is total elements present in array
*/

int solve(int arr[],int n,int key){
	if(arr[n] == key){
		return (n);
	}
	if(arr[1] == key){
		return (1);
	}
	if(n>2 && arr[2] == key){
		return (2);
	}
	
	int s = 2;
	int e = n%2 == 0 ? n : n-1;
	int pp;
	while(s <= e){
		int mid = (s+e)/2;
		if(mid%2 != 0) mid++;
		
		if(e - s == 2){
			pp = (s+e)/2;
			break;
		}
		
		if(arr[mid] == key){
		    return(mid);
		}
		else if(key < arr[mid]){
			e = mid;
		}
		else{
			s = mid;
		}
	}
	
	if(arr[pp-1] > key) pp = 1;
	if(arr[pp+1] < key) pp = n;
	
	if(arr[pp] == key) return(pp);
	int new_key = arr[pp];
	s = 2;
	e = n%2 == 0 ? n : n-1;
	while(s <= e){
		int mid = (s+e)/2;
		if(mid%2 != 0) mid++;
		
		if(e - s == 2){
			int new_pp = (s+e)/2;
			if(arr[new_pp-1] > new_key) new_pp = 1;
			if(arr[new_pp] == key){
				return new_pp;
			}
			break;
		}
		
		if(new_key < arr[mid]){
			e = mid;
		}
		else{
			s = mid;
		}
	}
	
	return (-1);
}

int main()
{
	FIO
	int t = 1; //cin>>t;
	
	while(t--){
	    int n = 8,k = 25; //cin>>n>>k;
	    int arr[n+1] = {0,19,3,10,8,5,12,1,25}; //for(int i=1; i<=n; i++) cin>>arr[i];
	    cout<<solve(arr,n,k)<<endl;
    }
	
	return 0;
}

