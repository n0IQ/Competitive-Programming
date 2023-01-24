#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n + 1), pos(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	int ans = n / 2;
	int i = (n + 1) / 2, l = pos[i], r = pos[n - i + 1];

	if (pos[i] > pos[n - i + 1]) {
		cout << ans << '\n';
		return;
	}

	if (n % 2 == 0) {
		ans--;
	}

	while (--i) {
		if (pos[i] < l && pos[n - i + 1] > r) {
			l = pos[i];
			r = pos[n - i + 1];
			ans--;
		}
		else {
			break;
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