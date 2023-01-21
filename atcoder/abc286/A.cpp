#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, p, q, r, s;
	cin >> n >> p >> q >> r >> s;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> b(a);
	for (int i = p, j = r; i <= q; i++) {
		b[i] = a[j++];
	}
	for (int i = r, j = p; i <= s; i++) {
		b[i] = a[j++];
	}

	for (int i = 1; i <= n; i++) {
		cout << b[i] << ' ';
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