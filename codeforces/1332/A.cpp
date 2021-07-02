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
	ll a, b, c, d, x, y, x1, y1, x2, y2;
	cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;

	if ((x == x1 && x == x2) && (a != 0 && b != 0)) {
		cout << "No" << '\n';
		return;
	}

	if ((y == y1 && y == y2) && (c != 0 && d != 0)) {
		cout << "No" << '\n';
		return;
	}

	if (a >= b) {
		a -= b; b = 0;

		if (x - a < x1) {
			cout << "No" << '\n';
			return;
		}
	}
	else {
		b -= a; a = 0;

		if (x + b > x2) {
			cout << "No" << '\n';
			return;
		}
	}

	if (c >= d) {
		c -= d; d = 0;

		if (y - c < y1) {
			cout << "No" << '\n';
			return;
		}
	}
	else {
		d -= c; c = 0;

		if (y + d > y2) {
			cout << "No" << '\n';
			return;
		}
	}

	cout << "Yes" << '\n';
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