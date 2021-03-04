#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int frog(int ht[], int n, int k)
{
	vi dp(n + 1, INT_MAX);

	dp[0] = dp[1] = 0;
	dp[2] = abs(ht[2] - ht[1]);

	repA(i, 3, n) {
		repA(j, 1, k) {
			if (i - j == 0) {
				break;
			}

			dp[i] = min(dp[i], dp[i - j] + abs(ht[i] - ht[i - j]));
		}
	}

	return dp[n];
}

void solve()
{
	int n, k;
	cin >> n >> k;

	int ht[n + 1];
	repA(i, 1, n) {
		cin >> ht[i];
	}

	cout << frog(ht, n, k) << '\n';
}

int main()
{
	fastio;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}