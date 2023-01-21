#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;
vector<vector<int>> adj, pathQueries;
map<pair<ll, ll>, pair<ll, ll>> mp;

void bfs(int s, int n)
{
	vector<ll> dist(n + 1, LLONG_MAX);
	vector<ll> value(n + 1, 0);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	value[s] = a[s];

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto &v : adj[u]) {
			if (dist[v] == LLONG_MAX) {
				dist[v] = dist[u] + 1;
				value[v] = value[u] + a[v];
				q.push(v);
			}
			else if (dist[u] + 1 <= dist[v] && value[v] < value[u] + a[v]) {
				value[v] = value[u] + a[v];
			}
		}
	}

	for (auto &v : pathQueries[s]) {
		if (dist[v] == LLONG_MAX) {
			mp[ {s, v}] = { -1, -1};
		}
		else {
			mp[ {s, v}] = {dist[v], value[v]};
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	adj.resize(n + 1);
	pathQueries.resize(n + 1);
	a.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'Y') {
				adj[i].push_back(j + 1);
			}
		}
	}

	int q;
	cin >> q;
	vector<pair<int, int>> queries;

	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		queries.push_back({u, v});
		pathQueries[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i, n);
	}

	for (int i = 0; i < q; i++) {
		int u = queries[i].first, v = queries[i].second;
		pair<ll, ll> p = mp[ {u, v}];
		if (p.first == -1) cout << "Impossible\n";
		else cout << p.first << ' ' << p.second << '\n';
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
	// cin >> t;
	while (t--) solve();

	return 0;
}