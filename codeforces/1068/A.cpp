#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, m, k, l;
	cin >> n >> m >> k >> l;

	ll x = (l + k + m - 1) / m;
	if (x * m <= n) cout << x << '\n';
	else cout << "-1\n";
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