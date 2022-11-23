#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(vector<ll> a, int n)
{
	ll ans = 0, zero = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 0) zero++;
		else ans += zero;
	}
	return ans;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	ll ans = helper(a, n);

	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 1) {
			a[i] = 0;
			ans = max(ans, helper(a, n));
			a[i] = 1;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			a[i] = 1;
			ans = max(ans, helper(a, n));
			a[i] = 0;
			break;
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