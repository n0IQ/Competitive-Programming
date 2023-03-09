#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, m;
	cin >> n >> m;

	vector<ll> ans(n, 0), cnt(101, 0);
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;

		ll reqSum = m - x, take = 1;

		for (ll j = 1; j <= 100; j++) {
			ll t = min(max(0LL, cnt[j]), reqSum / j);
			reqSum -= (j * t);
			take += t;
		}

		cout << i - take << ' ';
		cnt[x]++;
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
	// cin >> t;
	while (t--) solve();

	return 0;
}