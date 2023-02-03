#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;

	for (char ch = 'a'; ch <= 'e'; ch++) {
		priority_queue<int> pq;

		for (auto &s : arr) {
			int count = 0;
			for (auto &c : s) {
				count += (c == ch);
			}
			pq.push(count - ((int)s.size() - count));
		}

		int stories = 0, count = 0;
		while (!pq.empty()) {
			int delta = pq.top();
			pq.pop();

			if (count + delta > 0) {
				count += delta;
				stories++;
			}
			else break;
		}

		ans = max(ans, stories);
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