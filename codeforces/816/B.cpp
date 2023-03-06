#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 200000;

void solve()
{
	int n, k, q;
	cin >> n >> k >> q;

	vector<int> diff(MAXN + 10, 0);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		diff[l]++;
		diff[r + 1]--;
	}

	vector<ll> d(MAXN + 10, 0);
	d[0] = diff[0];
	for (int i = 1; i <= MAXN; i++) {
		d[i] = d[i - 1] + diff[i];
	}

	vector<ll> pref(MAXN + 10, 0);
	pref[0] = d[0];
	for (int i = 1; i <= MAXN; i++) {
		pref[i] = pref[i - 1] + (d[i] >= k);
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << pref[b] - pref[a - 1] << '\n';
	}
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
	// cin >> t;
	while (t--) solve();

	return 0;
}