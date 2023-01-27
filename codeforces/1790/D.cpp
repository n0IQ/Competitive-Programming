#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	multiset<ll> s;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		s.insert(x);
	}

	ll ans = 0;
	while (!s.empty()) {
		auto it = s.begin();
		ll x = *it;
		s.erase(it);

		while (!s.empty() && s.lower_bound(x + 1) != s.end() && *s.lower_bound(x + 1) == x + 1) {
			s.erase(s.lower_bound(x + 1));
			x = x + 1;
		}

		ans++;
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