#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

vector<vector<int>> adj;
vi ans;
vb visited;

void BFS(int s)
{
	vi a;
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (visited[v]) continue;
		visited[v] = true;
		a.pb(v);

		for (auto u : adj[v]) {
			if (!visited[u]) {
				q.push(u);
			}
		}
	}

	for (auto x : a) {
		ans[x] = sz(a);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	adj.resize(n + 1);
	visited.assign(n + 1, false);
	ans.assign(n + 1, 0);

	rep(i, m) {
		int k; cin >> k;

		vi v(k);
		rep(j, k) {
			cin >> v[j];
		}

		rep(j, k - 1) {
			adj[v[j]].pb(v[j + 1]);
			adj[v[j + 1]].pb(v[j]);
		}
	}

	repA(i, 1, n) {
		if (!visited[i]) {
			BFS(i);
		}
	}

	repA(i, 1, n) {
		cout << ans[i] << " ";
	}

	cout << '\n';
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