#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<ll> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	ll score = 0;
	for (int i = 0; i < m; i++) {
		int idx;
		cin >> idx;
		score += a[idx];
	}

	cout << score << '\n';
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