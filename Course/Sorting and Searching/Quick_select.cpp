#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

// find kth element in a sorted array

void swap(vector<int> &arr,int i,int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int quick_select(vector<int> &arr,int st,int en,int k)
{
	if(st >= en){
		return (-1);
	}
	
	int pivot = en;
	int i=-1;
	int j=0;
	
	while(j<pivot){
		if(arr[j] > arr[pivot]) j++;
		else{
			i++;
			swap(arr,i,j);
			j++;
		}
	}
	swap(arr,i+1,pivot);
	
	if(i+1+1 == k) return(arr[i+1]);
	else if(k < i+1+1) return quick_select(arr,st,i,k);
	else return quick_select(arr,i+2,en,k);
}

int main()
{
	vector<int> arr{777, 83, 417, 746}; // 0 2 4 5 6 7 10
	int k = 3;
	
	cout<<quick_select(arr,0,arr.size()-1,k)<<endl;
	
	return(0);
}
