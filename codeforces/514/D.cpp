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

int n, m, k;
vector<ll> ans, temp;

struct SparseTable {
	int n;
	int MAXLOG = 20;
	vector<int> LOG;
	vector<vector<ll>> st;

	void init(int _n)
	{
		n = _n;
		st = vector<vector<ll>> (n, vector<ll> (MAXLOG, 0));
		LOG.resize(n + 10, 0);
		LOG[1] = 0;
		for (int i = 2; i <= n; i++) {
			LOG[i] = LOG[i / 2] + 1;
		}
	}

	void build(vector<ll> &arr)
	{
		for (int i = 0; i < n; i++) {
			st[i][0] = arr[i];
		}

		for (int j = 1; j < MAXLOG; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	ll query(int l, int r)
	{
		int j = LOG[r - l + 1];
		return max(st[l][j], st[r - (1 << j) + 1][j]);
	}
};

SparseTable table[5];

bool check(int l, int r)
{
	ll sum = 0LL;
	temp.assign(m, 0);

	rep(i, 0, m) {
		ll x = table[i].query(l, r);
		temp[i] += x;
		sum += x;
	}

	return sum <= k;
}

void solve()
{
	cin >> n >> m >> k;

	vector<vector<ll>> arr(m, vector<ll>(n));
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> arr[j][i];
		}
	}

	rep(i, 0, m) {
		table[i].init(n);
		table[i].build(arr[i]);
	}

	ans.resize(m, 0);
	int mx = 0;
	rep(i, 0, n) {
		int l = i, r = n - 1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (check(i, mid)) {
				if (mx < mid - i + 1) {
					mx = mid - i + 1;
					ans = temp;
				}
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
	}

	rep(i, 0, sz(ans)) cout << ans[i] << ' ';
	cout << '\n';
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