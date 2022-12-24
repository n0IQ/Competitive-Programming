#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;

		if (t == 1) {
			int k, x;
			cin >> k >> x;
			a[k] = x;
		}
		else {
			int k;
			cin >> k;
			cout << a[k] << '\n';
		}
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