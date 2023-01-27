#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, s, r;
	cin >> n >> s >> r;

	vector<int> a(n, s - r);
	int sum = accumulate(a.begin(), a.end(), 0);

	for (int i = 1; i < n; i++) {
		while (sum > s && a[i] > 1) {
			a[i]--;
			sum--;
		}
	}

	for (auto &x : a) {
		cout << x << ' ';
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
	cin >> t;
	while (t--) solve();

	return 0;
}