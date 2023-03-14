#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<array<ll, 3>> a(n);
	for (int i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		a[i] = {l, r, i};
	}

	sort(a.begin(), a.end(), [&](array<ll, 3> x, array<ll, 3> y) {
		if (x[1] == y[1]) return x[0] < y[0];
		return x[1] <= y[1];
	});

	vector<ll> nonOverlap(n, 0);

	// get ranges that ends before and doesn't overlap
	for (int i = 0; i < n; i++) {
		ll l = 0, r = i - 1, mergeIndex = i;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			if (a[mid][1] >= a[i][0]) {
				mergeIndex = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		nonOverlap[a[i][2]] += (mergeIndex);
	}

	sort(a.begin(), a.end());

	// get ranges that ends after and doesn't overlap
	for (int i = 0; i < n; i++) {
		ll l = i + 1, r = n - 1, mergeIndex = i;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			if (a[mid][0] <= a[i][1]) {
				mergeIndex = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		nonOverlap[a[i][2]] += (n - 1 - mergeIndex);
	}

	ll ans = n + 10;
	for (int i = 0; i < n; i++) {
		ans = min(ans, nonOverlap[i]);
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