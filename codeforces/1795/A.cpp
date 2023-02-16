#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s >> t;

	reverse(t.begin(), t.end());
	s += t;

	int count = 0;
	for (int i = 0; i < n + m - 1; i++) {
		if (s[i] == s[i + 1]) {
			count++;
		}
	}

	if (count <= 1) cout << "YES\n";
	else cout << "NO\n";
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