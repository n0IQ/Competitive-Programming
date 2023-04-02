#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<ll> line(n);
	for (auto &x : line) {
		cin >> x;
	}
	sort(line.begin(), line.end());

	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;

		// D = (b - k)^2 - 4ac

		auto it = lower_bound(line.begin(), line.end(), b);
		if (it == line.end()) it--;

		ll x = *it;
		ll d = ((b - x) * (b - x)) - (4LL * a * c);

		if (d < 0) {
			cout << "YES\n" << *it << '\n';
			continue;
		}

		if (it != line.begin()) it--;

		x = *it;
		d = ((b - x) * (b - x)) - (4LL * a * c);

		if (d < 0) {
			cout << "YES\n" << *it << '\n';
		}
		else {
			cout << "NO\n";
		}
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