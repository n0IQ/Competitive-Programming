#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, x, p;
	cin >> n >> x >> p;

	for (ll i = 1; i <= min(5 * n, p); i++) {
		ll f = (i * (i + 1)) / 2;
		ll val = (x + f) % n;
		if (val == 0) {
			cout << "Yes\n";
			return;
		}
	}

	cout << "No\n";
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