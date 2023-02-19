#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100010];
ll dp[100010][50];
ll p[40];
ll n, k;

ll helper(int i, ll badKeysUsed)
{
	if (i > n) {
		return 0;
	}
	if (badKeysUsed >= 30) {
		return 0;
	}
	if (dp[i][badKeysUsed] != -1) {
		return dp[i][badKeysUsed];
	}

	ll ans = ((a[i] / p[badKeysUsed - 1]) - k) + helper(i + 1, badKeysUsed);
	ans = max(ans, (a[i] / p[badKeysUsed]) + helper(i + 1, badKeysUsed + 1));

	return dp[i][badKeysUsed] = ans;
}

void solve()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// dp[i][j] = max coins gained till ith box such that j bad keys has been used.

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 50; j++) {
			dp[i][j] = -1;
		}
	}

	cout << helper(1, 1) << '\n';
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

	p[0] = 1LL;
	for (int i = 1; i < 40; i++) {
		p[i] = p[i - 1] * 2LL;
	}

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}