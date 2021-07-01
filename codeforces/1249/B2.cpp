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
vi res;
vb vis;
ll days;

void dfs(int s, int d)
{
	vis[s] = 1;

	for (auto it : adj[s]) {
		if (it != d) {
			days++;
			dfs(it, d);
			res[s] = days;
		}
		else res[s] = days;
	}
}

void solve()
{
	int n;
	cin >> n;

	adj.clear(); adj.resize(n);
	vis.clear(); vis.resize(n);
	res.clear(); res.resize(n);

	rep(u, 0, n) {
		int v; cin >> v;
		--v;

		if (u != v) {
			adj[u].pb(v);
		}
	}

	rep(i, 0, n) {
		days = 1;

		if (!vis[i]) {
			dfs(i, i);
		}
	}

	for (auto it : res) {
		if (it == 0) it = 1;
		cout << it << " ";
	}

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
	cin >> t;
	while (t--) solve();

	return 0;
}