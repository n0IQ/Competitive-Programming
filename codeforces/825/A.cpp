#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	string ans;
	int zeros = 0;

	for (int i = 0; i < n; ) {
		int cnt = 0;
		ans += string(max(0, zeros - 1), '0');
		zeros = 0;

		while (i < n && s[i] == '1') {
			cnt++, i++;
		}

		ans += to_string(cnt);

		while (i < n && s[i] == '0') {
			zeros++, i++;
		}
	}

	ans += string(zeros, '0');

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