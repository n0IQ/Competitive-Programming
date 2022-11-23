#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	int cnt = 0;
	for (int j = 0; j < n; j++) {
		int i = j;
		while (j < n && a[j] == a[i]) j++;
		j--;

		int condition = 0;

		if (i == 0) condition++;
		else if (i > 0 && a[i - 1] > a[i]) {
			condition++;
		}

		if (j == n - 1) condition++;
		else if (j < n - 1 && a[j] < a[j + 1]) {
			condition++;
		}

		if (condition == 2) cnt++;
	}

	if (cnt == 1) cout << "YES\n";
	else cout << "NO\n";
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