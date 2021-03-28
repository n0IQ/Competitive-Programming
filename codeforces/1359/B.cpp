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

int n, m, x, y;
char mat[101][1001];
int dp[101][1001];

ll calc (int i, int j)
{
	if (i == n || j == m) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	if (j < m - 1 && mat[i][j] == '.' && mat[i][j + 1] == '.') {
		return dp[i][j] = min(y + calc(i, j + 2), x + calc(i, j + 1));
	}
	else if (mat[i][j] == '.') {
		return dp[i][j] = x + calc(i, j + 1);
	}
	else {
		calc(i, j + 1);
	}
}

void solve()
{
	cin >> n >> m >> x >> y;
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> mat[i][j];
		}
	}

	ll ans = 0;
	mem1(dp);

	rep(i, 0, n) {
		ans += calc(i, 0);
	}

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