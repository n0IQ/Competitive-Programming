#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size(), pos = 0;
	vector<bool> visited(26, 0);
	visited[s[0] - 'a'] = 1;
	string ans(1, s[0]);

	for (int i = 1; i < n; i++) {
		if (visited[s[i] - 'a']) {
			if (pos > 0 && ans[pos - 1] == s[i]) {
				pos--;
			}
			else if (pos < (int)ans.size() - 1 && ans[pos + 1] == s[i]) {
				pos++;
			}
			else {
				cout << "NO\n";
				return;
			}
		}
		else {
			if (pos == 0) {
				ans = s[i] + ans;
			}
			else if (pos == (int)ans.size() - 1) {
				ans.push_back(s[i]);
				pos++;
			}
			else {
				cout << "NO\n";
				return;
			}
		}
		visited[s[i] - 'a'] = 1;
	}

	for (int i = 0; i < 26; i++) {
		if (!visited[i]) ans.push_back(char('a' + i));
	}

	cout << "YES\n";
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