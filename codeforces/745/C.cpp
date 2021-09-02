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

const int MaxN = 1010;
int n, m, k;
vector<int> adj[MaxN];
vector<bool> visited(MaxN);
set<int> govs;

void dfs(int s, int &nodes, int &ok)
{
	visited[s] = true;
	nodes++;
	if (govs.count(s)) ok = 1;

	for (auto x : adj[s]) {
		if (!visited[x]) {
			dfs(x, nodes, ok);
		}
	}
}

void solve()
{
	cin >> n >> m >> k;
	rep(i, 0, k) {
		int x; cin >> x;
		govs.insert(--x);
	}

	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	vector<pii> edges;
	rep(i, 0, n) {
		if (!visited[i]) {
			int nodes = 0, ok = 0;
			dfs(i, nodes, ok);
			if (nodes == 1) visited[i] = false;
			else edges.pb({nodes, ok});
		}
	}

	sort(all(edges), greater<pii>());
	int cnt = 0;
	bool ok = false;
	rep(i, 0, sz(edges)) {
		if (!ok) {
			cnt += edges[i].ff;
			if (edges[i].ss == 1) ok = true;
			edges[i].ss = -1;
		}
		else {
			if (edges[i].ss == 0) {
				cnt += edges[i].ff;
				edges[i].ss = -1;
			}
		}
	}

	rep(i, 0, n) {
		if (!ok && govs.count(i) && !visited[i]) {
			cnt++;
			ok = true;
		}
		if (!govs.count(i) && !visited[i]) cnt++;
	}

	ll ans = (cnt * 1LL * (cnt - 1)) / 2;
	rep(i, 0, sz(edges)) {
		if (edges[i].ss != -1) {
			int nodes = edges[i].ff;
			ans += ((nodes * 1LL * (nodes - 1)) / 2);
		}
	}

	cout << ans - m << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}