#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<vector<int>> adj(n);

	for (int i = 0; i < n; i++) {
		vector<int> a(n - 1);
		for (int j = 0; j < n - 1; j++) {
			cin >> a[j];
		}
		adj[i] = a;
	}

	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[adj[i][0]]++;
	}

	int x = 0, cnt = 0;
	for (auto &it : mp) {
		if (it.second > cnt) {
			cnt = it.second;
			x = it.first;
		}
	}

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (adj[i][0] != x) {
			ans = adj[i];
			break;
		}
	}

	ans.insert(ans.begin(), x);
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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