#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<pair<ll, ll>> a(n), ans;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a[i] = {x, i};
	}
	sort(a.begin(), a.end());

	while (a[0].first != 1) {
		ll minValue = a[0].first, idx = a[0].second;
		bool hasChanged = false;

		for (int i = 1; i < n; i++) {
			if (a[i].first != minValue) {
				hasChanged = true;
				ans.push_back({a[i].second, idx});
				a[i].first = (a[i].first + minValue - 1) / minValue;
			}
		}

		if (!hasChanged) break;
		sort(a.begin(), a.end());
	}

	for (int i = 1; i < n; i++) {
		if (a[i].first != a[i - 1].first) {
			cout << "-1\n";
			return;
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