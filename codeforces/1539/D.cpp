#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, totalProducts = 0;
	cin >> n;

	vector<pair<ll, ll>> a(n); // required for discount, need to purchase
	for (int i = 0; i < n; i++) {
		ll ai, bi;
		cin >> ai >> bi;
		a[i] = {bi, ai};
	}

	sort(a.begin(), a.end());
	int i = 0, j = n - 1;
	ll ans = 0, currProducts = 0;

	while (i <= j) {
		if (currProducts >= a[i].first) {
			ans += a[i].second;
			currProducts += a[i].second;
			i++;
		}
		else {
			ll t = min(a[i].first - currProducts, a[j].second);
			ans += (t * 2LL);
			currProducts += t;
			a[j].second -= t;
			if (a[j].second == 0) j--;
		}
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
	// cin >> t;
	while (t--) solve();

	return 0;
}