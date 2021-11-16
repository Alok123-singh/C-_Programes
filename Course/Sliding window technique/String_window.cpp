
#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

string string_window(string s,string p) // O(N)
{
	unordered_map<char,int> fp; // hashmap for pattern p
	unordered_map<char,int> fs; // hashmap for current_window
	
	for(char ch: p) fp[ch]++;
	
	int cnt = 0; // to count the total charcters match among current_window and pattern
	int start = 0; // start of the current_window
	int start_idx = -1; // start of the minimum window
	int min_so_far = INT_MAX; // length of the minimum window
	
	for(int i=0; i<s.length(); i++)
	{
		// including current charcter by increasing its count in fs hashmap or expanding our current window
		char ch = s[i];
		fs[ch]++;
		
		// checking whether to count the current character in cnt or not
		/* current character will only be counted if it is present in the pattern and its frequency in hashmap fs
		   is smaller than or equal to frequency in hashmap fp */
		if(fp[ch] != 0 and fs[ch] <= fp[ch])
		{
			cnt++;
		}
		
		// checking whether we have all the elements of pattern in our current_window or not
		if(cnt == p.length())
        {
        	// contracting our current_window by removing unwanted characters
        	// unwanted character means either it is not present in pattern or its frequency is higher than required
        	while(fp[s[start]] == 0 || fs[s[start]] > fp[s[start]])
        	{
        		fs[s[start]]--;
        		start++;
			}
        	
        	int window_size = i - start + 1;
        	
        	// checking whether our current_window is smallest or not
        	if(window_size < min_so_far)
        	{
        		min_so_far = window_size;
        		start_idx = start;
			}
		}
	}
	// returning smallest window
	
	if(start_idx == -1) return("No substring found");
	
	return (s.substr(start_idx,min_so_far));
}

int main()
{
	int t{1}; //cin>>t;
	while(t--)
	{
	    string s{"helloe"},p{"oel"}; //cin>>str;
		cout<<string_window(s,p)<<endl;
	}
	
	return 0;
}

