#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int first = -1, last = -1;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '1') {
			if (first == -1) first = i;
			last = i;
		}
	}

	if (first == -1) {
		cout << "0\n";
		return;
	}

	int ans = 0;
	for (int i = first; i <= last; i++) {
		if (s[i] == '0') ans++;
	}

	cout << ans << '\n';
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