#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size();

	if (n == 1) {
		if (s[0] == '0') cout << "0\n";
		else if (s[0] == '?') cout << "9\n";
		else cout << "1\n";
		return;
	}

	if (s[0] == '0') {
		cout << "0\n";
		return;
	}

	ll ans = 1LL;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (i == 0) ans *= 9LL;
			else ans *= 10LL;
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