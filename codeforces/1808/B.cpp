#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<ll>> a(n, vector<ll>(m)), b(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)  {
			cin >> a[i][j];
			b[j].push_back(a[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {
		sort(b[i].begin(), b[i].end());
	}

	ll ans = 0;

	for (int i = 0; i < m; i++) {
		ll diff = 0;

		for (ll j = 1; j < n; j++) {
			ll t = b[i][j] - b[i][j - 1];
			diff += (j * t);
			ans += diff;
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