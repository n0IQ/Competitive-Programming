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
int block_sz;

struct Query {
	int l, r, idx;
} qr[MAXN];

int arr[MAXN], freq[(int)1e6 + 10];
ll ans[MAXN];
ll curr_ans;

bool comp(Query &q1, Query &q2)
{
	int b1 = q1.l / block_sz;
	int b2 = q2.l / block_sz;
	if (b1 != b2) return b1 < b2;
	else return (b1 & 1) ? q1.r < q2.r: q1.r > q2.r;
}

void add(int x)
{
	ll cnt = freq[arr[x]];
	curr_ans -= ((cnt * cnt) * arr[x]);
	freq[arr[x]]++;
	cnt = freq[arr[x]];
	curr_ans += ((cnt * cnt) * arr[x]);
}

void remove(int x)
{
	ll cnt = freq[arr[x]];
	curr_ans -= ((cnt * cnt) * arr[x]);
	freq[arr[x]]--;
	cnt = freq[arr[x]];
	curr_ans += ((cnt * cnt) * arr[x]);
}

void solve()
{
	int n, q;
	cin >> n >> q;

	rep(i, 1, n + 1) cin >> arr[i];

	rep(i, 1, q + 1) {
		int l, r;
		cin >> l >> r;
		qr[i] = {l, r, i};
	}

	block_sz = sqrt(n) + 1;
	sort(qr + 1, qr + q + 1, comp);
	int l = 1, r = 0;
	curr_ans = 0;

	rep(i, 1, q + 1) {
		while (r < qr[i].r) add(++r);
		while (l > qr[i].l) add(--l);
		while (r > qr[i].r) remove(r--);
		while (l < qr[i].l) remove(l++);
		ans[qr[i].idx] = curr_ans;
	}

	rep(i, 1, q + 1) {
		cout << ans[i] << '\n';
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