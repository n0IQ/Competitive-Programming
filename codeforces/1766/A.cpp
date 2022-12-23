#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	if (n <= 9) {
		cout << n << '\n';
		return;
	}

	string s = to_string(n);
	ll ans = 0;
	for (int i = 1; i < s.size(); i++) {
		ans += 9;
	}

	string t(s.size(), '0');
	t[0] = '1';
	int x = stoi(t);
	ans += n / x;

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