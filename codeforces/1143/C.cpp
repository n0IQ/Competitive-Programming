#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[100010];
int c[100010];
set<int> s;

void dfs(int u, int p)
{
	bool flag = c[u];
	for (auto &v : adj[u]) {
		if (v != p) {
			dfs(v, u);
			flag &= c[v];
		}
	}

	if (flag) s.insert(u);
}

void solve()
{
	int n, root = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p >> c[i];

		if (p != -1) {
			adj[i].push_back(p);
			adj[p].push_back(i);
		}
		else root = i;
	}

	dfs(root, -1);

	if (s.empty()) cout << "-1\n";
	else {
		for (auto &x : s) {
			cout << x << ' ';
		}
		cout << '\n';
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