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

	int a[n][m];
	rep(i, 0, n) {
		rep(j, 0, m) {
			char c; cin >> c;
			if (c == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}

	bool ok = false;
	int mn = INT_MAX;
	int cols[m] = {0};

	rep(j, 0, m) {
		int t = 0;
		rep(i, 0, n) {
			if (a[i][j] == 1) t++;
		}

		mn = min(mn, n - t);
		cols[j] = n - t;
	}

	int ans = mn;
	mn = INT_MAX;

	rep(i, 0, n) {
		int t = 0;
		bool ok = false;
		rep(j, 0, m) {
			if (a[i][j] == 1) t++;
			if (cols[j] == ans && a[i][j] == 0) ok = true;
		}

		if (ok) t++;
		mn = min(mn, max(0, m - t));
	}

	cout << ans + mn << '\n';
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