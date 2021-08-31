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

const int MaxN = 5e5 + 10;
const int INF = 1e9 + 10;
int n, m, k, cnt;

vector<pii> adj[MaxN];
int train[MaxN], dist[MaxN];
bool visited[MaxN], mark[MaxN];

void Dijkstra()
{
	set<pii> q;
	rep(i, 1, n) {
		dist[i] = train[i];
		if (dist[i] != INF) mark[i] = true;
		q.insert({dist[i], i});
	}

	dist[0] = 0;
	q.insert({dist[0], 0});

	while (!q.empty()) {
		int x = q.begin()->ss;
		q.erase(q.begin());

		if (mark[x]) cnt++;
		visited[x] = true;

		for (auto it : adj[x]) {
			int node = it.ff, wt = it.ss;

			if (!visited[node] && dist[x] + wt <= dist[node]) {
				q.erase({dist[node], node});
				dist[node] = dist[x] + wt;
				q.insert({dist[node], node});
				mark[node] = false;
			}
		}
	}
}

void solve()
{
	cin >> n >> m >> k;

	rep(i, 0, MaxN) train[i] = INF;

	rep(i, 0, m) {
		int u, v, wt;
		cin >> u >> v >> wt;
		--u, --v;
		adj[u].pb({v, wt});
		adj[v].pb({u, wt});
	}

	rep(i, 0, k) {
		int v, wt;
		cin >> v >> wt;
		--v;
		train[v] = min(train[v], wt);
	}

	Dijkstra();

	cout << k - cnt << '\n';
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