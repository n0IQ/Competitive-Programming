#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q;
	cin >> n >> q;

	set<int> notCalled, called, visited;

	for (int i = 1; i <= n; i++) notCalled.insert(i);

	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;

		if (t == 1) {
			int id = *notCalled.begin();
			notCalled.erase(notCalled.begin());
			if (!visited.count(id)) {
				called.insert(id);
			}
		}
		else if (t == 2) {
			int x;
			cin >> x;
			visited.insert(x);
			called.erase(x);
		}
		else {
			cout << *called.begin() << '\n';
		}
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