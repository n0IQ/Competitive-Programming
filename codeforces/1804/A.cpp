#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a, b;
	cin >> a >> b;

	a = abs(a);
	b = abs(b);

	ll t = min(a, b);
	ll ans = t * 2LL;
	a -= t;
	b -= t;

	if (a > 0) {
		ans++;
		a--;
		ans += (2 * a);
	}
	else if (b > 0) {
		ans++;
		b--;
		ans += (2 * b);
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