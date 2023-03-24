#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	if (k == 0) {
		for (int i = 0; i < n; i++) {
			cout << "-1 ";
		}
		cout << '\n';
		return;
	}

	vector<int> a(50, INT_MAX);
	for (int i = 1; i <= n; i++) {
		a[i - 1] = (i * (i + 1)) / 2;
	}

	auto it = upper_bound(a.begin(), a.end(), k);
	int idx = (int)((--it) - a.begin());

	vector<int> ans(n, -1000);
	fill(ans.begin(), ans.begin() + idx + 1, 2);

	int x = k - *it;
	if (x > 0) {
		int val = 2 * ((idx + 1) - (x - 1)) - 1;
		ans[idx + 1] = -val;
	}

	for (auto &x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
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