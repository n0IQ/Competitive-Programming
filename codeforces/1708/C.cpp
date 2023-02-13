#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> chose(n, 0);
	int k = 0, pos = -1;

	for (int i = n - 1; i >= 0; i--) {
		if (k < a[i]) {
			k++;
		}
		if (k > q) {
			pos = i;
			break;
		}
		chose[i] = 1;
	}

	for (int i = 0; i < pos; i++) {
		if (a[i] <= q) {
			chose[i] = 1;
		}
	}

	for (auto &x : chose) {
		cout << x;
	}
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