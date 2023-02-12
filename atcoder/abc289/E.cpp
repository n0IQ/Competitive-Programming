#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<int> color;
bool isPossible;

ll bfs(int x, int y, int tx, int ty)
{
	queue<pair<int, int>> q;
	vector<vector<int>> dist(n + 1, vector<int> (n + 1, INT_MAX));
	q.push({x, y});
	dist[x][y] = 0;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		ll d = dist[x][y];

		for (auto &ngb1 : adj[x]) {
			for (auto &ngb2 : adj[y]) {
				if (color[ngb1] == color[ngb2]) {
					continue;
				}

				if (dist[ngb1][ngb2] > 1 + dist[x][y]) {
					dist[ngb1][ngb2] = 1 + dist[x][y];
					q.push({ngb1, ngb2});
				}
			}
		}
	}

	return dist[tx][ty] == INT_MAX ? -1 : dist[tx][ty];
}

void solve()
{
	cin >> n >> m;

	adj.clear(), color.clear();
	adj.resize(n + 1), color.resize(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << bfs(1, n, n, 1) << '\n';
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