#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}

	int maxA = *max_element(a.begin(), a.end());
	int maxB = *max_element(b.begin(), b.end());

	if (a.back() == maxA && b.back() == maxB) cout << "Yes\n";
	else cout << "No\n";
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