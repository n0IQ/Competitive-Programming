#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

vector<vector<pii>> adj;
vi d, p;
vb visited;
int n, m;

void Dijkstra(int s)
{
	d.assign(n + 1, INT_MAX);
	p.assign(n + 1, -1);
	visited.assign(n + 1, false);
	d[s] = 0;

	priority_queue <pii, vpii, greater<pii>> q;
	q.push({0, s});

	while (!q.empty()) {
		int minVertex = q.top().ss;
		int distance = q.top().ff;

		visited[minVertex] = true;
		q.pop();

		if (distance != d[minVertex]) {
			continue;
		}

		for (auto edge : adj[minVertex]) {
			int v = edge.ff, wt = edge.ss;

			if (d[minVertex] + wt < d[v] && !visited[v]) {
				d[v] = d[minVertex] + wt;
				p[v] = minVertex;
				q.push({d[v], v});
			}
		}
	}
}

void Solve()
{
	Dijkstra(1);

	if (d[n] == INT_MAX) {
		cout << -1 << '\n';
		return;
	}

	vi path;

	for (int i = n; i != 1; i = p[i]) {
		path.pb(i);
	}

	path.pb(1);

	reverse(all(path));

	for (auto x : path) {
		cout << x << " ";
	}
}

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;

	adj.resize(n + 1);

	rep(i, m) {
		int u, v, wt; cin >> u >> v >> wt;
		adj[u].pb({v, wt});
		adj[v].pb({u, wt});
	}

	Solve();

	return 0;
}