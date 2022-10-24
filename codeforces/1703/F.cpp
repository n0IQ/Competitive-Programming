#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<ll> v;
	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] >= i) continue;
		v.push_back(a[i]);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		if (a[i] >= i) continue;
		auto it = lower_bound(v.begin(), v.end(), i + 1);
		ans += (int)(v.end() - it);
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