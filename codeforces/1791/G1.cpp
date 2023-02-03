#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	ll c;
	cin >> n >> c;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (ll i = 1; i <= n; i++) {
		pq.push(i + a[i]);
	}

	ll ans = 0;
	while (!pq.empty()) {
		ll cost = pq.top();
		pq.pop();

		if (c - cost >= 0) {
			ans++;
			c -= cost;
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