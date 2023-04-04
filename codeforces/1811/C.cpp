#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n - 1);
	for (auto &x : a) cin >> x;

	vector<ll> ans(n);
	ans[0] = a[0];

	for (int i = 1; i < n; i++) {
		if (i == n - 1) ans[i] = a[i - 1];
		else {
			ans[i] = min(a[i], a[i - 1]);
		}
	}

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
	cin >> t;
	while (t--) solve();

	return 0;
}