#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, a, b;
	cin >> n >> a >> b;

	if (a == b && a == n) {
		cout << "YES\n";
	}
	else {
		if (a + b <= n - 2) cout << "YES\n";
		else cout << "NO\n";
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
	cin >> t;
	while (t--) solve();

	return 0;
}