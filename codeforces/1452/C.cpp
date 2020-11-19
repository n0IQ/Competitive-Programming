#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all v.begin(),v.end()
#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0)
	{
		string s;
		cin >> s;

		stack<char> s1;
		stack<char> s2;
		ll pairs = 0;

		for (int i = 0; i < (int)s.length(); i++)
		{
			if (s[i] == '(')
			{
				s1.push(s[i]);
			}
			else if (s[i] == '[')
			{
				s2.push(s[i]);
			}
			else if (s[i] == ')' && !s1.empty() && s1.top() == '(')
			{
				pairs++;
				s1.pop();
			}
			else if (s[i] == ']' && !s2.empty() && s2.top() == '[')
			{
				pairs++;
				s2.pop();
			}
		}

		cout << pairs << '\n';
	}

	return 0;
}