#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (k <= n) {
		ll ans = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (i >= k - 1) {
				ans = max(ans, sum);
				sum -= a[i - k + 1];
			}
		}

		cout << ans + (k * (k - 1)) / 2 << '\n';
	}
	else {
		ll total = accumulate(a.begin(), a.end(), 0LL);
		cout << total + ((k - n) * 1LL * n) + ((n * 1LL * (n - 1LL)) / 2LL) << '\n';
	}
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