#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
//template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
vector<vector<ll>> adj;
vector<pll> min_power;

bool sort_power(ll x, ll idx)
{
	rep(i, 0, sz(adj[idx])) {
		if (adj[idx][i] >= x) return false;
		x++;
	}

	return true;
}

bool getScore(ll x)
{
	rep(i, 0, n) {
		if (min_power[i].ff <= x) {
			x += min_power[i].ss;
		}
		else return false;
	}

	return true;
}

void solve()
{
	cin >> n;
	adj.clear(), min_power.clear();

	adj.resize(n);

	rep(i, 0, n) {
		ll k; cin >> k;
		rep(j, 0, k) {
			ll x; cin >> x;
			adj[i].pb(x);
		}
	}

	min_power.resize(n);

	rep(i, 0, n) {
		ll l = 0, r = 1e9 + 1;

		while (r - l > 1) {
			ll m = (l + r) / 2;
			if (sort_power(m, i)) r = m;
			else l = m;
		}

		min_power[i] = mp(r, sz(adj[i]));
	}

	sort(all(min_power));
	ll l = 0, r = 1e9 + 1;

	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (getScore(m)) r = m;
		else l = m;
	}

	cout << r << '\n';
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