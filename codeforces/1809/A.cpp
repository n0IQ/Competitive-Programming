#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	sort(s.begin(), s.end());
	map<char, int> mp;
	for (auto &ch : s) mp[ch]++;

	if ((int)mp.size() == 1) {
		cout << "-1\n";
		return;
	}
	if ((int)mp.size() == 2) {
		bool ok = 0;
		for (auto &it : mp) {
			if (it.second >= 3) ok = 1;
		}

		if (ok) cout << "6\n";
		else cout << "4\n";
	}
	else {
		cout << "4\n";
		return;
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