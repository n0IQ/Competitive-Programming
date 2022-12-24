#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size();
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			if (i < n - 1 && s[i + 1] == '0') {
				ans++;
				i++;
			}
			else ans++;
		}
		else {
			ans++;
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
	//cin >> t;
	while (t--) solve();

	return 0;
}