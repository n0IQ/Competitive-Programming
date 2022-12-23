#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool helper(vector<vector<int>> adj, int m, int i, int j, char dir)
{
	if (adj[i][j] == 0) return false;

	while (j < m) {
		if (dir == 'U') {
			adj[i][j] = 0;
			if (adj[i - 1][j]) {
				i--;
				dir = 'R';
			}
			else if (adj[i][j + 1]) {
				j++;
				dir = 'U';
			}
			else break;
		}
		else if (dir == 'D') {
			adj[i][j] = 0;
			if (adj[i + 1][j]) {
				i++;
				dir = 'R';
			}
			else if (adj[i][j + 1]) {
				j++;
				dir = 'D';
			}
			else break;
		}
		else { // R
			adj[i][j] = 0;
			if (i == 0) {
				if (adj[i][j + 1]) {
					dir = 'D';
					j++;
				}
				else break;
			}
			else {
				if (adj[i][j + 1]) {
					dir = 'U';
					j++;
				}
				else break;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			if (adj[i][j] == 1) return false;
		}
	}

	return true;
}

void solve()
{
	int m;
	cin >> m;

	vector<vector<int>> adj(2, vector<int> (m + 1, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			adj[i][j] = (ch == 'B' ? 1 : 0);
		}
	}

	if (helper(adj, m, 0, 0, 'D') || helper(adj, m, 1, 0, 'U')) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
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