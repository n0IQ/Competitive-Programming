#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a, b;
	cin >> a >> b;

	ll ans = 1;

	for (int i = 1; i <= b; i++) {
		ans *= a;
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