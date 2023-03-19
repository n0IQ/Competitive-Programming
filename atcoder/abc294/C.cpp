#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<ll> a(n), b(m);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	a.push_back(LLONG_MAX);
	b.push_back(LLONG_MAX);

	vector<ll> posA(n), posB(m);
	int i = 0, j = 0, pos = 1;

	while (i < n || j < m) {
		if (a[i] < b[j]) {
			posA[i++] = pos++;
		}
		else {
			posB[j++] = pos++;
		}
	}

	for (auto &x : posA) cout << x << ' ';
	cout << '\n';
	for (auto &x : posB) cout << x << ' ';
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