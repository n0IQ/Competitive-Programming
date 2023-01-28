#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	map<int, int> minPos, maxPos;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (minPos.find(x) == minPos.end()) minPos[x] = i;
		maxPos[x] = i;
	}

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		if (minPos.count(a) && maxPos.count(b) && minPos[a] <= maxPos[b]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
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
	cin >> t;
	while (t--) solve();

	return 0;
}