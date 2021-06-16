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
	int n, k;
	cin >> n >> k;

	vll a(n), b(k);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, k) cin >> b[i];

	sort(all(a)), sort(all(b), greater<ll>());
	vector<vector<ll>> v(k);
	int l = 0;

	rep(i, 0, k) {
		rep(j, 0, b[i] - 1) {
			v[i].pb(a[l++]);
		}
	}

	int j = 0;
	rep(i, l, n) {
		v[j++].pb(a[l++]);
	}

	ll ans = 0;
	rep(i, 0, k) {
		ll mn = LLONG_MAX , mx = LLONG_MIN;

		for (auto it : v[i]) {
			mx = max(mx, it);
			mn = min(mn, it);
		}

		ans += (mx + mn);
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
	cin >> t;
	while (t--) solve();

	return 0;
}