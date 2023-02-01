#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	ll ans = INT_MAX;
	for (ll x = 0; x <= a[0]; x++) {
		ll min_val = INT_MAX, max_val = INT_MIN, flag = 0;

		for (int i = 0; i < n; i++) {
			ll l = 1, r = k, div = -1;

			while (l <= r) {
				ll mid = l + (r - l) / 2;
				if (a[i] / mid >= x) {
					div = a[i] / mid;
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}

			if (div == -1) {
				flag = 1;
				break;
			}

			min_val = min(min_val, div);
			max_val = max(max_val, div);
		}

		if (!flag) {
			ans = min(ans, max_val - min_val);
		}
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