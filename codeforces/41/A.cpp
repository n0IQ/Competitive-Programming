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

bool Translation(string s, string t)
{
	if (s.length() != t.length())
		return false;

	int start = 0, end = s.length() - 1, flag = s.length();

	while (flag-- > 0) // 1
	{
		if (s[end] != t[start])
			return false;

		end--;
		start++;
	}

	return true;
}

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s, t;
	cin >> s >> t;
	//cout << s << " " << t << '\n';

	if (Translation(s, t))
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}