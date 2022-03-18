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

	T merge(const T &l, const T &r)
	{
		return __gcd(l, r);
	}

	template<typename U> void build(U &arr, int i, int l, int r)
	{
		if (l == r) {
			st[i] = T(arr[l]);
			return;
		}

		int mid = l + (r - l) / 2;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);

		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	}

	template<typename U> void Update(int i, int l, int r, int idx, U val)
	{
		if (l == r) {
			st[i] = T(val);
			return;
		}

		int mid = l + (r - l) / 2;
		if (idx <=  mid)
			Update(i << 1, l, mid, idx, val);
		else
			Update(i << 1 | 1, mid + 1, r, idx, val);

		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	}

	void Query(int i, int l, int r, int ql, int qr, int x, int &cnt)
	{
		if (st[i] % x == 0 || ql > r || qr < l)
			return;
		if (l >= ql && r <= qr) {
			while (l != r) {
				int mid = l + (r - l) / 2;

				if (st[i << 1] % x != 0) {
					if (st[i << 1 | 1] % x != 0) {
						cnt += 2;
						return;
					}

					i = (i << 1);
					r = mid;
				}
				else {
					i = (i << 1 | 1);
					l = mid + 1;
				}
			}

			cnt++;
			return;
		}

		int mid = l + (r - l) / 2;
		Query(i << 1, l, mid, ql, qr, x, cnt);
		if (cnt > 1) return;
		Query(i << 1 | 1, mid + 1, r, ql, qr, x, cnt);
	}

	template<typename U> void update(int idx, U val)
	{
		Update(1, 0, n - 1, idx, val);
	}

	void query(int ql, int qr, int x, int &cnt)
	{
		return Query(1, 0, n - 1, ql, qr, x, cnt);
	}
};

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	SegTree<int> segtree(n, 0);
	segtree.build(a, 1, 0, n - 1);

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int l, r, x, cnt = 0;
			cin >> l >> r >> x;
			--l, --r;
			segtree.query(l, r, x, cnt);

			if (cnt > 1) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
		else {
			int idx, val;
			cin >> idx >> val;
			--idx;
			segtree.update(idx, val);
			a[idx] = val;
		}
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