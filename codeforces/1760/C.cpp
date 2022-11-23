#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	vector<pair<ll, ll>> b;
	for (int i = 0; i < n; i++) {
		b.push_back({a[i], i});
	}
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) {
		if (i == b[n - 1].second) {
			cout << a[i] - b[n - 2].first << ' ';
		}
		else {
			cout << a[i] - b[n - 1].first << ' ';
		}
	}

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