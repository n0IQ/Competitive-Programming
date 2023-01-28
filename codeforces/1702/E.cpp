#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ans;

void dfs(vector<vector<int>> &adj, vector<int> &color, int u, int c)
{
	color[u] = c;
	for (auto &v : adj[u]) {
		if (color[v] == 0) {
			dfs(adj, color, v, 3 - c);
		}
		else if (color[u] == color[v]) {
			ans = false;
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	ans = true;
	vector<vector<int>> adj(n + 1);
	map<int, int> mp;

	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		mp[u]++, mp[v]++;
		if (u == v || mp[u] > 2 || mp[v] > 2) ans = false;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if (!ans) {
		cout << "NO\n";
		return;
	}

	vector<int> color(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
			dfs(adj, color, i, 1);
			if (!ans) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
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