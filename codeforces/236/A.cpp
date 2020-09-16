#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define vsort sort(v.begin(),v.end())
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

	#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif
	
	string s;
	cin >> s;

	int distinct = 1;

	sort(s.begin(),s.end());

	for (int i = 0; i < s.length()-1; ++i)
	{
		if(s[i] != s[i+1])
		{
			distinct++;
		}
	}

	if(distinct % 2 == 0)
	{
		cout << "CHAT WITH HER!" << endl;
	}
	else
	{
		cout << "IGNORE HIM!" << endl;
	}
	
	return 0;
}