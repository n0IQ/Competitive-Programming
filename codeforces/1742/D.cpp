#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n + 1);
	int idx[1010] = {0};

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		idx[a[i]] = i;
	}

	int ans = -1;

	for (int i = 1; i <= 1000; i++) {
		if (idx[i] > 0) {

			for (int j = 1; j <= 1000; j++) {
				if (idx[j] > 0) {
					int g = __gcd(i, j);

					if (g == 1) {
						ans = max(ans, idx[i] + idx[j]);
					}
				}
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