#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	map<char, char> mp;

	for (int i = 0; i < n; i++) {
		if (!mp.count(s[i])) {
			if (i == 0 || mp[s[i - 1]] == '0') mp[s[i]] = '1';
			else mp[s[i]] = '0';
		}
	}

	for (int i = 0; i < n; i++) {
		s[i] = mp[s[i]];
	}

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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