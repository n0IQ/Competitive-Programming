#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	set<int> s(a.begin(), a.end());
	for (int i = 0, j = n - 1; i <= j; ) {
		int minX = *s.begin(), maxX = *prev(s.end());

		if (a[i] == minX || a[j] == minX) {
			s.erase(s.begin());
			if (a[i] == minX) i++;
			else j--;
		}
		else if (a[i] == maxX || a[j] == maxX) {
			s.erase(prev(s.end()));
			if (a[i] == maxX) i++;
			else j--;
		}
		else {
			cout << i + 1 << ' ' << j + 1 << '\n';
			return;
		}
	}

	cout << "-1\n";
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