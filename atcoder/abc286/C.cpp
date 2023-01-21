#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(string &s, int n)
{
	ll cnt = 0;
	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) cnt++;
	}
	return cnt;
}

void solve()
{
	int n;
	ll a, b;
	string s;
	cin >> n >> a >> b >> s;

	ll ans = LLONG_MAX;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, (i * 1LL * a) + (b * helper(s, n)));
		rotate(s.begin(), s.begin() + 1, s.end());
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
	// cin >> t;
	while (t--) solve();

	return 0;
}