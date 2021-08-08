#include <bits/stdc++.h>
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

vector<vector<int>> adj;
vb visited;
vi path;

void dfs(int s)
{
	visited[s] = true;
	bool ok = false;
	path.pb(s);

	for (auto x : adj[s]) {
		if (!visited[x]) {
			ok = true;
			dfs(x);
			path.pb(s);
		}
	}
}

void solve()
{
	int n;
	cin >> n;

	adj.resize(n); visited.assign(n, false);
	vector<pii> edges;

	rep(i, 0, n - 1) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		edges.pb({--u, --v});
	}

	sort(all(edges));
	rep(i, 0, n - 1) {
		int u = edges[i].ff, v = edges[i].ss;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(0);

	for (auto x : path) cout << x + 1 << " ";
	cout << '\n';
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