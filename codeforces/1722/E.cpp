#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1001][1001];
ll pref[1001][1001];

void solve()
{
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			a[i][j] = 0;
			pref[i][j] = 0;
		}
	}

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		a[x][y] += x * y;
	}

	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			pref[i][j] = a[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}

	for (int i = 0; i < q; i++) {
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;

		if (hs + 1 == hb || ws + 1 == wb) {
			cout << "0\n";
			continue;
		}

		int from_row = hs + 1, from_col = ws + 1, to_row = hb - 1, to_col = wb - 1;
		ll rectangles = pref[to_row][to_col] - pref[from_row - 1][to_col] - pref[to_row][from_col - 1] + pref[from_row - 1][from_col - 1];
		cout << rectangles << '\n';
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