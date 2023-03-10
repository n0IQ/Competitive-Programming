#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll x = (a[i] + 1) / 2;
		while (k < x) {
			ans++;
			x = (x + 1) / 2;
		}

		k = max(k, a[i]);
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
	// cin >> t;
	while (t--) solve();

	return 0;
}