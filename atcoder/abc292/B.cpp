#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<ll> cards(n + 1, 0);
	for (int i = 0; i < q; i++) {
		int t, x;
		cin >> t >> x;

		if (t == 1) cards[x]++;
		else if (t == 2) cards[x] += 2;
		else {
			if (cards[x] >= 2) cout << "Yes\n";
			else cout << "No\n";
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