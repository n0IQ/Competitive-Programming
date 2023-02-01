#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool ok = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == -1 && a[i + 1] == -1) {
			a[i] = 1;
			a[i + 1] = 1;
			ok = 1;
			break;
		}
	}

	if (ok) {
		cout << accumulate(a.begin(), a.end(), 0) << '\n';
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if ((a[i] == 1 && a[i + 1] == -1) || (a[i] == -1 && a[i + 1] == 1)) {
			int sum = accumulate(a.begin(), a.end(), 0);
			cout << sum << '\n';
			return;
		}
	}

	a[0] = -1, a[1] = -1;
	cout << accumulate(a.begin(), a.end(), 0) << '\n';
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