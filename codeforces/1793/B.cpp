#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll x, y;
	cin >> x >> y;

	ll n = (x - y) * 2;
	cout << n << '\n';

	int val = x, ok = 1;
	for (int i = 1; i <= n; i++) {
		cout << x << ' ';
		if (ok) x--;
		else x++;

		if (x == y - 1) {
			x = y + 1;
			ok = 0;
		}
	}

	cout << '\n';
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