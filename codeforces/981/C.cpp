#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> adj;
vector<pair<int, int>> ans;
int node, flag;

void dfs(int u, int p)
{
	bool ok = 0;
	if (u != node && (int)adj[u].size() - 1 > 1) {
		flag = 1;
		return;
	}

	for (auto &v : adj[u]) {
		if (v == p) continue;
		ok = 1;
		dfs(v, u);
	}

	if (!ok) {
		ans.push_back({node, u});
	}
}

void solve()
{
	int n;
	cin >> n;

	adj.resize(n + 1);
	vector<int> deg(n + 1, 0);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++, deg[v]++;
	}

	int d = 0;
	for (int i = 1; i <= n; i++) {
		if (deg[i] > d) {
			node = i;
			d = deg[i];
		}
	}

	flag = 0;
	dfs(node, -1);

	if (flag) cout << "No\n";
	else {
		cout << "Yes\n";
		cout << (int)ans.size() << '\n';
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
		}
	}
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