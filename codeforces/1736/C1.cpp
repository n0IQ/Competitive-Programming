#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll ans = 0, len = 1;
	int i = 1, j = 1, idx = 1;

	while (j <= n) {
		while (j <= n && a[j] >= idx) {
			ans += len;
			len++, j++, idx++;
		}

		while (i <= j && a[j] < idx) {
			i++, idx--, len--;
		}
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