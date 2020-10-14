#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vsort sort(v.begin(),v.end())
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	getline(cin, s);
	//cout << s;

	int flag = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
			flag = 1;
	}

	if (flag == 1)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}