#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, m, k, l;
	cin >> n >> m >> k >> l;

	ll left = 1, right = n / m, ans = -1;
	while (left <= right) {
		ll mid = left + (right - left) / 2;
		ll og = mid * m - k;

		if (og >= l) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
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