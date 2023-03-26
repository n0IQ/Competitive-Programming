#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int m;
	cin >> m;

	vector<vector<int>> a(m);
	map<int, vector<int>> mp;

	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		vector<int> t(n);

		for (int j = 0; j < n; j++) {
			cin >> t[j];
			mp[t[j]].push_back(i);
		}

		a[i] = t;
	}

	vector<int> ans(m);

	for (int i = 0; i < m; i++) {
		bool found = false;

		for (auto &x : a[i]) {
			auto it = upper_bound(mp[x].begin(), mp[x].end(), i);
			if (it == mp[x].end()) {
				ans[i] = x;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "-1\n";
			return;
		}
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