#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m, d;
	cin >> n >> m >> d;

	vector<int> p(n + 1);
	map<int, int> pos;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		pos[p[i]] = i;
	}

	vector<int> a(m + 1);
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}

	int ans = INT_MAX;
	for (int i = 1; i < m; i++) {
		int x = a[i], y = a[i + 1];
		int posx = pos[x], posy = pos[y];

		if (posx > posy || posy > posx + d) {
			ans = min(ans, 0);
			continue;
		}

		int steps = posy - posx;
		if (d < n - 1) {
			steps = min(steps, d - (posy - posx) + 1);
		}

		ans = min(ans, steps);
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