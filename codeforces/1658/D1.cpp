#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int l, r;
	cin >> l >> r;

	int n = r - l + 1;
	vector<int> originalBits(20), newBits(20);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < 20; j++) if ((x >> j) & 1) newBits[j]++;
		for (int j = 0; j < 20; j++) if ((i >> j) & 1) originalBits[j]++;
	}

	int x = 0;
	for (int i = 0; i < 20; i++) {
		if (originalBits[i] != newBits[i]) x += (1 << i);
	}

	cout << x << '\n';
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