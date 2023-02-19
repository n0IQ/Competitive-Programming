#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());

	vector<ll> b;
	for (int i = 0; i < n && (int)b.size() < k; i++) {
		if (b.empty()) b.push_back(a[i]);
		else if (b.back() != a[i]) b.push_back(a[i]);
	}

	ll mex = 0;
	for (auto &x : b) {
		if (mex == x) mex++;
		else break;
	}

	cout << mex << '\n';
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