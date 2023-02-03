#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, l, r, s;
	cin >> n >> l >> r >> s;

	int range = r - l + 1;
	int mn = (range * (range + 1)) / 2;
	int mx = ((n * (n + 1)) / 2) - (((n - range) * (n - range + 1)) / 2);

	// cout << mn << ' ' << mx << '\n';

	if (s < mn || s > mx) {
		cout << "-1\n";
		return;
	}

	vector<int> a(n + 1, 0);
	int x = 1;
	for (int i = l; i <= r; i++) {
		a[i] = x++;
	}

	int sum = mn, i = r;
	x = n;

	while (sum < s) {
		if (sum - a[i] + x <= s) {
			sum = sum - a[i] + x;
			a[i] = x;
			i--, x--;
		}
		else {
			a[i] = s - (sum - a[i]);
			break;
		}
	}

	set<int> rem;
	for (int i = 1; i <= n; i++) rem.insert(i);
	for (int i = l; i <= r; i++) rem.erase(a[i]);
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			a[i] = *rem.begin();
			rem.erase(rem.begin());
		}
	}

	for (i = 1; i <= n; i++) {
		cout << a[i] << ' ';
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