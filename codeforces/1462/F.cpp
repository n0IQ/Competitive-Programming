#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<pair<ll, ll>> a(n);
	for (auto &i : a) {
		cin >> i.first >> i.second;
	}
	sort(a.begin(), a.end());

	vector<ll> starts(n), ends(n);
	for (int i = 0; i < n; i++) {
		starts[i] = a[i].first;
		ends[i] = a[i].second;
	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());

	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		int cnt = (int)(lower_bound(ends.begin(), ends.end(), a[i].first) - ends.begin());
		cnt += (int)(starts.end() - upper_bound(starts.begin(), starts.end(), a[i].second));
		ans = min(ans, cnt);
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