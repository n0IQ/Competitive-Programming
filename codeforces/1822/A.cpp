#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, t;
	cin >> n >> t;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	int ans = 0, idx = -1;
	for (int i = 0; i < n; i++) {
		if (i + a[i] <= t) {
			if (b[i] > ans) {
				ans = b[i];
				idx = i;
			}
		}
	}

	if (idx == -1) cout << "-1\n";
	else cout << idx + 1 << '\n';
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