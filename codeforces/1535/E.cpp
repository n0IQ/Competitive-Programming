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

const int MAXN = (int)5e5 + 10;
const int LOG = 19;
int up[MAXN][LOG];
int gold[MAXN], price[MAXN];

void process(int v, int p)
{
	up[v][0] = p;
	for (int j = 1; j < LOG; j++) {
		if (up[v][j - 1] != -1) {
			up[v][j] = up[up[v][j - 1]][j - 1];
		}
	}
}

int first_non_zero(int v)
{
	for (int j = LOG - 1; j >= 0; j--) {
		if (up[v][j] != -1 && gold[up[v][j]] > 0) {
			v = up[v][j];
		}
	}

	return v;
}

void solve()
{
	int q, a0, c0;
	cin >> q >> a0 >> c0;

	gold[0] = a0;
	price[0] = c0;

	mem1(up);

	rep(i, 1, q + 1) {
		int t;
		cin >> t;

		if (t == 1) {
			int p, a, c;
			cin >> p >> a >> c;
			process(i, p);
			gold[i] = a;
			price[i] = c;
		}
		else {
			int v, w;
			cin >> v >> w;

			int gold_taken = 0;
			ll cost = 0;

			while (w > 0) {
				int x = first_non_zero(v);
				if (gold[x] == 0) break;

				int temp = min(w, gold[x]);
				gold_taken += temp;
				gold[x] -= temp;
				w -= temp;
				cost += (temp * 1LL * price[x]);
			}

			cout << gold_taken << ' ' << cost << endl;
		}
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}