#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[101][100001];
ll value[101], weight[101];

ll helper(int i, int n, ll val)
{
	if (val == 0) {
		return 0;
	}
	if (val < 0 || i >= n) {
		return 1e15;
	}
	if (dp[i][val] != -1) {
		return dp[i][val];
	}

	return dp[i][val] = min(weight[i] + helper(i + 1, n, val - value[i]), helper(i + 1, n, val));
}

void solve()
{
	ll n, W;
	cin >> n >> W;

	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}

	// dp[i][j] = max profit gained till (1...i) items of having value of j s.t. total weight is less than capacity
	memset(dp, -1, sizeof(dp));

	ll ans = 0;
	for (int i = 1; i <= 100000; i++) {
		ll wt = helper(0, n, i);

		if (wt <= W) {
			ans = i;
		}
	}

	cout << ans << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}