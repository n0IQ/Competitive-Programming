#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1, vector<int> (m + 1, 0));
	int totalCount = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> adj[i][j];
			totalCount += (adj[i][j] == 1);
		}
	}

	if (totalCount % n != 0) {
		cout << "-1\n";
		return;
	}

	set<int> pos[m + 1];
	map<int, int> count;
	int reqCount = totalCount / n;

	for (int i = 1; i <= n; i++) {
		int currOnes = accumulate(adj[i].begin(), adj[i].end(), 0);
		count[i] = currOnes;

		if (currOnes > reqCount) {
			for (int j = 1; j <= m; j++) {
				if (adj[i][j]) {
					pos[j].insert(i);
				}
			}
		}
	}

	int ops = 0;
	vector<array<int, 3>> ans;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m && count[i] < reqCount; j++) {
			if (adj[i][j] == 0) {
				while (!pos[j].empty() && count[*pos[j].begin()] <= reqCount) {
					pos[j].erase(pos[j].begin());
				}

				if (!pos[j].empty()) {
					ops++;
					ans.push_back({i, *pos[j].begin(), j});
					count[i]++;
					count[*pos[j].begin()]--;
					pos[j].erase(pos[j].begin());
				}
			}
		}
	}

	cout << (int)ans.size() << '\n';
	for (auto &arr : ans) {
		cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
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