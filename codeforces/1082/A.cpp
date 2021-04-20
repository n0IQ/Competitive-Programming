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
	ll n, x, y, d;
	cin >> n >> x >> y >> d;

	if (y >= x) {
		if ((y - x) % d == 0) {
			cout << (y - x) / d << '\n';
			return;
		}

		ll t1 = LLONG_MAX, t2 = LLONG_MAX;
		bool ok1 = false, ok2 = false;

		if ((y - 1) % d == 0) {
			ok1 = true;
			ll temp = x - 1;
			(temp % d == 0 ? temp = temp / d : temp = (temp / d) + 1);
			t1 = temp + ((y - 1) / d);
		}

		if ((n - y) % d == 0) {
			ok2 = true;
			ll temp = n - x;
			(temp % d == 0 ? temp = temp / d : temp = (temp / d) + 1);
			t2 = temp + ((n - y) / d);
		}

		if (ok1 || ok2) {
			cout << min(t1, t2) << '\n';
			return;
		}

		cout << -1 << '\n';
	}
	else {
		if ((x - y) % d == 0) {
			cout << (x - y) / d << '\n';
			return;
		}

		ll t1 = LLONG_MAX, t2 = LLONG_MAX;
		bool ok1 = false, ok2 = false;

		if ((y - 1) % d == 0) {
			ok1 = true;
			ll temp = x - 1;
			(temp % d == 0 ? temp = temp / d : temp = (temp / d) + 1);
			t1 = temp + ((y - 1) / d);
		}

		if ((n - y) % d == 0) {
			ok2 = true;
			ll temp = n - x;
			(temp % d == 0 ? temp = temp / d : temp = (temp / d) + 1);
			t2 = temp + ((n - y) / d);
		}

		if (ok1 || ok2) {
			cout << min(t1, t2) << '\n';
			return;
		}

		cout << -1 << '\n';
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