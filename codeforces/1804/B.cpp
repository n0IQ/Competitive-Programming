#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> &a, ll n, ll k, ll d, ll w, ll boxes)
{
	ll currBox = 1, start = a.back(), supply = 1;
	for (int i = n - 2; i >= 0; i--) {
		if ((supply >= k) || (start - min(a[i] + w, start) > d)) {
			start = a[i];
			currBox++;
			supply = 1;
		}
		else {
			supply++;
		}
	}

	return currBox <= boxes;
}

void solve()
{
	ll n, k, d, w;
	cin >> n >> k >> d >> w;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	ll l = 1, r = n + 10, ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (check(a, n, k, d, w, mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
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