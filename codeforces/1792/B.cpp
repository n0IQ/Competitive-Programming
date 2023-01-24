#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a == 0) cout << "1\n";
	else if (abs(b - c) <= a) {
		cout << a + b + c + min(a - abs(b - c) + 1, d) << '\n';
	}
	else {
		cout << a + 2 * min(b, c) + a + 1 << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}