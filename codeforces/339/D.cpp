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

template <typename T> class SegTree {
public:
	int n;
	T e;
	vector<T> st;

	SegTree(int _n, T _e = T()) {
		n = _n;
		e = _e;
		st.resize(4 * n + 10);
	}

	T merge(const T &l, const T &r, bool &ok)
	{
		if (ok) {
			ok ^= 1;
			return (l | r);
		}
		else {
			ok ^= 1;
			return (l ^ r);
		}
	}

	template<typename U> void build(U &arr, int i, int l, int r, bool &ok)
	{
		if (l == r) {
			st[i] = T(arr[l]);
			ok = 1;
			return;
		}

		int mid = l + (r - l) / 2;
		build(arr, i << 1, l, mid, ok);
		build(arr, i << 1 | 1, mid + 1, r, ok);

		st[i] = merge(st[i << 1], st[i << 1 | 1], ok);
	}

	template<typename U> void Update(int i, int l, int r, int idx, U val, bool &ok)
	{
		if (l == r) {
			st[i] = T(val);
			ok = 1;
			return;
		}

		int mid = l + (r - l) / 2;
		if (idx <= mid)
			Update(i << 1, l, mid, idx, val, ok);
		else
			Update(i << 1 | 1, mid + 1, r, idx, val, ok);

		st[i] = merge(st[i << 1], st[i << 1 | 1], ok);
	}

	template<typename U> void update(int idx, U val, bool ok)
	{
		Update(1, 0, n - 1, idx, val, ok);
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;

	n = (1 << n);
	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	SegTree<ll> segtree(n);

	bool ok = 0;
	segtree.build(a, 1, 0, n - 1, ok);

	while (m--) {
		int idx;
		ll val;
		cin >> idx >> val;
		--idx;
		ok = 0;
		segtree.update(idx, val, ok);
		cout << segtree.st[1] << '\n';
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