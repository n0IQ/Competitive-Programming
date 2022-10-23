#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	int g = 0;
	for (int i = 1; i <= n; i++) {
		g = __gcd(g, a[i]);
	}

	if (g == 1) {
		cout << "0\n";
		return;
	}

	int ans = 100000000;

	for (int i = n; i >= 1; i--) {
		int cost = 0;

		vector<int> b(a);

		for (int j = i; j >= 1; j--) {
			cost += (n - j + 1);

			b[j] = __gcd(b[j], j);
			g = 0;

			for (int k = 1; k <= n; k++) {
				g = __gcd(g, b[k]);
			}

			if (g == 1) {
				ans = min(ans, cost);
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
	cin >> t;
	while (t--) solve();

	return 0;
}