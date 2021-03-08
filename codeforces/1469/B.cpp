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

	int a[n];
	rep(i, 0, n) cin >> a[i];

	int m;
	cin >> m;

	int b[m];
	rep(i, 0, m) cin >> b[i];

	int dp[n + 1][m + 1];
	rep(i, 0, n + 1) {
		rep(j, 0, m + 1) {
			dp[i][j] = INT_MIN;
		}
	}

	dp[0][0] = 0;
	int ans = 0;

	rep(i, 0, n + 1) {
		rep(j, 0, m + 1) {
			if (i < n) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i]);
			}

			if (j < m) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j]);
			}

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}