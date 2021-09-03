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

void solve()
{
	int n;
	cin >> n;

	int a[n], f[n] = {0};
	rep(i, 0, n) {
		cin >> a[i];
		a[i]--;
	}

	int m;
	cin >> m;
	vector<pair<ll, pii>> app;
	rep(i, 0, m) {
		int u, v, c;
		cin >> u >> v >> c;
		app.pb({c, {--u, --v}});
	}

	sort(all(app));
	ll cost = 0;

	for (auto it : app) {
		int u = it.ss.ff, v = it.ss.ss, c = it.ff;
		if (f[v] == 0 && a[u] > a[v]) {
			cost += c;
			f[v] = 1;
		}
	}

	bool ok = false;
	rep(i, 0, n) {
		if (f[i] == 0) {
			if (!ok) ok = true;
			else {
				cout << -1 << '\n';
				return;
			}
		}
	}

	cout << cost << '\n';
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