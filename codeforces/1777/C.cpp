#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	set<ll> s;
	for (ll i = 1; i <= m; i++) s.insert(i);
	map<ll, ll> mp;

	ll ans = INT_MAX;
	for (int i = 0, j = 0; j < n; j++) {
		for (ll k = 1; k * k <= a[j]; k++) {
			if (a[j] % k == 0) {
				mp[k]++;
				if (mp[k] == 1) s.erase(k);
				if (a[j] / k != k) {
					mp[a[j] / k]++;
					if (mp[a[j] / k] == 1) s.erase(a[j] / k);
				}
			}
		}

		while (i <= j && s.empty()) {
			ans = min(ans, a[j] - a[i]);

			for (ll k = 1; k * k <= a[i]; k++) {
				if (a[i] % k == 0) {
					mp[k]--;
					if (mp[k] == 0 && k <= m) s.insert(k);
					if (a[i] / k != k) {
						mp[a[i] / k]--;
						if (mp[a[i] / k] == 0 && a[i] / k <= m) s.insert(a[i] / k);
					}
				}
			}

			i++;
		}
	}

	if (ans == INT_MAX) cout << "-1\n";
	else cout << ans << '\n';
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