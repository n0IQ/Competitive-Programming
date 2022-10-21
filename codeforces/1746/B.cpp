#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int ans = 0, i = 0, j = n - 1;

	while (i < j) {
		while (i < j && a[i] == 0) i++;
		while (i < j && a[j] == 1) j--;
		if (i >= j) break;
		ans++;
		i++, j--;
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