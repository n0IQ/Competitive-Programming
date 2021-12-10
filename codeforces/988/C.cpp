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

void solve()
{
	int k;
	cin >> k;

	vector<ll> adj[k], p(k, 0LL);

	rep(i, 0, k) {
		int n;
		cin >> n;

		rep(j, 0, n) {
			ll x;
			cin >> x;
			adj[i].pb(x);
			p[i] += x;
		}
	}

	map<ll, set<int>> m;
	rep(i, 0, k) {
		for (auto x : adj[i]) {
			m[p[i] - x].insert(i);
		}
	}

	for (auto it : m) {
		if (sz(it.ss) >= 2) {
			cout << "YES\n";
			set<int> s = it.ss;
			int i, j, x, y;
			i = *s.begin();
			s.erase(s.begin());
			j = *s.begin();
			ll sum = it.ff;

			rep(l, 0, sz(adj[i])) {
				if (p[i] - adj[i][l] == sum) {
					x = l;
					break;
				}
			}

			rep(l, 0, sz(adj[j])) {
				if (p[j] - adj[j][l] == sum) {
					y = l;
					break;
				}
			}

			cout << i + 1 << ' ' << x + 1 << '\n';
			cout << j + 1 << ' ' << y + 1 << '\n';
			return;
		}
	}

	cout << "NO\n";
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