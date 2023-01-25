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

	vector<ll> pref(n + 5, 0), suff(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i - 1];
	}
	for (int i = n; i >= 1; i--) {
		suff[i] = suff[i + 1] + a[i - 1];
	}

	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll g = __gcd(pref[i], suff[i + 1]);
		ans = max(ans, g);
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