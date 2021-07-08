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

	vector<pii> a, b;
	rep(i, 0, 2 * n) {
		int x, y; cin >> x >> y;
		if (x == 0) {
			a.pb({x, abs(y)});
		}
		else {
			b.pb({abs(x), y});
		}
	}

	sort(all(a));
	sort(all(b));

	double ans = 0.0;
	rep(i, 0, n) {
		ll x1 = a[i].ff, y1 = a[i].ss, x2 = b[i].ff, y2 = b[i].ss;
		ll c = x1 - x2, d = y1 - y2;
		c *= c; d *= d;
		double t = sqrtl((c + d));
		ans += t;
	}

	cout << ps(ans, 15) << '\n';
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