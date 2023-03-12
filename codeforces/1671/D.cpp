#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200000;

/*
- inserting any x b/w min and max Values doesn't change the optimal answer.
- only remaining values are 1...min-1 and max + 1...x.
- optimal way is to insert 1 close to min Value or at start or at end, similar for x.
*/

void solve()
{
	int n, x;
	cin >> n >> x;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	ll ans = 0, minVal = a[0], maxVal = a[0];
	for (int i = 0; i < n - 1; i++) {
		ans += abs(a[i] - a[i + 1]);
		minVal = min(minVal, a[i + 1]);
		maxVal = max(maxVal, a[i + 1]);
	}

	if (minVal > 1) {
		ans += min({a[0] - 1, a.back() - 1, 2 * (minVal - 1)});
	}
	if (maxVal < x) {
		ans += min({x - a[0], x - a.back(), 2 * (x - maxVal)});
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