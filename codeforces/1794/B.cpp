#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) {
		cin >> x;
		if (x == 1) x++;
	}

	for (int i = 0; i < n - 1; i++) {
		if ((a[i + 1] % a[i]) == 0) a[i + 1]++;
	}
	for (auto &x : a) cout << x << ' ';
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