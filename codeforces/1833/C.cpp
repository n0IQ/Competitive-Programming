#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	ll minX = *min_element(a.begin(), a.end()), minVal = LLONG_MAX;

	for (auto &x : a) {
		if (x % 2) minVal = min(minVal, x);
	}

	for (auto &x : a) {
		if (x % 2 != minX % 2) {
			if (x - minVal <= 0) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
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