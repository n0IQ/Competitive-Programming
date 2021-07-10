#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 2e5;
vector<pair<int, int>> adj[N];
int dist[N], vis[N];

void Dijkstra(int source)
{
	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX;
		vis[i] = 0;
	}

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	dist[source] = 0;
	q.push({0, source});

	while (!q.empty()) {
		int x = q.top().second;
		int distance = q.top().first;
		q.pop();
		vis[x] = true;

		if (distance != dist[x]) {
			continue;
		}

		for (auto it : adj[x]) {
			int node = it.first, wt = it.second;

			if (!vis[node] && dist[x] + wt < dist[node]) {
				dist[node] = dist[x] + wt;
				q.push({dist[node], node});
			}
		}
	}
}

void solve()
{
	int n, q;
	cin >> n >> q;

	rep(i, 0, n - 1) {
		int u, v; cin >> u >> v;
		adj[u].pb({v, 1});
		adj[v].pb({u, 1});
	}

	Dijkstra(1);

	rep(i, 0, q) {
		int u, v; cin >> u >> v;

		int d = abs(dist[u] - dist[v]);

		if (d % 2 == 0) cout << "Town" << '\n';
		else cout << "Road" << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}