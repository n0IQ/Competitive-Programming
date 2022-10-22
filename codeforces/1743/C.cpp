#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2000000000000000

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	s = "-" + s + "-";
	// dp[i][0] = max magazines saved till ith box when ith box is not covered
	// dp[i][1] = max magazines saved till ith box when ith box is covered
	// dp[i][2] = max magazines saved till ith box when ith box is covered from right
	ll dp[n + 1][3];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});

		if (s[i] == '1') {
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
		}
		if (s[i + 1] == '1') {
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + a[i];
		}
	}

	cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
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