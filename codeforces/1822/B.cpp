#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> pos, neg, zero;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		if (x > 0) pos.push_back(x);
		else if (x < 0) neg.push_back(x);
		else zero.push_back(x);
	}

	ll ans = LLONG_MIN;
	if ((int)pos.size() >= 2) {
		sort(pos.begin(), pos.end());
		reverse(pos.begin(), pos.end());
		ans = max(ans, pos[0] * pos[1]);
	}
	if ((int)neg.size() >= 2) {
		sort(neg.begin(), neg.end());
		ans = max(ans, neg[0] * neg[1]);
	}
	if ((int)zero.size() >= 1) {
		ans = max(ans, 0LL);
	}
	if (pos.size() >= 1 && neg.size() >= 1) {
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		ans = max(ans, pos[0] * neg[0]);
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