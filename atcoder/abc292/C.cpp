#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		ll a = i, b = n - i, div1 = 0, div2 = 0;

		for (ll j = 1; j * j <= a; j++) {
			if (a % j == 0) {
				div1++;
				if (a / j != j) div1++;
			}
		}

		for (ll j = 1; j * j <= b; j++) {
			if (b % j == 0) {
				div2++;
				if (b / j != j) div2++;
			}
		}

		ans += (div1 * div2);
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