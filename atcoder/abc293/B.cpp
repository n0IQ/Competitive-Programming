#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	vector<bool> visited(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			visited[a[i]] = 1;
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			ans.push_back(i);
		}
	}

	cout << (int)ans.size() << '\n';
	for (auto &i : ans) {
		cout << i << ' ';
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