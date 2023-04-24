#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	if (n == 1) {
		cout << "1\n";
		return;
	}

	if (n % 2) {
		cout << "-1\n";
		return;
	}

	vector<int> b(n);
	b[0] = n;

	for (int i = 1; i <= n; i += 2) {
		b[i] = i;
	}
	for (int i = 2, val = n - 2; i < n; i += 2, val -= 2) {
		b[i] = val;
	}

	for (auto &x : b) {
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