#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<vector<int>> &a, int n, int m, int l)
{
	vector<vector<int>> pref(n + 10, vector<int>(m + 10, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = (a[i][j] >= l) + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n - l + 1; i++) {
		for (int j = 1; j <= m - l + 1; j++) {
			int from_row = i, from_col = j, to_row = i + l - 1, to_col = j + l - 1;
			int sum = pref[to_row][to_col] - pref[from_row - 1][to_col] - pref[to_row][from_col - 1] + pref[from_row - 1][from_col - 1];
			// cout << from_row << ' ' << from_col << ' ' << to_row << ' ' << to_col << ' ' << sum << '\n';
			if (sum >= l * l) return true;
		}
	}

	return false;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n + 1, vector<int> (m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int l = 1, r = min(n, m), ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(a, n, m, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
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
	cin >> t;
	while (t--) solve();

	return 0;
}