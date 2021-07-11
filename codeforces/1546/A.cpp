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

	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	ll sum1 = accumulate(all(a), 0LL);
	ll sum2 = accumulate(all(b), 0LL);

	if (sum1 != sum2) {
		cout << -1 << '\n';
		return;
	}

	vpii v1, v2, res;

	rep(i, 0, n) {
		if (a[i] < b[i]) {
			v1.pb({i, b[i] - a[i]});
		}
		else if (a[i] > b[i]) {
			v2.pb({i, a[i] - b[i]});
		}
	}

	int i = 0, j = 0;
	while (i < sz(v1) && j < sz(v2))
	{
		int mn = min(v1[i].ss, v2[j].ss);
		rep(k, 0, mn) {
			res.push_back({v2[j].ff, v1[i].ff});
		}

		v1[i].ss -= mn, v2[j].ss -= mn;

		if (v1[i].ss == 0) i++;
		if (v2[j].ss == 0) j++;
	}

	if (i != sz(v1) || j != sz(v2)) {
		cout << -1 << '\n';
		return;
	}

	cout << sz(res) << '\n';
	for (auto &[a, b] : res) {
		cout << a + 1 << " " << b + 1 << '\n';
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