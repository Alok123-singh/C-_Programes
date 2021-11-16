#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod ((int)1e9+7)
#define inf 1e18
#define endl "\n"
#define p_b push_back
using namespace std;

void replace_space(char str[])
{
	int spaces = 0;
	for(int i=0; i<strlen(str); i++) if(str[i] == ' ') spaces++;
	
	int idx = strlen(str) + 2*spaces;
	str[idx] = '\0';
	
	for(int i=strlen(str)-1; i>=0; i--)
	{
		if(str[i] == ' ')
		{
			str[idx-1] = '0';
			str[idx-2] = '2';
			str[idx-3] = '%';
			idx -= 3;
		}
		else
		{
			str[idx-1] = str[i];
			idx--;
		}
	}
	
}

int main()
{
    char str[10000];
    cin.getline(str,1000);
    
    replace_space(str);
    cout<<str<<endl;
    
	return 0;
}

