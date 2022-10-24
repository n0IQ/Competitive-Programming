#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int q;
	cin >> q;
	set<ll> s = {0};
	map<ll, ll> mp;

	while (q--) {
		char ch;
		ll x;
		cin >> ch >> x;

		if (ch == '+') {
			s.insert(x);
		}
		else {
			ll i = mp[x];
			while (s.count(x * i)) {
				i++;
			}

			mp[x] = i;
			cout << x*i << '\n';
		}
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