#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	ll aliceW = 0, aliceB = 0, bobW = 0, bobB = 0, cards = 0;
	int aliceTurn = 1, cnt = 1, lastCard = 1; // White = 0, Black = 1

	for (ll i = 1; ; i++) {
		if (cards + i <= n) {
			ll W = i / 2, B = i / 2;
			if (i % 2 == 1) {
				if (lastCard) W++;
				else B++;
				lastCard ^= 1;
			}

			if (aliceTurn) {
				aliceW += W;
				aliceB += B;
			}
			else {
				bobW += W;
				bobB += B;
			}

			cards += i;
		}
		else {
			ll rem = n - cards;
			ll W = rem / 2, B = rem / 2;

			if (rem % 2 == 1) {
				if (lastCard) W++;
				else B++;
				lastCard ^= 1;
			}

			if (aliceTurn) {
				aliceW += W;
				aliceB += B;
			}
			else {
				bobW += W;
				bobB += B;
			}

			break;
		}

		cnt++;
		if (cnt == 2) {
			aliceTurn ^= 1;
			cnt = 0;
		}
	}

	vector<ll> ans = {aliceW, aliceB, bobW, bobB};
	for (auto &x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
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