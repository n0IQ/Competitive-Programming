#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, w, h;

int check(vector<pair<ll, ll>> &cake, vector<pair<ll, ll>> &choco, ll delta)
{
	for (int i = 0, j = 0; i < n && j < n; i++, j++) {
		ll w1 = cake[j].first + delta, w2 = cake[j].second + delta;
		ll h1 = choco[i].first, h2 = choco[i].second;

		if (h1 >= w1 && h2 <= w2) {
			continue;
		}
		else {
			if (w1 > h1) return -1;
			return 1;
		}
	}

	return 0;
}

void solve()
{
	cin >> n >> w >> h;

	vector<pair<ll, ll>> cake(n), choco(n);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		cake[i] = {x - w, x + w};
	}

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		choco[i] = {x - h, x + h};
	}

	sort(cake.begin(), cake.end());
	sort(choco.begin(), choco.end());

	ll l = -1e15, r = 1e15;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		ll res = check(cake, choco, mid);

		if (res == 0) {
			cout << "YES\n";
			return;
		}
		else if (res == 1) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << "NO\n";
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