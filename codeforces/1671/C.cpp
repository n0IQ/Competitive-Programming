#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	ll x;
	cin >> n >> x;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	ll ans = 0, prefixSum = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] > x) break;
		ll l = 1, r = x + 10, sugar = 0; // 1 2 2

		while (l <= r) {
			ll mid = l + (r - l) / 2;
			ll itemPrice = a[i] + mid - 1;
			ll totalPrice = prefixSum + (i * (mid - 1)) + itemPrice;

			if (totalPrice <= x) {
				sugar = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		ans += sugar;
		prefixSum += a[i];
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