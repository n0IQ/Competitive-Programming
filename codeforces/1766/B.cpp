#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	if (n <= 3) {
		cout << "NO\n";
		return;
	}

	map<string, int> mp;
	mp[s.substr(0, 2)]++;

	for (int i = 2; i < n - 1; i++) {
		string t = s.substr(i, 2);
		if (mp.count(t)) {
			cout << "YES\n";
			return;
		}

		t = s.substr(i - 1, 2);
		mp[t]++;
	}


	cout << "NO\n";
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