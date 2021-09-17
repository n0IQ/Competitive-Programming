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
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MaxN = 1e5 + 10;
int n, m, bridges;
vector<int> adj[MaxN];
set<pii> res;
int lv[MaxN], dp[MaxN];
bool visited[MaxN];

void dfs2(int u, int p)
{
	visited[u] = 1;

	for (auto v : adj[u]) {
		if (!visited[v]) {
			res.insert({u, v});
			dfs2(v, u);
		}
		else if (v != p) {
			if (!res.count({u, v}) && !res.count({v, u})) {
				res.insert({u, v});
			}
		}
	}
}

void dfs(int u, int p)
{
	dp[u] = 0;

	for (auto v : adj[u]) {
		if (lv[v] == 0) {
			lv[v] = lv[u] + 1;
			dfs(v, u);
			dp[u] += dp[v];
		}
		else if (lv[v] < lv[u]) {
			dp[u]++;
		}
		else if (lv[v] > lv[u]) {
			dp[u]--;
		}
	}

	dp[u]--;

	if (lv[u] > 1 && dp[u] == 0) {
		bridges++;
	}
}

bool hasBridge()
{
	lv[0] = 1;
	dfs(0, -1);
	if (bridges > 0) return true;
	return false;
}

void solve()
{
	cin >> n >> m;
	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (hasBridge()) {
		cout << 0 << '\n';
		return;
	}

	dfs2(0, -1);
	for (auto it : res) {
		cout << it.ff + 1 << ' ' << it.ss + 1 << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}