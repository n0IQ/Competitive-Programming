#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<ll> a(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll sum = accumulate(a.begin(), a.end(), 0LL);
	vector<ll> pref(n + 10, 0);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	for (int i = 0; i < q; i++) {
		ll l, r, x;
		cin >> l >> r >> x;

		ll currSum = abs(sum - pref[r] - pref[l - 1] + ((r - l + 1) * x));
		if (currSum & 1) cout << "YES\n";
		else cout << "NO\n";
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