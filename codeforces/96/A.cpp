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
	cin >> s;

	string s1 = "0000000";
	string s2 = "1111111";

	if (s.find(s1) != string::npos || s.find(s2) != string::npos)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}