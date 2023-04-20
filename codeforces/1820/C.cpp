#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getMex(vector<ll> a, int n)
{
	set<ll> s(a.begin(), a.end());
	ll mex = 0;
	while (!s.empty()) {
		if (*s.begin() == mex) mex++;
		else break;
		s.erase(s.begin());
	}

	return mex;
}

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	map<ll, ll> mp;
	for (auto &x : a) {
		cin >> x;
		mp[x]++;
	}

	if (n == 1) {
		if (a[0] == 0) cout << "No\n";
		else cout << "Yes\n";
		return;
	}

	ll currMex = getMex(a, n);
	ll reqMex = currMex + 1;

	// cout << currMex << ' ';

	bool isPresent = false;
	if (mp.count(reqMex)) isPresent = true;

	if (isPresent) {
		int startIdx = n, endIdx = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == reqMex) {
				startIdx = min(startIdx, i);
				endIdx = max(endIdx, i);
			}
		}

		for (int i = startIdx; i <= endIdx; i++) {
			a[i] = currMex;
		}

		ll mex = getMex(a, n);
		if (mex == reqMex) cout << "Yes\n";
		else cout << "No\n";
	}
	else {
		bool ok = false;
		for (int i = 0; i < n; i++) {
			if (a[i] > currMex || mp[a[i]] > 1) ok = true;
		}

		if (ok) cout << "Yes\n";
		else cout << "No\n";
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