#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int q, x;
	cin >> q >> x;

	map<ll, ll> mp;
	ll mex = 0;

	for (int i = 0; i < q; i++) {
		ll val;
		cin >> val;
		mp[val % x]++;

		while (mp[mex % x] > 0) {
			mp[mex % x]--;
			mex++;
		}

		cout << mex << '\n';
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