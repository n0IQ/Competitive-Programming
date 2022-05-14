#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	sort(a.begin(), a.end());

	while (q--) {
		int x;
		cin >> x;

		auto it = lower_bound(a.begin(), a.end(), x);
		int ans = (a.end() - it);
		cout << ans << '\n';
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int tt = 1;
	//cin >> t;
	while (tt--) solve();

	return 0;
}