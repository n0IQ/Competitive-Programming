#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

void solve()
{
	int n;
	cin >> n;

	// dp[i][j] = number of zebroid subsequence that can be formed till ith index such that
	//            current marble is red / blue (0 / 1)

	ll dp[n][2];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] % MOD;
		dp[i][1] = dp[i - 1][1] % MOD;

		dp[i][i % 2] += (1 + dp[i - 1][(i % 2) ^ 1]) % MOD;
	}

	cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << '\n';
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("Error.txt", "w", stderr);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}