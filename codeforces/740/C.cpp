#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<pair<ll, ll>> a(m);
	ll mex = INT_MAX;
	for (auto &i : a) {
		cin >> i.first >> i.second;
		mex = min(mex, i.second - i.first + 1);
	}

	sort(a.begin(), a.end());
	vector<ll> ans(n, -1);
	ll val = 0;

	for (int i = a[0].first - 1; i < n; i++) {
		ans[i] = val % mex;
		val++;
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) {
			ans[i] = 0;
		}
	}

	cout << mex << '\n';
	for (auto &x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
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
	// cin >> t;
	while (t--) solve();

	return 0;
}