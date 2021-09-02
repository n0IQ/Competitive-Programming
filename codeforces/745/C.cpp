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
int govs[MaxN];
bool visited[MaxN];

void dfs(int s, int &nodes)
{
	visited[s] = true;
	nodes++;

	for (auto x : adj[s]) {
		if (!visited[x]) {
			dfs(x, nodes);
		}
	}
}

void solve()
{
	cin >> n >> m >> k;
	rep(i, 0, k) {
		int x; cin >> x;
		govs[i] = --x;
	}

	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll ans = 0, mx = 0;
	rep(i, 0, k) {
		int nodes = 0;
		dfs(govs[i], nodes);
		if (nodes > mx) mx = nodes;
		ans = ans + (nodes * 1LL * (nodes - 1)) / 2;
	}

	rep(i, 0, n) {
		if (!visited[i]) {
			ans += mx;
			mx++;
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