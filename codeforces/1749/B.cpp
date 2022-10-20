#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), b(n);
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(b.begin(), b.end());
	for (int i = 0; i < n - 1; i++) {
		ans += b[i];
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