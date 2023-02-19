#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	string s;
	cin >> n >> k >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			if (k <= 0) s[i] = 'x';
			k--;
		}
	}

	cout << s << '\n';
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