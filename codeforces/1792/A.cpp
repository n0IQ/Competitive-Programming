#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	int ans = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) cnt1++;
		else ans++;
	}

	cout << ans + (cnt1 + 1) / 2 << '\n';
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