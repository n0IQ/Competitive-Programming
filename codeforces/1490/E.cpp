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
	map<ll, ll> cnt, res;
	ll mx = -1;

	rep(i, 0, n) {
		cin >> a[i];
		cnt[a[i]]++;
		mx = max(mx, a[i]);
	}

	rep(i, 0, n) {
		if (res.count(a[i])) continue;
		else {
			ll t = a[i], sum = 0;
			bool ok = 0;

			for (auto it : cnt) {
				if (sum >= mx) {
					ok = 1;
					break;
				}
				if (t >= it.ff) {
					sum += it.ss * it.ff;
					t = max(t, sum);
				}
				else {
					ok = 0;
					break;
				}
			}

			if (ok || sum >= mx) res[a[i]] = 1;
			else res[a[i]] = 0;
		}
	}

	vi ans;
	rep(i, 0, n) {
		if (res[a[i]] == 1) ans.pb(i + 1);
	}

	cout << sz(ans) << '\n';
	rep(i, 0, sz(ans)) cout << ans[i] << " ";
	cout << '\n';
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