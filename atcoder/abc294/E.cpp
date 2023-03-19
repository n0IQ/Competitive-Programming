#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll l, n, m;
	cin >> l >> n >> m;

	vector<pair<ll, ll>> a(n), b(m);
	for (auto &i : a) cin >> i.first >> i.second;
	for (auto &i : b) cin >> i.first >> i.second;

	ll ans = 0, col1 = 1, col2 = 1;

	for (int i = 0, j = 0; i < n && j < m;) {
		if (a[i].first == b[j].first) {
			ll x1 = col1, y1 = col1 + a[i].second - 1;
			ll x2 = col2, y2 = col2 + b[j].second - 1;
			ans += (min(y1, y2) - max(x1, x2) + 1);

			if (y1 == y2) {
				i++, j++;
				col1 = y1 + 1;
				col2 = y2 + 1;
			}
			else if (y1 < y2) {
				i++;
				col1 = y1 + 1;
			}
			else {
				j++;
				col2 = y2 + 1;
			}
		}
		else {
			ll r1 = col1 + a[i].second - 1, r2 = col2 + b[j].second - 1;
			if (r1 == r2) {
				i++, j++;
				col1 = r1 + 1;
				col2 = r2 + 1;
			}
			else if (r1 < r2) {
				i++;
				col1 = r1 + 1;
			}
			else {
				j++;
				col2 = r2 + 1;
			}
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
	// cin >> t;
	while (t--) solve();

	return 0;
}