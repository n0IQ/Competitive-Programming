#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool flag = 0;
ll ans;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u)
{
	if (flag) return;

	ans++;
	if (ans >= 1000000) {
		flag = 1;
		return;
	}

	for (auto &v : adj[u]) {
		if (!visited[v]) {
			visited[v] = 1;
			dfs(adj, visited, v);
			visited[v] = 0;
		}
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
	visited[1] = 1;
	ans = 0, flag = 0;
	dfs(adj, visited, 1);

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
	//cin >> t;
	while (t--) solve();

	return 0;
}