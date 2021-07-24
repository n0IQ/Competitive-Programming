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
vector<ll> dist, cnt;

void BFS(int s)
{
	queue<int> q;
	dist[s] = 0;
	cnt[s] = 1;
	q.push(s);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto it : adj[x]) {
			if (dist[it] == -1) {
				q.push(it);
				dist[it] = dist[x] + 1;
				cnt[it] = cnt[x];
			}
			else if (dist[it] == dist[x] + 1) {
				cnt[it] += cnt[x];
				cnt[it] %= mod;
			}
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	adj.resize(n);
	dist.assign(n, -1); cnt.assign(n, 0);

	rep(i, 0, m) {
		int u, v; cin >> u >> v;
		adj[--u].pb(--v);
		adj[v].pb(u);
	}

	BFS(0);
	cout << cnt[n - 1] << '\n';
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