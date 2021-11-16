#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define p_b push_back
using namespace std;

pair<int,int> min_pairs(vector<int> A,vector<int> B){
	// sorting the elements present on second vector
	sort(B.begin(),B.end());

	int p1=-1,p2=-1; // for empty vectors
	int min_diff = INT_MAX;
	// iterating over the elements of first vector and keep looking the lowe_bound of that element in second vector
	for(auto x: A){
		//finding the index of lower bound of x in vector B
		int lb = lower_bound(B.begin(),B.end(),x) - B.begin();
		
		//checking the difference with (lb-1)th element in vector B with respect to element x from vector A
		if(lb-1 >= 0 && x - B[lb-1] < min_diff){
			min_diff = x - B[lb-1];
			p1 = B[lb-1];
			p2 = x;
		}
		
		/* checking whether lb is valid or not as well as checking the difference of (lb)th element of vector B
		   with respect to element x from vector A */
		if(lb != B.size() && B[lb] - x < min_diff){
			min_diff = B[lb] - x;
			p1 = x;
			p2 - B[lb];
		}
	}
	
	return(make_pair(p1,p2));
}

int main()
{
    vector<int> A{-1,5,10,20,3};
    vector<int> B{26,134,135,15,17};
    
    auto ans = min_pairs(A,B);
    cout<<"Minimum difference pair is : "<<"("<<ans.first<<","<<ans.second<<")"<<endl;
	
	return 0;
}
