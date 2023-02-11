#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &temp, int u)
{
	visited[u] = 1;
	temp.push_back(u);

	for (auto &v : adj[u]) {
		if (!visited[v]) {
			dfs(adj, visited, temp, v);
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u;
		cin >> u;
		int v = u + 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> ans;
	vector<bool> visited(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			vector<int> temp;
			dfs(adj, visited, temp, i);
			sort(temp.begin(), temp.end(), greater<>());
			for (auto &x : temp) ans.push_back(x);
		}
	}

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
	// cin >> t;
	while (t--) solve();

	return 0;
}