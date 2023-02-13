#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[6001];
int dp[6010][6010];

ll helper(int l, int r)
{
	if (l <= 1 && r >= n) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	ll ans = INT_MAX;
	if (l - 1 >= 1 && a[l - 1] == a[l]) {
		ans = min(ans, helper(l - 1, r));
	}
	else if (l - 1 >= 1) {
		ans = min(ans, 1 + helper(l - 1, r));
	}

	if (r + 1 <= n && a[r + 1] == a[r]) {
		ans = min(ans, helper(l, r + 1));
	}
	else if (r + 1 <= n) {
		ans = min(ans, 1 + helper(l, r + 1));
	}

	if (l - 1 >= 1 && r + 1 <= n && a[l - 1] == a[r + 1]) {
		ans = min(ans, 1 + helper(l - 1, r + 1));
	}

	return dp[l][r] = ans;
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// dp[l][r] = minimum number of turns to change the line from l to r to a single color.
	memset(dp, -1, sizeof(dp));

	ll ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, helper(i, i));
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
	// cin >> t;
	while (t--) solve();

	return 0;
}