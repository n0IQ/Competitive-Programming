#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<ll> pref(n + 10, 0);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	ll ans = 0, maxfreq = 0, flag = 1;
	map<ll, ll> mp;

	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			if (flag) ans += mp[0];
			else ans += maxfreq;
			flag = 0;
			maxfreq = 0;
			mp.clear();
		}

		maxfreq = max(maxfreq, ++mp[pref[i]]);
	}

	if (!flag) ans += maxfreq;
	else ans += mp[0];

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