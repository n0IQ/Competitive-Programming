#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, l, r, x;
vector<ll> a;

ll helper(int i, ll sum, ll minD, ll maxD)
{
	if (i >= n) {
		if ((sum >= l && sum <= r) && (maxD - minD >= x)) {
			return 1;
		}
		return 0;
	}

	ll ans = helper(i + 1, sum, minD, maxD);
	ans += helper(i + 1, sum + a[i], min(minD, a[i]), max(maxD, a[i]));
	return ans;
}

void solve()
{
	cin >> n >> l >> r >> x;

	a.resize(n);
	for (auto &x : a) cin >> x;

	cout << helper(0, 0, INT_MAX, INT_MIN) << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}