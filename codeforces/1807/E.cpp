#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll askQuery(ll k, ll l, ll r)
{
	cout << "? " << k << ' ';
	for (int i = l; i <= r; i++) {
		cout << i << ' ';
	}
	cout << endl;

	ll wt;
	cin >> wt;
	return wt;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n + 1, 0), pref(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}

	ll l = 1, r = n;
	while (l < r) {
		ll mid = l + (r - l) / 2;
		ll wt = askQuery(mid - l + 1, l, mid);
		ll stones = pref[mid] - pref[l - 1];

		if (wt > stones) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << "! " << l << endl;
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