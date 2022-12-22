#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	sort(a.begin(), a.end());

	for (int i = 0; i < m; i++) {
		auto it = upper_bound(a.begin(), a.end(), b[i]);
		cout << it - a.begin() << ' ';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}