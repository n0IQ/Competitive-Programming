#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

int a[1001][1001];

// dp[i][j] = no of ways to reach this cell

int helper(int n, int m)
{
	int dp[n][m];
	rep(i, 0, n) {
		rep(j, 0, m) dp[i][j] = 0;
	}

	dp[0][0] = 1;

	rep(i, 0, n) {
		rep(j, 0, m) {
			if (j - 1 >= 0 && !a[i][j]) {
				dp[i][j] += dp[i][j - 1];
				dp[i][j] %= MOD1;
			}
			if (i - 1 >= 0 && !a[i][j]) {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] %= MOD1;
			}
		}
	}

	return dp[n - 1][m - 1] % MOD1;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	rep(i, 0, n) {
		rep(j, 0, m) {
			char ch;
			cin >> ch;
			if (ch == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}

	cout << helper(n, m) << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}