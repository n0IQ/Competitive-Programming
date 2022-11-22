#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int, int>> adj[100010];
vector<int> ans;

bool dfs(int u, int p)
{
	bool flag = false;

	for (auto &it : adj[u]) {
		int v = it.first, t = it.second;

		if (v != p) {
			bool ok = dfs(v, u);

			if (t == 2) {
				if (!ok) {
					ans.push_back(v);
				}
				flag = true;
			}
			else {
				flag |= ok;
			}
		}
	}

	return flag;
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({v, t});
		adj[v].push_back({u, t});
	}

	dfs(1, 0);

	cout << ans.size() << '\n';
	for (auto &x : ans) {
		cout << x << ' ';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}