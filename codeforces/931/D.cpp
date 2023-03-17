#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[100001];

void solve()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	ll ans = 0;
	queue<pair<int, int>> q; // node, parent
	q.push({1, 0});

	while (!q.empty()) {
		int sz = (int)q.size();
		ans += (sz % 2);

		for (int i = 0; i < sz; i++) {
			int u = q.front().first, p = q.front().second;
			q.pop();

			for (auto &v : adj[u]) {
				if (v != p) {
					q.push({v, u});
				}
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