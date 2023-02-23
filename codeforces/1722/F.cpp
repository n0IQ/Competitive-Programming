#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[55][55];
set<pair<int, int>> s;
bool isPossible;


int getCount(int i, int j)
{
	return a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
}

bool check(int i, int j)
{
	bool conditions = true;
	if (a[i][j] && (a[i][j - 1] || a[i + 1][j - 1] || a[i - 1][j - 1] || a[i - 1][j] || a[i - 1][j + 1])) conditions = false;
	if (a[i][j + 1] && (a[i][j + 2] || a[i + 1][j + 2] || a[i - 1][j + 2] || a[i - 1][j + 1] || a[i - 1][j])) conditions = false;
	if (a[i + 1][j] && (a[i][j - 1] || a[i + 1][j - 1] || a[i + 2][j - 1] || a[i + 2][j] || a[i + 2][j + 1])) conditions = false;
	if (a[i + 1][j + 1] && (a[i + 2][j] || a[i + 2][j + 1] || a[i + 2 ][j + 2] || a[i + 1][j + 2] || a[i][j + 2])) conditions = false;

	if (a[i][j]) s.erase({i, j});
	if (a[i][j + 1]) s.erase({i, j + 1});
	if (a[i + 1][j]) s.erase({i + 1, j});
	if (a[i + 1][j + 1]) s.erase({i + 1, j + 1});

	return conditions;
}

void solve()
{
	isPossible = true;
	for (int i = 0; i <= 52; i++) {
		for (int j = 0; j <= 52; j++) {
			a[i][j] = 0;
		}
	}
	s.clear();

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char ch;
			cin >> ch;
			a[i][j] = (ch == '*');
			if (a[i][j]) s.insert({i, j});
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cnt = getCount(i, j);
			if (cnt == 4) {
				isPossible = false;
				break;
			}
			if (cnt == 3) {
				bool ok = check(i, j);
				isPossible &= ok;
			}
		}

		if (!isPossible) break;
	}

	if (isPossible && s.empty()) cout << "YES\n";
	else cout << "NO\n";
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