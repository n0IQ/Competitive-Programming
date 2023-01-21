#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a, b;
ll dp[101][10010];

ll helper(int i, int n, int x)
{
	if (x == 0) {
		return 1;
	}
	if (i >= n || x < 0) {
		return 0;
	}
	if (dp[i][x] != -1) {
		return dp[i][x];
	}

	bool isPossible = false;
	for (int j = 0; j <= b[i]; j++) {
		isPossible |= helper(i + 1, n, x - (j * a[i]));
	}

	return dp[i][x] = isPossible;
}

void solve()
{
	int n, x;
	cin >> n >> x;

	a.resize(n), b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	memset(dp, -1, sizeof(dp));
	if (helper(0, n, x)) cout << "Yes\n";
	else cout << "No\n";
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