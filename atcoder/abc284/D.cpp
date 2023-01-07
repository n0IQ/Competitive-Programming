#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	ll n;
	cin >> n;

	ll a = -1, b = -1;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			int cnt = 0;

			while (n % i == 0) {
				n /= i;
				cnt++;
			}

			if (cnt == 2) a = i;
			else b = i;
			break;
		}
	}

	if (a == -1) {
		a = sqrtl(n);
	}
	else if (b == -1) {
		b = n;
	}

	cout << a << ' ' << b << '\n';
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