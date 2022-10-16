#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	string s;
	cin >> s;

	map<int, char> mp;

	for (int i = 0; i < n; i++) {
		if (mp.count(a[i])) {
			if (s[i] != mp[a[i]]) {
				cout << "NO\n";
				return;
			}
		}
		else {
			mp[a[i]] = s[i];
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