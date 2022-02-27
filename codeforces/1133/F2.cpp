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

vector<int> p, r;

int find_set(int x)
{
	if (x == p[x]) return x;
	return p[x] = find_set(p[x]);
}

int union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (r[a] < r[b]) {
			swap(a, b);
		}

		p[b] = a;
		r[a] += r[b];
		return 1;
	}

	return 0;
}

void solve()
{
	int n, m, d, a, b;
	cin >> n >> m >> d;

	vector<pii> edges, temp_edge;
	vector<int> deg(n + 1, 0);

	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		if (u == 1 || v == 1) temp_edge.pb({u, v});
		else edges.pb({u, v});
		deg[u]++;
		deg[v]++;
	}

	debug(deg)

	p.resize(n + 1);
	iota(all(p), 0);
	r.resize(n + 1, 1);

	for (auto [u, v] : edges) {
		a = find_set(u);
		b = find_set(v);

		if (a != b) {
			union_set(a, b);
		}
	}

	set<int> nodes;
	rep(i, 2, n + 1) {
		nodes.insert(find_set(i));
	}

	debug(p)
	debug(nodes)

	if (d > deg[1] || d < sz(nodes)) {
		cout << "NO\n";
		return;
	}

	set<pii> ans;

	debug(p)
	debug(r)

	for (auto [u, v] : temp_edge) {
		if (d == 0) break;

		a = find_set(u);
		b = find_set(v);

		if (a != b) {
			ans.insert({u, v});
			union_set(a, b);
			d--;
		}
	}

	debug(nodes)
	debug(ans)

	for (auto [u, v] : temp_edge) {
		if (d == 0) break;
		if (!ans.count({u, v}) && !ans.count({v, u})) {
			ans.insert({u, v});
			d--;
		}
	}

	debug(ans)

	iota(all(p), 0);
	r.assign(n + 1, 1);
	for (auto it : ans) {
		a = find_set(it.ff);
		b = find_set(it.ss);
		union_set(a, b);
	}

	for (auto [u, v] : edges) {
		int a = find_set(u);
		int b = find_set(v);
		if (a != b) {
			bool ok = union_set(a, b);
			ans.insert({u, v});
		}
	}

	debug(ans)

	cout << "YES\n";
	for (auto it : ans) {
		cout << it.ff << ' ' << it.ss << '\n';
	}
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