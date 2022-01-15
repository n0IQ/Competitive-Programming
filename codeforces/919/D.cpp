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

vector<int> adj[300010], in_edges[300010];
vector<bool> visited(300010, 0), stk(300010, 0);
vector<int> toposort;

bool check_cycle(int u)
{
	visited[u] = 1;
	stk[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			bool cycle = check_cycle(v);
			if (cycle) {
				return true;
			}
		}
		else if (stk[v]) {
			return true;
		}
	}

	stk[u] = 0;
	return false;
}

void dfs(int u)
{
	visited[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}

	toposort.pb(u);
}

void solve()
{
	int n, m;
	string s;
	cin >> n >> m >> s;

	s = "0" + s;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		in_edges[v].pb(u);
	}

	rep(i, 1, n + 1) {
		if (!visited[i]) {
			if (check_cycle(i)) {
				cout << "-1\n";
				return;
			}
		}
	}

	visited.assign(n + 1, 0);
	rep(i, 1, n + 1) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	reverse(all(toposort));

	int dp[n + 1][26];
	mem0(dp);

	// dp[i][j] = max number of repeating characters j that can be achieved when at node i

	for (auto v : toposort) {
		for (auto u : in_edges[v]) {
			rep(i, 0, 26) {
				dp[v][i] = max(dp[v][i], dp[u][i]);
			}
		}

		dp[v][s[v] - 'a']++;
	}

	int ans = 0;
	rep(i, 1, n + 1) {
		rep(j, 0, 26) {
			ans = max(ans, dp[i][j]);
		}
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