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
	int n, m;
	cin >> n >> m;

	// n = zero, m = one
	if (n >= m ) {
		if (n - m > 1) {
			cout << -1 << '\n';
			return;
		}

		string s;
		rep(i, 0, m) s += "01";
		if (n > m) s.pb('0');
		cout << s << '\n';
	}

	if (m > n) {
		if ((2 * n) - m < -2) {
			cout << -1 << '\n';
			return;
		}

		string s;

		while (m > n && n > 0) {
			m -= 2; n--;
			s += "110";
		}

		while (m > 0 && n > 0) {
			s += "10";
			m--, n--;
		}

		while (m > 0) {
			s.pb('1');
			m--;
		}

		while (n > 0) {
			s.pb('0');
			n--;
		}

		cout << s << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}