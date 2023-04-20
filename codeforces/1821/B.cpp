#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	int startIdx = 0, endIdx = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			startIdx = i;
			break;
		}
	}

	for (int i = n - 1; i >= startIdx; i--) {
		if (a[i] != b[i]) {
			endIdx = i;
			break;
		}
	}

	int minVal = INT_MAX, maxVal = 0;
	for (int i = startIdx; i <= endIdx; i++) {
		minVal = min(minVal, a[i]);
		maxVal = max(maxVal, a[i]);
	}

	for (int i = startIdx - 1; i >= 0; i--) {
		if (a[i] <= minVal) {
			startIdx = i;
			minVal = min(minVal, a[i]);
		}
		else break;
	}

	for (int i = endIdx + 1; i < n; i++) {
		if (a[i] >= maxVal) {
			endIdx = i;
			maxVal = max(maxVal, a[i]);
		}
		else break;
	}

	cout << startIdx + 1 << ' ' << endIdx + 1 << '\n';
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