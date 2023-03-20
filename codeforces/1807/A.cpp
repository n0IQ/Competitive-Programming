#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b == c) cout << "+\n";
	else cout << "-\n";
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