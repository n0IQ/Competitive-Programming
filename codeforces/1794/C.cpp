#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}

	vector<int> ans(n, 0);
	ans[0] = 1;

	for (int i = 1; i < n; i++) {
		int l = 0, r = i, d = 1;

		while (l <= r) {
			int mid = l + (r - l) / 2;

			if (a[mid] >= i - mid + 1) {
				d = i - mid + 1;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		ans[i] = d;
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