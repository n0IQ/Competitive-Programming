#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, z;
vector<ll> a;
ll dp[100010][10][2];

ll helper(int i, int totalMoves, int backMoves, bool wasBackMove)
{
	if (i > n || totalMoves == k) {
		return 0;
	}
	if (dp[i][backMoves][wasBackMove] != -1) {
		return dp[i][backMoves][wasBackMove];
	}

	ll ans = 0;

	if (i == 0 || wasBackMove) { // prevMove was a backmove
		ans = a[i + 1] + helper(i + 1, totalMoves + 1, backMoves, 0);
	}
	else {
		if (backMoves < z) {
			ans = max(a[i - 1] + helper(i - 1, totalMoves + 1, backMoves + 1, 1), a[i + 1] + helper(i + 1, totalMoves + 1, backMoves, 0));
		}
		else {
			ans = a[i + 1] + helper(i + 1, totalMoves + 1, backMoves, 0);
		}
	}

	return dp[i][backMoves][wasBackMove] = ans;
}

void solve()
{
	cin >> n >> k >> z;

	a.clear();
	a.resize(n + 10, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// dp[i][j][k] = maximum score obtained standing at ith position and j back moves have been used
	//               such that last move was in front or back.

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	cout << a[1] + helper(1, 0, 0, 0) << '\n';
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