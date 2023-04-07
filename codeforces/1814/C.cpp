#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, s1, s2;
	cin >> n >> s1 >> s2;

	priority_queue<pair<ll, ll>> pq;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		pq.push({x, i});
	}

	vector<ll> a, b;
	ll t1 = s1, t2 = s2;

	while (!pq.empty()) {
		ll task = pq.top().second;
		pq.pop();
		if (t1 <= t2) {
			a.push_back(task);
			t1 += s1;
		}
		else {
			b.push_back(task);
			t2 += s2;
		}
	}

	cout << (int)a.size() << ' ';
	for (auto &x : a) cout << x << ' ';
	cout << '\n';
	cout << (int)b.size() << ' ';
	for (auto &x : b) cout << x << ' ';
	cout << '\n';
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