#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	ll aliceCards = 0, bobCards = 0, cards = 0;
	int aliceTurn = 1, cnt = 1, lastCard = 1;

	for (ll i = 1; ; i++) {
		if (cards + i <= n) {
			if (aliceTurn) aliceCards += i;
			else bobCards += i;
			cards += i;
		}
		else {
			ll rem = n - cards;
			if (aliceTurn) aliceCards += rem;
			else bobCards += rem;
			break;
		}

		cnt++;
		if (cnt == 2) {
			aliceTurn ^= 1;
			cnt = 0;
		}
	}

	cout << aliceCards << ' ' << bobCards << '\n';
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