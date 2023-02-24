#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	cin >> s;

	int n = (int)s.size();

	if (n == 1) {
		cout << "YES\n";
		for (char ch = 'a'; ch <= 'z'; ch++) {
			cout << ch;
		}
		cout << '\n';
		return;
	}

	vector<int> adj[26];
	vector<bool> visited(26, 0);
	visited[s[0] - 'a'] = 1;

	for (int i = 0; i < n - 1; i++) {
		int u = s[i] - 'a', v = s[i + 1] - 'a';
		if (visited[v]) {
			bool found = false;
			for (auto &x : adj[u]) {
				if (x == v) found = true;
			}

			if (!found) {
				cout << "NO\n";
				return;
			}
		}
		else {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		visited[v] = 1;
	}

	for (int i = 0; i < 26; i++) {
		if (adj[i].size() > 2) {
			cout << "NO\n";
			return;
		}
	}

	fill(visited.begin(), visited.end(), 0);
	string ans;

	for (int i = 0; i < n; i++) {
		int curr = s[i] - 'a';

		if (visited[curr]) {
			if (adj[curr].size() == 2) {
				int idxCurr = ans.find('a' + curr);
				int idxU = ans.find('a' + adj[curr][0]);
				int idxV = ans.find('a' + adj[curr][1]);
				/*cout << "idx: " << curr << ' ' << idxCurr << '\n';
				cout << "idx: " << adj[curr][0] << ' ' << idxU << '\n';
				cout << "idx: " << adj[curr][1] << ' ' << idxV << '\n';*/

				if (idxU == -1) {
					if (idxCurr == 0) ans.insert(ans.begin(), 'a' + adj[curr][0]);
					else ans.push_back('a' + adj[curr][0]);
					visited[adj[curr][0]] = 1;
				}
				if (idxV == -1) {
					if (idxCurr == 0) ans.insert(ans.begin(), 'a' + adj[curr][1]);
					else ans.push_back('a' + adj[curr][1]);
					visited[adj[curr][1]] = 1;
				}
			}
		}
		else {
			ans.push_back('a' + curr);
			ans.push_back('a' + adj[curr][0]);
			visited[curr] = 1;
			visited[adj[curr][0]] = 1;

			if (adj[curr].size() == 2) {
				ans.insert(ans.begin(), ('a' + adj[curr][1]));
				visited[adj[curr][1]] = 1;
			}
		}

		// cout << ans << '\n';
	}

	for (int i = 0; i < 26; i++) {
		if (!visited[i]) ans.push_back('a' + i);
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