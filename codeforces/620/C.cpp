#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	set<ll> s;
	vector<pair<int, int>> ans;

	for (int i = 0, j = 0; j < n; j++) {
		if (s.count(a[j])) {
			ans.push_back({i + 1, j + 1});
			i = j + 1;
			s.clear();
		}
		else {
			s.insert(a[j]);
		}
	}

	if (ans.empty()) cout << "-1\n";
	else {
		if (!s.empty()) {
			ans.back().second = n;
		}

		cout << (int)ans.size() << '\n';
		for (auto &it : ans) {
			cout << it.first << ' ' << it.second << '\n';
		}
	}
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