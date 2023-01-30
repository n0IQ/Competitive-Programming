#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	map<ll, ll> mp;
	for (ll i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			mp[i]++;
			n /= i;
		}
	}
	if (n > 1) mp[n]++;

	ll ans = 0;
	while (1) {
		ll sum = 1, flag = 0;

		for (auto &it : mp) {
			if (it.second > 0) {
				flag = 1;
				sum *= it.first;
				it.second--;
			}
		}

		if (!flag) break;
		else ans += sum;
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