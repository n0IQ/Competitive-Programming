#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(n), c(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < m; i++) cin >> c[i];

	vector<int> left;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			left.push_back(i);
		}
	}

	int lastPlank = -1;
	for (auto &i : left) {
		if (b[i] == c.back()) lastPlank = i;
	}

	for (int i = 0; i < n && lastPlank == -1; i++) {
		if (b[i] == c.back()) lastPlank = i;
	}

	if (lastPlank == -1) {
		cout << "NO\n";
		return;
	}

	vector<int> toPaint[n + 1];
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			if (i != lastPlank) toPaint[b[i]].push_back(i);
		}
	}

	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		if (toPaint[c[i]].empty()) {
			ans[i] = lastPlank;
			a[lastPlank] = c[i];
		}
		else {
			int currPlank = toPaint[c[i]].back();
			toPaint[c[i]].pop_back();
			ans[i] = currPlank;
			a[currPlank] = c[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	for (auto &x : ans) {
		cout << x + 1 << ' ';
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