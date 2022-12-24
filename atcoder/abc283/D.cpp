#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = s.size();

	vector<int> v;
	vector<char> adj[n + 1];
	map<char, int> mp;

	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			v.push_back(i);
		}
		else if (s[i] == ')') {
			int idx = v.back();

			for (auto ch : adj[idx]) {
				mp[ch]--;
			}
			adj[idx].clear();
			v.pop_back();
		}
		else {
			if (mp[s[i]] >= 1) {
				cout << "No\n";
				return;
			}
			int idx = (v.empty() ? -1 : v.back());
			adj[idx].push_back(s[i]);
			mp[s[i]]++;
		}
	}

	cout << "Yes\n";
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
	//cin >> t;
	while (t--) solve();

	return 0;
}