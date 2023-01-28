#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	string s;
	int p;
	cin >> s >> p;

	int n = (int)s.size();
	vector<bool> visited(n, 0);

	vector<int> a[26];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		a[s[i] - 'a'].push_back(i);
		sum += (s[i] - 'a' + 1);
	}

	for (int i = 25; i >= 0 && sum > p; i--) {
		while (!a[i].empty() && sum > p) {
			sum -= (i + 1);
			visited[a[i].back()] = 1;
			a[i].pop_back();
		}
	}

	string ans;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ans.push_back(s[i]);
		}
	}

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