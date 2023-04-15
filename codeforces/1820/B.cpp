#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size();

	if (n == 1) {
		if (s[0] == '1') cout << "1\n";
		else cout << "0\n";
		return;
	}

	ll ones = 0;
	for (auto &ch : s) {
		if (ch == '1') ones++;
	}

	if (ones == n) {
		cout << n * 1LL * n << '\n';
		return;
	}

	s += s;
	int sz = (int)s.size();

	ll max_cnt = 0;
	for (int i = 0; i < sz; i++) {
		if (s[i] == '1') {
			ll cnt = 0;
			while (i < sz && s[i] == '1') {
				i++, cnt++;
			}

			max_cnt = max(max_cnt, cnt);
		}
	}

	// cout << max_cnt << ' ';

	ll ans = 0, len = max_cnt;
	for (ll i = 1LL; i <= max_cnt; i++) {
		ans = max(ans, len * 1LL * i);
		len--;
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