#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, t, r;
	cin >> n >> t >> r;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	if (t < r) {
		cout << "-1\n";
		return;
	}

	map<int, bool> lighted;
	for (int i = -500; i <= 500; i++) lighted[i] = false;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int litCandles = 0;

		for (int d = a[i] - t; d < a[i]; d++) {
			if (lighted[d]) litCandles++;
		}

		for (int d = a[i] - 1; d >= a[i] - t && litCandles < r; d--) {
			if (!lighted[d]) {
				lighted[d] = true;
				litCandles++;
				ans++;
			}
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
	// cin >> t;
	while (t--) solve();

	return 0;
}