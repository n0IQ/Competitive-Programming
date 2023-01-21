#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll x, y;
	cin >> x >> y;

	if (x == y) {
		cout << x << '\n';
	}
	else if (x > y) {
		cout << x + y << '\n';
	}
	else {
		ll t = x * (y / x);
		cout << (t + y) / 2 << '\n';
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