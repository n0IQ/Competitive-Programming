#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<int> &a, vector<int> &chose, int n, int q, int idx)
{
	fill(chose.begin(), chose.end(), 0);

	for (int i = 0; i < n; i++) {
		if (i < idx) {
			if (a[i] <= q) chose[i] = 1;
		}
		else {
			chose[i] = 1;
			if (a[i] > q) q--;
		}
	}

	return q >= 0;
}

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int l = 0, r = n - 1, idx = n;
	vector<int> chose(n, 0);

	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (check(a, chose, n, q, mid)) {
			idx = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	check(a, chose, n, q, idx);

	for (auto &x : chose) {
		cout << x;
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