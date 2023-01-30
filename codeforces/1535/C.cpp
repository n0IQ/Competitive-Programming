#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size();
	s = "0" + s;

	// dp[i][j] = max number of beautiful strings till ith index such that ith character is j (0 / 1)
	ll dp[n + 1][2];
	memset(dp, 0, sizeof(dp));
	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else if (s[i] == '0') {
			dp[i][0] = dp[i - 1][1] + 1;
		}
		else {
			dp[i][0] = dp[i - 1][1] + 1;
			dp[i][1] = dp[i - 1][0] + 1;
		}

		ans += max(dp[i][0], dp[i][1]);
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
	cin >> t;
	while (t--) solve();

	return 0;
}