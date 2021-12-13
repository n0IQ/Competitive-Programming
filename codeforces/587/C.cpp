#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
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
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
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

const int MAXN = (int)1e5 + 10;
const int LOG = 19;
vector<int> adj[MAXN], city[MAXN];
int up[MAXN][LOG];
int st[MAXN][LOG][10];
int depth[MAXN];

vector<int> merge(vector<int> a, vector<int> b)
{
	for (auto x : b) a.pb(x);
	sort(all(a));
	unique(all(a));
	a.resize(min(10, sz(a)));
	return a;
}

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

		vector<int> a = merge(city[v], city[u]);
		for (int i = 0; i < sz(a); i++) {
			st[v][0][i] = a[i];
		}

		for (int j = 1; j < LOG; j++) {
			if (up[v][j - 1] != -1) {
				vector<int> t1(10), t2(10);
				for (int i = 0; i < 10; i++) {
					t1[i] = st[v][j - 1][i];
					t2[i] = st[up[v][j - 1]][j - 1][i];
				}
				a.clear();
				a = merge(t1, t2);
				for (int i = 0; i < sz(a); i++) {
					st[v][j][i] = a[i];
				}
				//st[v][j - 1][0...10] st[up[v][j - 1]][j - 1][0...10]
			}
		}

		dfs(v, u);
	}
}

vector<int> get_lca(int u, int v)
{
	vector<int> a, b;
	if (depth[u] < depth[v]) {
		swap(u, v);
	}

	int k = depth[u] - depth[v];
	for (int j = LOG - 1; j >= 0; j--) {
		if (k & (1 << j)) {
			b.clear();
			for (int i = 0; i < 10; i++) {
				b.pb(st[u][j][i]);
			}
			a = merge(a, b);
			u = up[u][j];
		}
	}

	if (u == v) return a;

	for (int j = LOG - 1; j >= 0; j--) {
		if (up[u][j] != up[v][j]) {
			b.clear();
			for (int i = 0; i < 10; i++) {
				b.pb(st[u][j][i]);
			}
			a = merge(a, b);
			b.clear();
			for (int i = 0; i < 10; i++) {
				b.pb(st[v][j][i]);
			}
			a = merge(a, b);
			u = up[u][j];
			v = up[v][j];
		}
	}

	b.clear();
	for (int i = 0; i < 10; i++) b.pb(st[u][0][i]);
	a = merge(a, b);
	b.clear();
	for (int i = 0; i < 10; i++) b.pb(st[v][0][i]);
	a = merge(a, b);
	return a;
}

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	rep(i, 0, m) {
		int x;
		cin >> x;
		city[--x].pb(i);
	}

	rep(i, 0, n) {
		sort(all(city[i]));
		city[i].resize(min(10, sz(city[i])));
	}

	mem1(up);
	rep(i, 0, n) {
		rep(j, 0, LOG) {
			rep(k, 0, 10) st[i][j][k] = (int)1e9;
		}
	}

	dfs(0);

	while (q--) {
		int u, v, a;
		cin >> u >> v >> a;
		--u, --v;

		vector<int> ans;
		if (u == v) {
			ans = city[u];
		}
		else {
			ans = get_lca(u, v);
		}

		rep(i, 0, sz(ans)) {
			if (ans[i] >= (int)1e9) {
				ans.resize(i);
				break;
			}
		}

		ans.resize(min(sz(ans), a));
		cout << sz(ans) << ' ';
		for (auto x : ans) cout << x + 1 << ' ';
		cout << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}