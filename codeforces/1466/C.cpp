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
	string s;
	cin >> s;

	int n = sz(s);

	if (sz(s) == 1) {
		cout << 0 << '\n';
		return;
	}

	int dp[n] = {0}, mark[n] = {0};
	dp[0] = 0;

	rep(i, 1, n) {
		if (i - 1 >= 0) {
			if (mark[i - 1] == 0) {
				if (s[i] == s[i - 1]) {
					dp[i] = 1;
					mark[i] = 1;
				}
			}
		}

		if (i - 2 >= 0) {
			if (mark[i - 2] == 0) {
				if (s[i] == s[i - 2]) {
					dp[i] = 1;
					mark[i] = 1;
				}
			}
		}
	}

	int ans = accumulate(dp, dp + n, 0);
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