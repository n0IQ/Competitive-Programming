#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

/*---------------------------------------------------------Debugging----------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------------------------------------------*/

vector<pii> adj[1001];
vector<pair<pii, int>> edges;
vector<pii> routes;
vector<vector<ll>> d;

vector<ll> Dijkstra(int n, int s)
{
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	vector<ll> dist(n + 1, INF);
	pq.push({0, s});
	dist[s] = 0;

	while (!pq.empty()) {
		int u = pq.top().ss;
		ll temp_d = pq.top().ff;
		pq.pop();

		if (temp_d != dist[u]) {
			continue;
		}

		for (auto e : adj[u]) {
			int v = e.ff, w = e.ss;

			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	rep(i, 0, m) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		edges.pb({{u, v}, w});
	}

	d.resize(n + 1);

	rep(i, 1, n + 1) { // precalc all pair shortest paths
		d[i] = Dijkstra(n, i);
	}

	rep(i, 1, k + 1) {
		int u, v;
		cin >> u >> v;
		routes.pb({u, v});
	}

	debug(d)
	debug(edges)
	debug(routes)

	ll ans = INF;

	rep(i, 0, m) {
		int remove_x = edges[i].ff.ff, remove_y = edges[i].ff.ss;
		ll sum = 0;

		rep(j, 0, k) {
			int curr_x = routes[j].ff, curr_y = routes[j].ss;
			if (curr_x == curr_y) continue;
			sum += min({d[curr_x][remove_x] + d[curr_y][remove_y], d[curr_x][remove_y] + d[curr_y][remove_x], d[curr_x][curr_y]});
		}

		ans = min(ans, sum);
	}

	cout << ans << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("Error.txt", "w", stderr);
#endif

	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}