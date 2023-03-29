#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(ll n)
{
	ll minVal = 10, maxVal = 0;
	while (n) {
		ll d = n % 10;
		n /= 10;
		minVal = min(minVal, d);
		maxVal = max(maxVal, d);
	}

	return maxVal - minVal;
}

void solve()
{
	ll l, r;
	cin >> l >> r;

	ll ans = -1, x = l;
	for (ll i = l; i <= r; i++) {
		ll diff = helper(i);
		if (diff >= ans) {
			ans = diff;
			x = i;
		}
		if (ans == 9) break;
	}

	cout << x << '\n';
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