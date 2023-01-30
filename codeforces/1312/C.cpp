#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	set<ll> powers;
	__int128 p = 1;
	while (p <= (ll)1e16) {
		powers.insert(p);
		p *= k;
	}

	for (int i = 0; i < n && !powers.empty(); i++) {
		while (a[i] > 0 && !powers.empty()) {
			auto it = powers.upper_bound(a[i]);
			if(it == powers.begin()) break;
			it--;
			a[i] -= (*it);
			powers.erase(it);
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			cout << "NO\n";
			return;
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