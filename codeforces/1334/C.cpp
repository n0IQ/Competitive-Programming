#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	ll ans = LLONG_MAX, sum = 0;

	for (int i = 0; i < n; i++) {
		ll x = (i == 0 ? b[n - 1] : b[i - 1]);
		c[i] = max(0LL, a[i] - x);
		sum += c[i];
	}

	for (int i = 0; i < n; i++) {
		ans = min(ans, sum - c[i] + a[i]);
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