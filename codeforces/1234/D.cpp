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
		T temp;
		rep(i, 0, 26) {
			if (l.freq[i]) {
				temp.freq[i]++;
			}
		}
		rep(i, 0, 26) {
			if (r.freq[i]) {
				temp.freq[i]++;
			}
		}
		return temp;
	}

	template<typename U> void build(U &arr, int i, int l, int r)
	{
		if (l == r) {
			st[i].freq[arr[l] - 'a']++;
			return;
		}

		int mid = l + (r - l) / 2;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);

		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	}

	template<typename U> void Update(int i, int l, int r, int idx, U prev_val, U val)
	{
		if (l == r) {
			st[i].freq[prev_val - 'a']--;
			st[i].freq[val - 'a']++;
			return;
		}

		int mid = l + (r - l) / 2;
		if (idx <=  mid)
			Update(i << 1, l, mid, idx, prev_val, val);
		else
			Update(i << 1 | 1, mid + 1, r, idx, prev_val, val);

		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	}

	T Query(int i, int l, int r, int ql, int qr)
	{
		if (ql > r || qr < l)
			return e;
		if (l >= ql && r <= qr) {
			return st[i];
		}

		int mid = l + (r - l) / 2;
		T x = Query(i << 1, l, mid, ql, qr);
		T y = Query(i << 1 | 1, mid + 1, r, ql, qr);

		return merge(x, y);
	}

	template<typename U> void update(int idx, U prev_val, U val)
	{
		Update(1, 0, n - 1, idx, prev_val, val);
	}

	T query(int ql, int qr)
	{
		return Query(1, 0, n - 1, ql, qr);
	}
};

struct node {
	int freq[26] = {0};
};

void solve()
{
	string s;
	int q;
	cin >> s >> q;

	int n = sz(s);
	SegTree<node> segtree(n);
	segtree.build(s, 1, 0, n - 1);

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int idx;
			char val;
			cin >> idx >> val;
			--idx;
			segtree.update(idx, s[idx], val);
			s[idx] = val;
		}
		else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			node res = segtree.query(l, r);
			int ans = 0;
			rep(i, 0, 26) {
				if (res.freq[i] > 0) ans++;
			}
			cout << ans << '\n';
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