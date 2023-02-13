#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[6001][6001];

int lcs(int n, vector<int> &a, vector<int> &b)
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[n][n];
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x != a.back()) a.push_back(x);
	}

	vector<int> b(a);
	reverse(b.begin() + 1, b.end());

	n = (int)a.size() - 1;
	cout << n - (lcs(n, a, b) + 1) / 2 << '\n';
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