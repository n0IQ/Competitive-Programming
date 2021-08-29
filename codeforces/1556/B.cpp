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

	vector<ll> a(n);
	int even = 0, odd = 0;
	rep(i, 0, n) {
		cin >> a[i];
		if (a[i] % 2 == 0) even++;
		else odd++;
	}

	if (n == 1) {
		cout << 0 << '\n';
		return;
	}

	if (n % 2 == 0 && even != odd) {
		cout << -1 << '\n';
		return;
	}

	if ((n % 2 == 1) && ((even != (n / 2)) && (odd != (n / 2)))) {
		cout << -1 << '\n';
		return;
	}

	ll res1 = 0LL, res2 = 0LL;
	vector<ll> e, o;

	if (n % 2 == 1 && odd > even) res1 = 1e12;
	else {
		rep(i, 0, n) {
			if (i % 2 == 0) {
				if (a[i] % 2 == 1) o.pb(i);
			}
			else {
				if (a[i] % 2 == 0) e.pb(i);
			}
		}

		if (e.empty() && o.empty()) res1 = 0;
		else if (e.empty() || o.empty()) res1 = 1e12;
		else {
			sort(all(e)), sort(all(o));
			rep(i, 0, sz(e)) {
				res1 += (abs(e[i] - o[i]));
			}
		}
	}

	e.clear(), o.clear();

	if (n % 2 == 1 && even > odd) res2 = 1e12;
	else {
		rep(i, 0, n) {
			if (i % 2 == 0) {
				if (a[i] % 2 == 0) e.pb(i);
			}
			else {
				if (a[i] % 2 == 1) o.pb(i);
			}
		}

		if (e.empty() && o.empty()) res1 = 0;
		else if (e.empty() || o.empty()) res2 = 1e12;
		else {
			sort(all(e)), sort(all(o));
			rep(i, 0, sz(e)) {
				res2 += (abs(e[i] - o[i]));
			}
		}
	}

	cout << min(res1, res2) << '\n';
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