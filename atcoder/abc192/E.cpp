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
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

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
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 1e5;
int n, m;
vector<vector<tuple<int, int, int>>> adj;
vll d;
vb visited;

ll Dijkstra(int s, int dst)
{
	priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater <pair<ll, int>>> q;
	d.assign(N + 5, 1e18);

	q.push({0LL, s});
	d[s] = 0;

	while (!q.empty()) {
		int minVertex = q.top().ss;
		ll time = q.top().ff;
		q.pop();

		if (time < d[minVertex]) {
			continue;
		}

		if (minVertex == dst) {
			return time;
		}

		for (auto e : adj[minVertex]) {
			int v = get<0>(e);
			ll t = get<1>(e), k = get<2>(e);

			ll cost = (time % k == 0 ? time / k : time / k + 1);
			cost *= k;

			if (cost + t < d[v]) {
				d[v] = cost + t;
				q.push({d[v], v});
			}
		}
	}

	return -1;
}

void solve()
{
	adj.clear(); d.clear(); visited.clear();

	int source, destination;
	cin >> n >> m >> source >> destination;

	adj.resize(N + 5);
	rep(i, m) {
		int u, v, t, k; cin >> u >> v >> t >> k;
		adj[u].pb(make_tuple(v, t, k));
		adj[v].pb(make_tuple(u, t, k));
	}

	cout << Dijkstra(source, destination) << '\n';
}

int main()
{
	fastio;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}