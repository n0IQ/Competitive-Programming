#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<int> l(26, 0), u(26, 0);
	for (auto &ch : s) {
		if (ch >= 'a' && ch <= 'z') l[ch - 'a']++;
		else u[ch - 'A']++;
	}

	ll ans = 0;
	for (int i = 0; i < 26; i++) {
		int t = min(l[i], u[i]);
		ans += t;
		l[i] -= t;
		u[i] -= t;
	}

	for (int i = 0; i < 26 && k > 0; i++) {
		int t = max(l[i], u[i]);
		int ops = min(t / 2, k);
		ans += ops;
		k -= ops;
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