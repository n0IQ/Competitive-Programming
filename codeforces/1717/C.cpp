#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		if (a[i] > b[i]) {
			cout << "NO\n";
			return;
		}

		ll x = (i == n - 1 ? b[0] : b[i + 1]);
		if (x >= b[i] - 1) continue;
		else {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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