#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u, int &nodes, int &edges)
{
	visited[u] = 1;
	nodes++;
	edges += (int)adj[u].size();

	for (auto &v : adj[u]) {
		if (!visited[v]) {
			dfs(adj, visited, v, nodes, edges);
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

	bool isPossible = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int nodes = 0, edges = 0;
			dfs(adj, visited, i, nodes, edges);
			if (nodes != edges / 2) isPossible = false;
		}
	}

	if (isPossible) cout << "Yes\n";
	else cout << "No\n";
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