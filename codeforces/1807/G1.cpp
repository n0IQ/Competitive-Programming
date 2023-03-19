#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	if (a[0] != 1 || (n > 1 && a[1] != 1)) {
		cout << "NO\n";
		return;
	}

	ll sum = 2;
	for (int i = 2; i < n; i++) {
		if (a[i] > sum) {
			cout << "NO\n";
			return;
		}
		sum += a[i];
	}

	cout << "YES\n";
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