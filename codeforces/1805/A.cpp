#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), b(n);
	ll exor = 0;
	for (auto &x : a) {
		cin >> x;
		exor ^= x;
	}

	ll ans = exor;

	for (int i = 0; i < n; i++) {
		b[i] = (a[i] ^ exor);
	}

	exor = 0;
	for (auto &x : b) {
		exor ^= x;
	}

	if (exor == 0) cout << ans << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}