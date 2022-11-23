#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll> &a, ll n, ll c, ll d, ll k)
{
	ll coins = 0, curr = 1;
	vector<bool> day(d + 10, 0);

	for (ll i = 0; i < n && curr <= d; i++) {
		if (day[curr]) break;

		for (int j = curr; j <= d; j += (k + 1)) {
			coins += a[i];
			day[j] = 1;
		}

		curr++;
	}

	return coins >= c;
}

void solve()
{
	ll n, c, d;
	cin >> n >> c >> d;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end(), greater<>());

	ll sum = 0;
	for (int i = 0; i < min(d, n); i++) {
		sum += a[i];
	}

	if (sum >= c) {
		cout << "Infinity\n";
		return;
	}
	if (a[0] * d < c) {
		cout << "Impossible\n";
		return;
	}

	ll l = 0, r = 2e6, ans = -1;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (check(a, n, c, d, mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
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