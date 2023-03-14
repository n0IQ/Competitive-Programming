#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	m--;
	vector<ll> a(n), pref(n, 0);
	for (auto &x : a) cin >> x;

	for (int i = 0; i < n; i++) {
		pref[i] = a[i];
		if (i > 0) pref[i] += pref[i - 1];
	}

	ll ans = 0, curr = pref[m];
	priority_queue<ll> max_heap;

	for (int i = m; i >= 0; i--) {
		while (pref[i] < curr) {
			ll x = max_heap.top();
			max_heap.pop();

			curr -= (2LL * x);
			ans++;
		}

		max_heap.push(a[i]);
	}

	priority_queue<ll, vector<ll>, greater<ll>> min_heap;
	curr = pref[m];

	for (int i = m + 1; i < n; i++) {
		min_heap.push(a[i]);

		while (pref[i] < curr) {
			ll x = min_heap.top();
			min_heap.pop();
			curr += (2LL * x);
			ans++;
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