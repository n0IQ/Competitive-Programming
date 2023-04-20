#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string &s)
{
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] != s[i - 1]) return false;
	}

	return true;
}

ll helper(string s, int n, char ch)
{
	ll ops = 0;

	while (1) {
		if (check(s)) break;

		string t;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == ch) t.push_back(s[i]);
			else {
				i++;
				if (i < (int)s.size()) {
					t.push_back(s[i]);
				}
			}
		}

		s = t;
		ops++;
	}

	return ops;
}

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size();

	ll ans = INT_MAX;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		ll ops = helper(s, n, ch);
		ans = min(ans, ops);
		// cout << ch << ' ' << ops << '\n';
	}

	cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}