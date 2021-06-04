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
	int p, q, l, r;
	cin >> p >> q >> l >> r;

	vpii v1, v2;
	rep(i, 0, p) {
		int x, y; cin >> x >> y;
		v1.pb({x, y});
	}

	rep(i, 0, q) {
		int x, y; cin >> x >> y;
		v2.pb({x, y});
	}

	int ans = 0;
	while (l <= r) {
		bool ok = false;

		rep(i, 0, sz(v2)) {
			int x = v2[i].ff + l, y = v2[i].ss + l;

			for (auto it : v1) {
				if (!(x > it.ss || y < it.ff)) ok = true;
			}
		}

		if (ok) ans++;

		l++;
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