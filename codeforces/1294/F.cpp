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

const int MAXN = (int)2e5 + 10;
const int LOG = 20;
vector<int> adj[MAXN];
vector<int> depth(MAXN, 0);
int up[MAXN][LOG];
int max_d, node;

void dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v == p) continue;

		depth[v] = depth[u] + 1;
		up[v][0] = u;

		for (int j = 1; j < LOG; j++) {
			if (up[v][j - 1] != -1) {
				up[v][j] = up[up[v][j - 1]][j - 1];
			}
		}

		dfs(v, u);
	}
}

int get_lca(int u, int v)
{
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int k = depth[u] - depth[v];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			u = up[u][j];
		}
	}

	if (u == v) {
		return u;
	}

	for (int j = LOG - 1; j >= 0; j--) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
		}
	}

	return up[u][0];
}

pii get_distance(int u, int v)
{
	int lca = get_lca(u, v);
	int dist = depth[u] + depth[v] - 2 * depth[lca];
	return {lca, dist};
}

void dfs2(int u, int p = -1, int d = 0)
{
	if (d > max_d) {
		max_d = d;
		node = u;
	}

	for (auto v : adj[u]) {
		if (v != p) {
			dfs2(v, u, d + 1);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int a, b, c;

	max_d = 0;
	dfs2(0);
	a = node;
	max_d = 0;
	dfs2(node);
	b = node;

	rep(i, 0, MAXN) {
		rep(j, 0, LOG) {
			up[i][j] = -1;
		}
	}

	dfs(a);

	max_d = 0;
	rep(i, 0, n) {
		if (i == a || i == b) continue;

		pii p1 = get_distance(b, i);
		pii p2 = get_distance(a, p1.ff);

		int dist = p1.ss + p2.ss;
		if (dist > max_d) {
			max_d = dist;
			c = i;
		}
	}

	cout << max_d << '\n';
	cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
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