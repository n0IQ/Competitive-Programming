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

	int cnt0 = 0, pos = 0, neg = 0;

	vll a(n);
	rep(i, 0, n) {
		cin >> a[i];
		if (a[i] == 0) cnt0++;
		if (a[i] > 0) pos++;
		if (a[i] < 0) neg++;
	}

	if (pos == 0) {
		cout << n << '\n';
		return;
	}

	if (pos == n) {
		cout << 1 << '\n';
		return;
	}

	if (neg == 0 && cnt0 > 0) {
		cout << max(cnt0, 2) << '\n';
		return;
	}

	vll b;
	rep(i, 0, n) {
		if (a[i] <= 0) b.pb(a[i]);
	}

	sort(all(b));
	ll t = INT_MAX;
	rep(i, 1, sz(b)) {
		t = min(t, abs(b[i] - b[i - 1]));
	}

	ll ans = neg;
	if (cnt0 > 1) ans += cnt0;
	else {
		if (cnt0 > 0) ans++;
		rep(i, 0, n) {
			if (a[i] > 0 && a[i] <= t) {
				ans++;
				break;
			}
		}
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