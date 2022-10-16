#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	ll even = 0, odd = 0, evenSum = 0, oddSum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			even++;
			evenSum += a[i];
		}
		else {
			odd++;
			oddSum += a[i];
		}
	}

	while (q--) {
		ll t, x, total = 0;
		cin >> t >> x;

		if (t == 0) { // add in even
			if (x % 2 == 0) {
				evenSum += (even * x);
				total = evenSum + oddSum;
			}
			else {
				evenSum += (even * x);
				oddSum += evenSum;
				odd += even;
				even = 0;
				evenSum = 0;
			}
		}
		else { // add in odd
			if (x % 2 == 0) {
				oddSum += (odd * x);
				total = evenSum + oddSum;
			}
			else {
				oddSum += (odd * x);
				evenSum += oddSum;
				even += odd;
				oddSum = 0;
				odd = 0;
			}
		}

		cout << evenSum + oddSum << '\n';
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