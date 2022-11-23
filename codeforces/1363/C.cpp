#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[1010];
int n, x, moves;

int dfs(int u, int p)
{
	int cnt = 0;
	for (auto &v : adj[u]) {
		if (v != p) {
			int sub = dfs(v, u);
			if (u == x) {
				moves += (sub - 1);
			}
			else {
				cnt += sub;
			}
		}
	}
	return cnt + 1;
}

void solve()
{
	cin >> n >> x;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
	}

	int deg = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (u == x || v == x) deg++;
	}

	if (n <= 2 || deg <= 1) {
		cout << "Ayush\n";
		return;
	}

	moves = 0;
	dfs(x, -1);

	if (moves % 2 == 0) { // aayush move
		if (adj[x].size() % 2) cout << "Ayush\n";
		else cout << "Ashish\n";
	}
	else { // ashish move
		if (adj[x].size() % 2) cout << "Ashish\n";
		else cout << "Ayush\n";
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