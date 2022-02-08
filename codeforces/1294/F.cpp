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
vector<int> adj[MAXN];
vector<int> par;

pii dfs(int u, int p = -1, int d = 0)
{
	par[u] = p;
	pii res = {d, u};

	for (auto v : adj[u]) {
		if (v != p) {
			res = max(res, dfs(v, u, d + 1));
		}
	}

	return res;
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

	par.resize(n);
	int a, b, c;

	pii p1 = dfs(0);
	pii p2 = dfs(p1.ss);

	a = p1.ss, b = p2.ss;
	vector<int> path;
	int u = b;
	while (u != a) {
		path.pb(u);
		u = par[u];
	}
	path.pb(a);

	if (sz(path) == n) {
		cout << n - 1 << '\n';
		cout << path[0] + 1 << ' ' << path[1] + 1 << ' ' << path.back() + 1 << '\n';
		return;
	}

	queue<int> q;
	vector<bool> visited(n, 0);
	vector<int> dist(n, 0);
	for (auto x : path) {
		q.push(x);
		visited[x] = 1;
		dist[x] = 0;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = 1;
				dist[v] = dist[u] + 1;
			}
		}
	}

	int max_d = -1;
	rep(i, 0, n) {
		if (dist[i] > max_d) {
			max_d = dist[i];
			c = i;
		}
	}

	cout << p2.ff + max_d << '\n';
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