#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, m;
	cin >> n >> m;

	set<int> s;
	vector<int> time(n + 1, -1);
	int val = n;

	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;

		if (!s.count(x)) {
			if (val >= 0 && time[val] == -1) {
				time[val] = i;
			}
			val--;
		}
		s.insert(x);
	}

	for (int i = 1; i <= n; i++) {
		cout << time[i] << ' ';
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