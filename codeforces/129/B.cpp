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

vvi adj;
vb visited;

void solve()
{
	int n, m;
	cin >> n >> m;

	adj.resize(n + 1);
	visited.assign(n + 1, false);

	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int count = 0, u = 0, v = 0;
	bool ok = false;
	queue<pii> q;

	while (1) {
		ok = false;

		rep(i, 1, n + 1) {
			if (sz(adj[i]) == 1 && !visited[i]) {
				ok = true;
				v = adj[i][0];
				visited[i] = true;
				q.push({i, v});
			}
		}

		if (!ok) break;

		while (!q.empty()) {
			u = q.front().ff, v = q.front().ss;
			q.pop();

			auto it = find(adj[v].begin(), adj[v].end(), u);
			adj[v].erase(it);
		}

		count++;
	}

	cout << count << '\n';
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