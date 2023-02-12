#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getSetBits(vector<int> &a, int k)
{
	int setBits = 0;
	for (auto &x : a) {
		setBits += ((x >> k) & 1);
	}
	return setBits;
}

void solve()
{
	int l, r;
	cin >> l >> r;

	int n = r - l + 1;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<int> b(n);
	iota(b.begin(), b.end(), 0);

	int ans = 0;
	for (int i = 0; i < 20; i++) {
		int setBits1 = getSetBits(a, i);
		int setBits2 = getSetBits(b, i);

		// cout << i << ' ' << setBits1 << ' ' << setBits2 << '\n';

		if (setBits1 != setBits2) {
			ans |= (1 << i);
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