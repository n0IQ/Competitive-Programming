#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll searchEven(ll n)
{
	ll l = 0, r = 2e9, ans = r;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (4LL * mid * (mid + 1) + 1 >= n) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return 2 * ans;
}

ll searchOdd(ll n)
{
	ll l = 0, r = 2e9, ans = r;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		if (4 * mid * mid >= n) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return 2 * ans - 1;
}

void solve()
{
	ll n;
	cin >> n;

	cout << min(searchEven(n), searchOdd(n)) << '\n';
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