#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 2e5 + 10;
vector<vector<ll>> adj, p;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	sort(all(a));
	adj = vector<vector<ll>> (MAXN);
	p = vector<vector<ll>> (MAXN);

	rep(i, 0, n) {
		int t = a[i], cnt = 0;

		while (t != 0) {
			adj[t].pb(cnt);
			t /= 2;
			cnt++;
		}

		adj[t].pb(cnt);
	}

	rep(i, 0, MAXN) {
		sort(all(adj[i]));
	}

	rep(i, 0, MAXN) {
		ll t = 0LL;

		for (auto x : adj[i]) {
			t += x;
			p[i].pb(t);
		}
	}

	ll ans = 1e12;

	rep(i, 0, MAXN) {
		if (sz(p[i]) < k) continue;
		ans = min(ans, p[i][k - 1]);
	}

	cout << ans << '\n';
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