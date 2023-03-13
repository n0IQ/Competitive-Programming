#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b, c, d;
vector<vector<ll>> arr(5, vector<ll> (5, 0));

ll check(ll sum, ll x)
{
	ll firstSquare = arr[1][2] + arr[2][1] + x;
	ll secondSquare = arr[1][2] + arr[2][3] + x;
	ll thirdSquare = arr[2][1] + arr[3][2] + x;
	ll fourthSquare = arr[3][2] + arr[2][3] + x;

	if (sum - firstSquare <= 0) return 1;
	if (sum - firstSquare > n) return 2;

	if (sum - secondSquare <= 0) return 1;
	if (sum - secondSquare > n) return 2;

	if (sum - thirdSquare <= 0) return 1;
	if (sum - thirdSquare > n) return 2;

	if (sum - fourthSquare <= 0) return 1;
	if (sum - fourthSquare > n) return 2;

	return 0;
}

void solve()
{
	cin >> n >> a >> b >> c >> d;

	arr[1][2] = a, arr[2][1] = b, arr[2][3] = c, arr[3][2] = d;
	ll minSum = arr[1][2] + arr[2][1] + 2, maxSum = arr[1][2] + arr[2][1] + (2LL * n);
	ll ans = 0;

	for (ll i = minSum; i <= maxSum; i++) {
		ll l, r, minVal, maxVal;

		// get minimum Possible value to be kept at (2,2) for sum i
		l = 1, r = n, minVal = -1;

		while (l <= r) {
			ll mid = l + (r - l) / 2;
			ll res = check(i, mid);

			if (res == 0) {
				minVal = mid;
				r = mid - 1;
			}
			else if (res == 1) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		// get maximum Possible value to be kept at (2,2) for sum i
		l = 1, r = n, maxVal = -1;
		while (l <= r) {
			ll mid = l + (r - l) / 2;
			ll res = check(i, mid);
			if (res == 0) {
				maxVal = mid;
				l = mid + 1;
			}
			else if (res == 2) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		// cout << i << ' ' << minVal << ' ' << maxVal << '\n';

		if (minVal != -1 && maxVal != -1) {
			ans += (maxVal - minVal + 1);
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