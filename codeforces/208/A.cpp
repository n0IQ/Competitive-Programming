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

	string str = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
		{
			i += 2;
		}
		else
		{
			str += s[i];

			if (s[i + 1] == 'W' && s[i + 2] == 'U' && s[i + 3] == 'B')
			{
				str += ' ';
			}
		}

	}

	cout << str << '\n';

	return 0;
}