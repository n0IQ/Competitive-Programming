#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, a, b, c;
	cin >> n >> a >> b >> c;

	if (n % 4 == 0) {
		cout << "0\n";
	}
	else if (n % 4 == 1) {
		cout << min({a * 3LL, a + b, c}) << '\n';
	}
	else if (n % 4 == 2) {
		cout << min({a * 2LL, b, c * 2LL}) << '\n';
	}
	else {
		cout << min({a, b + c, 3LL * c}) << '\n';
	}
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