#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	for (ll x = a + 1; x <= c; x++) {
		ll y = (a * b) / __gcd(a * b, x);
		y = y * (d / y);

		if (y > b && y <= d) {
			cout << x << ' ' << y << '\n';
			return;
		}
	}

	cout << "-1 -1\n";
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