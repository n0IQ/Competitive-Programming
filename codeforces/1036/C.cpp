#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v;
ll dp[20][2][5];

ll helper(int idx, bool tight, int countNonZero)
{
	if (countNonZero > 3) {
		return 0;
	}
	if (idx >= (int)v.size()) {
		return countNonZero <= 3;
	}
	if (dp[idx][tight][countNonZero] != -1) {
		return dp[idx][tight][countNonZero];
	}

	ll ans = 0;

	for (int dgt = 0; dgt <= (tight ? v[idx] : 9); dgt++) {
		bool newTight = tight;
		int newCountNonZero = countNonZero;
		if (tight && dgt < v[idx]) newTight = 0;
		if (dgt != 0) newCountNonZero++;
		if (newCountNonZero <= 3) {
			ans += helper(idx + 1, newTight, newCountNonZero);
		}
	}

	return dp[idx][tight][countNonZero] = ans;
}

ll func(ll n)
{
	v.clear();
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}
	reverse(v.begin(), v.end());

	memset(dp, -1, sizeof(dp));
	return helper(0, 1, 0);
}

void solve()
{
	ll l, r;
	cin >> l >> r;
	cout << func(r) - func(l - 1) << '\n';
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