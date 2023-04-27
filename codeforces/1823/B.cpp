#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<int> a(n + 10);
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (abs(a[i] - i) % k != 0) cnt++;
	}

	if (cnt == 0) cout << "0\n";
	else if (cnt == 2) cout << "1\n";
	else cout << "-1\n";
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