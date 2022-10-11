#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	if (n == 3) {
		cout << "-1\n";
		return;
	}
	for (int i = n; i >= (n % 2 == 0 ? (n / 2) + 1 : (n / 2) + 2); i--) {
		cout << i << ' ';
	}
	for (int i = 1; i <= (n % 2 == 0 ? n / 2 : (n + 1) / 2); i++) {
		cout << i << ' ';
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