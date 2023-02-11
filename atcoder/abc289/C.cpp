#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<int>> sets;

ll helper(int i, vector<int> &visited)
{
	if (i == m) {
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) {
				flag = 0;
				break;
			}
		}
		return flag;
	}

	ll ans = helper(i + 1, visited);
	for (auto &x : sets[i]) {
		visited[x]++;
	}
	ans += helper(i + 1, visited);
	for (auto &x : sets[i]) {
		visited[x]--;
	}

	return ans;
}

void solve()
{
	cin >> n >> m;
	sets.resize(m);

	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int x;
			cin >> x;
			sets[i].push_back(x);
		}
	}

	/*for (int i = 0; i < m; i++) {
		for (auto &x : sets[i]) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	cout << '\n';*/

	vector<int> visited(n + 10, 0);
	cout << helper(0, visited) << '\n';
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