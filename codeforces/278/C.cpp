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

bool arr[101][101];
vector<int> p, r;
int n, m;

int find_set(int x)
{
	if (x == p[x]) return x;
	return p[x] = find_set(p[x]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b = find_set(b);

	if (a != b) {
		if (r[a] < r[b]) {
			swap(a, b);
		}

		p[b] = a;
		r[a] += r[b];

		rep(i, 1, m + 1) {
			if (arr[b][i]) arr[a][i] = 1;
		}
	}
}

bool check(int u, int v)
{
	bool ok = 0;
	rep(i, 1, m + 1) {
		if (arr[u][i] == 1 && arr[v][i] == 1) ok = 1;
	}

	return ok;
}

void solve()
{
	cin >> n >> m;

	rep(i, 1, n + 1) {
		int k;
		cin >> k;

		rep(j, 0, k) {
			int x;
			cin >> x;
			arr[i][x] = 1;
		}
	}

	p.resize(n + 1);
	iota(all(p), 0);
	r.resize(n + 1, 1);

	rep(i, 1, n + 1) {
		rep(j, i + 1, n + 1) {
			int u = find_set(i);
			int v = find_set(j);

			if (u != v && check(u, v)) {
				union_set(u, v);
			}
		}
	}

	set<int> s;
	rep(i, 1, n + 1) {
		s.insert(find_set(i));
	}

	bool ok = 0;
	for (auto x : s) {
		rep(i, 1, m + 1) {
			if (arr[x][i]) ok = 1;
		}
	}

	if (ok) cout << max(0, sz(s) - 1) << '\n';
	else cout << sz(s) << '\n';
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