#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, sx, sy, ex, ey, bounce, isPossible, flip;
string startDir;
int row[30000], col[30000];

void dfs(int x, int y, string &dir)
{
	if (flip > 2 || isPossible == 1 || row[x] > 1e5 || col[y] > 1e5) return;
	if (x == ex && y == ey) {
		isPossible = 1;
		return;
	}

	row[x]++, col[y]++;

	if ((x == 1 || x == n) && (y == 1 || y == m)) {
		bounce++;
		if (y == 1 || y == m) {
			flip++;
			dir[0] = (dir[0] == 'U' ? 'D' : 'U');
			dir[1] = (dir[1] == 'L' ? 'R' : 'L');
		}
		else {
			dir[0] = (dir[0] == 'U' ? 'D' : 'U');
		}
	}
	else if (x == 1 || x == n) {
		bounce++;
		dir[0] = (dir[0] == 'U' ? 'D' : 'U');
	}
	else if (y == 1 || y == m) {
		bounce++;
		dir[1] = (dir[1] == 'L' ? 'R' : 'L');
	}

	if (dir[0] == 'U') {
		if (dir[1] == 'L') dfs(x - 1, y - 1, dir);
		else dfs(x - 1, y + 1, dir);
	}
	else {
		if (dir[1] == 'L') dfs(x + 1, y - 1, dir);
		else dfs(x + 1, y + 1, dir);
	}
}

void solve()
{
	cin >> n >> m >> sx >> sy >> ex >> ey >> startDir;
	bounce = isPossible = flip = 0;
	for (int i = 0; i <= n; i++) row[i] = 0;
	for (int i = 0; i <= m; i++) col[i] = 0;

	if (sx == ex && sy == ey) {
		cout << bounce << '\n';
		return;
	}

	if (sx == 1 && sy == 1) {
		if (startDir[0] == 'U' || startDir[1] == 'L') bounce = 1;
		startDir = "DR";
		sx = 2, sy = 2;
	}
	else if (sx == n && sy == 1) {
		if (startDir[0] == 'D' || startDir[1] == 'L') bounce = 1;
		startDir = "UR";
		sx = n - 1, sy = 2;
	}
	else if (sx == 1 && sy == m) {
		if (startDir[0] == 'U' || startDir[1] == 'R') bounce = 1;
		startDir = "DL";
		sx = 2, sy = m - 1;
	}
	else if (sx == n && sy == m) {
		if (startDir[0] == 'D' || startDir[1] == 'R') bounce = 1;
		startDir = "UL";
		sx = n - 1, sy = m - 1;
	}
	else if (sx == 1) {
		if (startDir[0] == 'U') {
			bounce++;
			startDir[0] = 'D';
		}
		sx = 2;
		sy = (startDir[1] == 'L' ? sy - 1 : sy + 1);
	}
	else if (sx == n) {
		if (startDir[0] == 'D') {
			bounce++;
			startDir[0] = 'U';
		}
		sx = n - 1;
		sy = (startDir[1] == 'L' ? sy - 1 : sy + 1);
	}
	else if (sy == 1) {
		if (startDir[1] == 'L') {
			bounce++;
			startDir[1] = 'R';
		}
		sx = (startDir[0] == 'U' ? sx - 1 : sx + 1);
		sy = 2;
	}
	else if (sy == m) {
		if (startDir[1] == 'R') {
			bounce++;
			startDir[1] = 'L';
		}
		sx = (startDir[0] == 'U' ? sx - 1 : sx + 1);
		sy = m - 1;
	}

	// cout << sx << ' ' << sy << ' ' << startDir << '\n';

	dfs(sx, sy, startDir);

	if (isPossible) cout << bounce << '\n';
	else cout << "-1\n";
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