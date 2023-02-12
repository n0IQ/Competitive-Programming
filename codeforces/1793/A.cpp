#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a, b, n, m;
	cin >> a >> b >> n >> m;

	if (m >= n) cout << min(a, b) * n << '\n';
	else if (b * (m + 1) <= a * m) cout << b * n << '\n';
	else {
		ll x = n / (m + 1);
		ll rem = n % (m + 1);
		ll cost = a * (x * m);

		if (a <= b) {
			cost += (rem * a);
		}
		else {
			cost += (rem * b);
		}

		cout << cost << '\n';
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