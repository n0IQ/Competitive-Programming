#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// B-S-C
ll have[3];
ll req[3];
ll price[3];

bool check(ll target, ll rubles)
{
	ll moneySpent = 0;
	for (int i = 0; i < 3; i++) {
		ll need = max(0LL, (req[i] * target) - have[i]);
		moneySpent += (need * price[i]);
	}
	return moneySpent <= rubles;
}

void solve()
{
	string s;
	cin >> s;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == 'B') req[0]++;
		else if (s[i] == 'S') req[1]++;
		else req[2]++;
	}

	for (int i = 0; i < 3; i++) {
		cin >> have[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> price[i];
	}

	ll rubles;
	cin >> rubles;

	ll l = 1, r = 1e15, ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;

		if (check(mid, rubles)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
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
	// cin >> t;
	while (t--) solve();

	return 0;
}