#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u, int p, int &cnt)
{
	visited[u] = 1;
	for (auto &v : adj[u]) {
		if (!visited[v]) {
			dfs(adj, visited, v, u, cnt);
		}
		else if (v != p) cnt++;
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> visited(n + 1, 0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int cnt = 0;
			dfs(adj, visited, i, 0, cnt);
			ans += cnt;
		}
	}

	cout << ans / 2 << '\n';
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