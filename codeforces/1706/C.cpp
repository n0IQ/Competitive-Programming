#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	// dp[i][0] = maximum cool buildings till ith index such that ith building is not cool
	// dp[i][1] = maximum cool buildings till ith index such that ith building is cool
	ll dp[n][2], cost[n][2];
	memset(dp, 0, sizeof(dp));
	memset(cost, 0, sizeof(cost));

	dp[0][0] = dp[0][1] = 0;
	cost[0][0] = cost[0][1] = 0;

	for (int i = 1; i < n; i++) {
		// ith building is not cool
		if (dp[i - 1][0] > dp[i - 1][1]) {
			dp[i][0] = dp[i - 1][0];
			cost[i][0] = cost[i - 1][0];
		}
		else if (dp[i - 1][0] < dp[i - 1][1]) {
			dp[i][0] = dp[i - 1][1];
			cost[i][0] = cost[i - 1][1];
		}
		else {
			dp[i][0] = dp[i - 1][0];
			cost[i][0] = min(cost[i - 1][0], cost[i - 1][1]);
		}

		// ith building is cool
		if (i < n - 1) {
			dp[i][1] = dp[i - 1][0] + 1;
			cost[i][1] = cost[i - 1][0] + max(0LL, max(a[i - 1], a[i + 1]) - a[i] + 1);
		}
		else {
			dp[i][1] = dp[i - 1][0];
			cost[i][1] = cost[i - 1][0];
		}
	}

	if (dp[n - 1][0] > dp[n - 1][1]) {
		cout << cost[n - 1][0] << '\n';
	}
	else if (dp[n - 1][0] < dp[n - 1][1]) {
		cout << cost[n - 1][1] << '\n';
	}
	else {
		cout << min(cost[n - 1][0], cost[n - 1][1]) << '\n';
	}
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
	cin >> t;
	while (t--) solve();

	return 0;
}