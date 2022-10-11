#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int check(vector<ll> &a, vector<ll> &pref, int idx, int n, ll sum)
{
	int max_len = idx + 1, curr_len = 0;
	ll curr_sum = 0LL;

	for (int i = idx + 1; i < n; i++) {
		if (curr_sum + a[i] == sum) {
			max_len = max(max_len, curr_len + 1);
			curr_sum = 0;
			curr_len = 0;
		}
		else if (curr_sum + a[i] < sum) {
			curr_sum += a[i];
			curr_len++;
		}
		else {
			return -1;
		}
	}

	return curr_sum == 0 ? max_len : -1;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	vector<ll> pref(n, 0);
	pref[0] = a[0];
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1] + a[i];
	}

	int min_len = n;
	for (int i = 0; i < n; i++) {
		int ans = check(a, pref, i, n, pref[i]);

		// cout << i << ' ' << ans << '\n';

		if (ans != -1) {
			min_len = min(min_len, ans);
		}
	}

	cout << min_len << '\n';
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