#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	map<char, int> mp;
	int ans = 0;

	for (int i = 0; i < (int)s.size(); i++) {
		mp[s[i]]++;

		if ((int)mp.size() > 3) {
			ans++;
			mp.clear();
			mp[s[i]]++;
		}
	}

	cout << ans + 1 << '\n';
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