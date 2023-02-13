#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	int neg = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) neg++;
		else if (a[i] == 0) zero++;
	}

	if ((neg % 2 == 0) || (zero > 0)) {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += abs(a[i]);
		}
		cout << sum << '\n';
	}
	else {
		ll x = INT_MAX;
		for (int i = 0; i < n; i++) {
			x = min(x, abs(a[i]));
		}

		ll sum = 0, ok = 1;
		for (int i = 0; i < n; i++) {
			if (ok && abs(a[i]) == x) {
				ok = 0;
			}
			else sum += abs(a[i]);
		}
		cout << sum - x << '\n';
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