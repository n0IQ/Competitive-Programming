#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
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
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
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

const int MAXN = (int)1e4 + 10;
int p[MAXN], r[MAXN];

void init()
{
	rep(i, 0, MAXN) {
		p[i] = i;
		r[i] = 1;
	}
}

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
		if (r[a] < r[b])
			swap(a, b);
		p[b] = a;
		r[a] += r[b];
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 1, n + 1) {
		int v; cin >> v;
		int u = find_set(i);
		v = find_set(v);
		if (u != v) {
			union_set(u, v);
		}
	}

	set<int> s;
	rep(i, 1, n + 1) {
		s.insert(find_set(i));
	}

	cout << sz(s) << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	init();
	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}