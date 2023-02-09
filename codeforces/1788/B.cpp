#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	if (n % 2 == 0) {
		cout << n / 2 << ' ' << n / 2 << '\n';
		return;
	}
	else {
		string val1, val2;
		ll sum1 = 0, sum2 = 0;

		while (n) {
			ll d = n % 10;
			ll x = (d + 1) / 2, y = d / 2;

			if (sum1 <= sum2) {
				val1.push_back('0' + x);
				val2.push_back('0' + y);
				sum1 += x;
				sum2 += y;
			}
			else {
				val1.push_back('0' + y);
				val2.push_back('0' + x);
				sum1 += y;
				sum2 += x;
			}

			n /= 10;
		}

		reverse(val1.begin(), val1.end());
		reverse(val2.begin(), val2.end());

		cout << stoll(val1) << ' ' << stoll(val2) << '\n';
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