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

const int MAXN = (int)1e5 + 10;
vector<int> adj[MAXN];
bool respect[MAXN], new_respect[MAXN];
set<int> ans;

bool dfs(int u, int p = -1)
{
	for (auto v : adj[u]) {
		if (v != p) {
			new_respect[u] &= dfs(v, u);
		}
	}

	return respect[u];
}

void solve()
{
	int n, root;
	cin >> n;

	mem0(respect), mem0(new_respect);
	rep(i, 0, n) {
		int p, c; cin >> p >> c;
		--p;
		if (p < 0) {
			root = i;
			continue;
		}
		respect[i] = c;
		new_respect[i] = c;
		adj[i].pb(p);
		adj[p].pb(i);
	}

	dfs(root);
	rep(i, 0, n) {
		if (new_respect[i]) ans.insert(i);
	}

	if (ans.empty()) cout << -1 << '\n';
	else for (auto x : ans) cout << x + 1 << ' ';
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