#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	vector<ll> pref(n + 10, 0LL);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + b[i];
	}

	vector<ll> ans(n + 10, 0), diff(n + 10, 0);

	for (int i = 1; i <= n; i++) {
		if (b[i] >= a[i]) {
			ans[i] += min(a[i], b[i]);
			continue;
		}

		int l = i, r = n, idx = i;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			ll x = pref[mid] - pref[i - 1];

			if (a[i] >= x) {
				idx = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}

		diff[i]++;
		diff[idx + 1]--;
		ans[idx + 1] += (a[i] - (pref[idx] - pref[i - 1]));
	}

	vector<ll> finalDiff(n + 10, 0);
	finalDiff[1] = diff[1];
	for (int i = 2; i <= n; i++) {
		finalDiff[i] = finalDiff[i - 1] + diff[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] + max(0LL, b[i] * finalDiff[i]) << ' ';
	}
	cout << '\n';
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