#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300000;
map<int, int> notificationNo;
set<int> app[MAXN + 1];

void solve()
{
	int n, m;
	cin >> n >> m;

	queue<array<int, 3>> q;
	int queueCount = 0, unreadTexts = 0;

	for (int i = 0; i < m; i++) {
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			q.push({x, ++notificationNo[x], ++queueCount});
			app[x].insert(notificationNo[x]);
			unreadTexts++;
		}
		else if (t == 2) {
			unreadTexts -= app[x].size();
			app[x].clear();
		}
		else {
			while (!q.empty() && q.front()[2] <= x) {
				auto v = q.front();
				q.pop();
				if (app[v[0]].count(v[1])) {
					app[v[0]].erase(v[1]);
					unreadTexts--;
				}
			}
		}

		cout << unreadTexts << '\n';
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
	// cin >> t;
	while (t--) solve();

	return 0;
}