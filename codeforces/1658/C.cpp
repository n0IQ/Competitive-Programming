#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int idx = -1;
	for (int i = 0; i < n; i++) {
		if (c[i] == 1) {
			if (idx == -1) idx = i;
			else {
				cout << "NO\n";
				return;
			}
		}
	}

	if (idx == -1) {
		cout << "NO\n";
		return;
	}

	rotate(c.begin(), c.begin() + idx, c.end());
	for (int i = 1; i < n; i++) {
		if (c[i] - c[i - 1] > 1) {
			cout << "NO\n";
			return;
		}
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