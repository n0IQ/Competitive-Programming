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

	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	int mx = *max_element(all(a));
	bool ok = true;
	set<int> s;
	set<pii> ans;

	rep(i, 0, n) {
		if (sz(s) == mx) break;
		if (s.count(a[i])) {
			ok = false;
			break;
		}

		s.insert(a[i]);
	}

	if (ok) {
		s.clear();
		int x = mx;
		mx = 0;
		rep(i, x, n) mx = max(mx, a[i]);
		rep(i, x, n) {
			if (s.count(a[i])) {
				ok = false;
				break;
			}

			s.insert(a[i]);
		}

		if (sz(s) != mx) ok = false;
		mx = x;
		if (ok) ans.insert({mx, n - mx});
	}

	s.clear();
	ok = true;

	repR(i, n - 1, 0) {
		if (sz(s) == mx) break;
		if (s.count(a[i])) {
			ok = false;
			break;
		}

		s.insert(a[i]);
	}

	if (ok) {
		s.clear();
		int x = mx;
		mx = 0;
		rep(i, 0, n - x) mx = max(mx, a[i]);
		rep(i, 0, n - x) {
			if (s.count(a[i])) {
				ok = false;
				break;
			}

			s.insert(a[i]);
		}

		if (sz(s) != mx) ok = false;
		if (ok) ans.insert({mx, n - mx});
	}

	cout << sz(ans) << '\n';
	for (auto [x, y] : ans) cout << x << " " << y << '\n';
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