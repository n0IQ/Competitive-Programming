#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	bool isPossible = false, start = false, end = false;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;

		if (l == r && l == k) isPossible = true;
		else if (l == k) start = true;
		else if (r == k) end = true;
	}

	if (isPossible || (start && end)) cout << "YES\n";
	else cout << "NO\n";
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