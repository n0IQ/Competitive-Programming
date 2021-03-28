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

int dp[101][101];

bool check(int a[], int n, int sum)
{
	if (sum == 0) return 1;
	if (n == 0) return 0;

	if (dp[n][sum] != -1) return dp[n][sum];

	if (a[n - 1] <= sum) {
		return dp[n][sum] = check(a, n, sum - a[n - 1]) || check(a, n - 1, sum - a[n - 1]) || check(a, n - 1, sum);
	}
	else {
		return dp[n][sum] = check(a, n - 1, sum);
	}
}

void solve()
{
	int q, d;
	cin >> q >> d;

	int a[d + 1];
	for (int i = d, j = 0; i <= d * 10; i += 10, j++) {
		a[j] = i;
	}

	rep(i, 0, q) {
		mem1(dp);
		int x; cin >> x;

		if (x == d || x >= (10 * d)) cout << "YES" << '\n';
		else {
			if (check(a, d, x)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
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