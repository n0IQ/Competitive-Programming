#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> a, int n, ll k)
{
	vector<ll> mark(n, 0);

	for (int i = 1; i <= k; i++) {
		ll x = k - i + 1, ok = 0;

		for (int j = n - 1; j >= 0; j--) {
			if (a[j] != -1 && a[j] <= x) {
				a[j] = -1;
				mark[j] = 1;
				ok = 1;
				break;
			}
		}

		for (int j = 0; j < n; j++) {
			if (!mark[j] && a[j] < x) {
				a[j] += x;
				mark[j] = 1;
				break;
			}
		}

		if (!ok) return false;
	}

	return true;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	sort(a.begin(), a.end());
	ll l = 1, r = n, ans = 0;

	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (check(a, n, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
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
	cin >> t;
	while (t--) solve();

	return 0;
}