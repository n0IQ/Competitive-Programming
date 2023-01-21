#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
vector<ll> fact(100010);

void solve()
{
	ll n;
	cin >> n;

	if (n == 1) {
		cout << "0\n";
		return;
	}

	ll ans = ((fact[n] % MOD) * ((n * (n - 1)) % MOD)) % MOD;
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


	fact[0] = 1LL;
	for (ll i = 1; i <= 100000; i++) {
		fact[i] = ((i % MOD) * (fact[i - 1] % MOD)) % MOD;
	}

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}