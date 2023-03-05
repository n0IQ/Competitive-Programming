#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	priority_queue<ll> pq;
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				ans += pq.top();
				pq.pop();
			}
		}
		else {
			pq.push(x);
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