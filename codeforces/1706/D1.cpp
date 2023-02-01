#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = INT_MAX;
	for (int mi = 0; mi <= 3000; mi++) {
		int mx = 0;
		bool flag = false;

		for (int i = 0; i < n; i++) {
			int p = mi == 0 ? k : min(k, a[i] / mi);
			if (p == 0) {
				flag = true;
				break;
			}

			mx = max(mx, a[i] / p);
		}

		if (flag) continue;
		ans = min(ans, mx - mi);
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