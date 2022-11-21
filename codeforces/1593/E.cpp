#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	set<int> adj[n + 1];
	set<pair<int, int>> s;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 1; i <= n; i++) {
		s.insert({adj[i].size(), i});
	}

	while (k-- && !s.empty()) {
		set<int> temp;

		while (!s.empty() && s.begin()->first <= 1) {
			temp.insert(s.begin()->second);
			s.erase(s.begin());
		}

		for (auto &u : temp) {
			for (auto &v : adj[u]) {
				adj[v].erase(u);
				s.erase({adj[v].size() + 1, v});
				s.insert({adj[v].size(), v});
			}
			s.erase({adj[u].size(), u});
		}
	}

	cout << s.size() << '\n';
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