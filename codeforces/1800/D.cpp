#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	ll ans = 1;
	for (int i = 2; i < n; i++) {
		if (s[i] != s[i - 2]) ans++;
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