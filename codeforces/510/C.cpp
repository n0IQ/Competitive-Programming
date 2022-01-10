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

vector<int> adj[30];
vector<bool> visited(30, 0), stk(30, 0);
vector<int> toposort;

bool dfs(int u)
{
	visited[u] = 1;
	stk[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			bool cycle = dfs(v);
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

void dfs2(int u)
{
	visited[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			dfs2(v);
		}
	}

	toposort.pb(u);
}

void solve()
{
	int n;
	cin >> n;

	vector<string> a(n);
	for (auto &s : a) cin >> s;

	rep(i, 0, n - 1) {
		string s = a[i], t = a[i + 1];
		int u = -1, v = -1;

		rep(j, 0, min(sz(s), sz(t))) {
			if (s[j] != t[j]) {
				u = s[j] - 'a', v = t[j] - 'a';
				adj[u].pb(v);
				break;
			}
		}

		if (u == -1 && sz(s) > sz(t)) {
			cout << "Impossible\n";
			return;
		}
	}

	rep(i, 0, 26) {
		if (!visited[i]) {
			if (dfs(i)) {
				cout << "Impossible\n";
				return;
			}
		}
	}

	visited.assign(30, 0);
	rep(i, 0, 26) {
		if (!visited[i]) {
			dfs2(i);
		}
	}
	reverse(all(toposort));

	debug(toposort)
	visited.assign(30, 0);
	string ans;
	for (auto x : toposort) {
		ans.pb('a' + x);
		visited[x] = 1;
	}

	debug(ans)
	rep(i, 0, 26) {
		if (!visited[i]) {
			ans.pb('a' + i);
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