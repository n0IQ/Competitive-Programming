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

	vll a(n);
	rep(i, 0, n) cin >> a[i];

	bool pos = 0, neg = 0;
	if (a[0] < 0) neg = 1;
	else pos = 1;

	int i = 0;
	vi res1, res2;

	while (i < n) {
		ll mx = INT_MIN, mn = INT_MIN;

		while (pos && i < n && a[i] > 0) {
			mx = max(mx, a[i]);
			i++;
		}

		if (pos && mx != INT_MIN) {
			res1.pb(mx);
			pos = 0, neg = 1;
		}

		while (neg && i < n && a[i] < 0) {
			mn = max(mn, a[i]);
			i++;
		}

		if (neg && mn != INT_MIN) {
			res2.pb(mn);
			neg = 0, pos = 1;
		}
	}

	ll sum = 0LL;

	rep(i, 0, sz(res1)) sum += res1[i];
	rep(i, 0, sz(res2)) sum += res2[i];

	cout << sum << '\n';
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