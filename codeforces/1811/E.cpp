#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
vector<ll> v;
ll dp[16][2][2];

ll helper(int idx, bool hasFour, bool tight)
{
	if (idx >= (int)v.size()) {
		return hasFour;
	}
	if (dp[idx][hasFour][tight] != -1) {
		return dp[idx][hasFour][tight];
	}

	ll ans = 0;
	for (int dgt = 0; dgt <= (tight ? v[idx] : 9); dgt++) {
		bool newTight = tight;
		bool newHasFour = hasFour;

		if (tight && dgt < v[idx]) newTight = 0;
		if (hasFour == 0 && dgt == 4) newHasFour = 1;
		ans += helper(idx + 1, newHasFour, newTight);
	}

	return dp[idx][hasFour][tight] = ans;
}

ll check(ll n)
{
	v.clear();
	ll r = n;
	while (r) {
		v.push_back(r % 10);
		r /= 10;
	}
	reverse(v.begin(), v.end());

	memset(dp, -1, sizeof(dp));
	ll count = helper(0, 0, 1);
	// cout << "count: " << count << '\n';

	if (k + count == n) return 1;
	else if (k + count < n) return 0;
	else return 2;
}

void solve()
{
	cin >> k;

	ll l = 1, r = 1e15, ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		ll res = check(mid);

		if (res == 1) {
			ans = mid;
			r = mid - 1;
		}
		else if (res == 0) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
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