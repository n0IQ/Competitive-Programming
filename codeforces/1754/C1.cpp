#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	if (n % 2 == 1) {
		cout << "-1\n";
		return;
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i += 2) {
		if (a[i] == 1) {
			if (a[i + 1] == 1) {
				ans.push_back({i, i + 1});
			}
			else {
				ans.push_back({i, i});
				ans.push_back({i + 1, i + 1});
			}
		}
		else if (a[i] == -1) {
			if (a[i + 1] == -1) {
				ans.push_back({i, i + 1});
			}
			else {
				ans.push_back({i, i});
				ans.push_back({i + 1, i + 1});
			}
		}
	}

	cout << (int)ans.size() << '\n';
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}