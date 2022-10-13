#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	vector<ll> max_val(n, 0LL), height(n, 0LL);
	max_val[0] = a[0];
	height[0] = a[0];

	for (int i = 1; i < n; i++) {
		max_val[i] = max(max_val[i - 1], a[i]);
		height[i] = height[i - 1] + a[i];
	}

	/*for (auto &x : max_val) cout << x << ' ';
	cout << '\n';
	for (auto &x : height) cout << x << ' ';
	cout << '\n';*/

	for (int i = 0; i < q; i++) {
		ll k;
		cin >> k;

		int l = 0, r = n - 1, idx = -1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (max_val[mid] > k) {
				r = mid - 1;
			}
			else {
				idx = mid;
				l = mid + 1;
			}
		}

		// cout << i << ' ' << idx << '\n';

		if (idx == -1) cout << "0 ";
		else cout << height[idx] << ' ';
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