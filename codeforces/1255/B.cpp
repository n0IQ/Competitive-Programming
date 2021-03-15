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
	int n, m;
	cin >> n >> m;

	int a[n + 1], wires = 0;
	multimap<int, int> mp;
	multimap<int, int>::iterator it1;
	multimap<int, int>::iterator it2;
	vpii adj;
	ll cost = 0;

	rep(i, 1, n + 1) {
		cin >> a[i];
		mp.insert({a[i], i});
	}

	if (m < n || n <= 2) {
		cout << -1 << '\n';
		return;
	}

	rep(i, 1, n) {
		adj.pb({i, i + 1});
		cost += a[i] + a[i + 1];
		wires++;
	}

	adj.pb({n, 1});
	cost += a[n] + a[1];
	wires++;

	it1 = mp.begin();
	it2 = it1; it2++;
	int u = it1->ss, v = it2->ss;

	while (wires != m) {
		adj.pb({u, v});
		cost += a[u] + a[v];
	}

	cout << cost << '\n';

	for (auto p : adj) {
		cout << p.ff << " " << p.ss << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}