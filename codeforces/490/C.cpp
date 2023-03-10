#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll a, b;
vector<ll> suffix;

ll binpow(ll a, ll b, ll m)
{
	ll res = 1;
	a %= m;

	while (b) {
		if (b & 1) {
			res = (res * a) % m;
		}

		a = (a * a) % m;
		b /= 2;
	}

	return res;
}

void solve()
{
	cin >> s >> a >> b;

	int n = (int)s.size();
	suffix.resize(n, -1);

	ll val = 0;
	string t;

	for (int i = n - 1; i >= 0 ; i--) {
		val = ((s[i] - '0') * binpow(10LL, n - i - 1, b) + val) % b;
		suffix[i] = val;
	}

	/*for (auto &x : suffix) cout << x << ' ';
	cout << '\n';*/

	int partitionIndex = -1;
	val = 0;
	for (int i = 0; i < n - 1; i++) {
		val = (val * 10LL + (s[i] - '0')) % a;

		if (val == 0) {
			while (i < n - 1 && s[i + 1] == '0') i++;
			if (i >= n - 1) break;
			if (suffix[i + 1] == 0) {
				partitionIndex = i;
				break;
			}
		}
	}

	// cout << "idx: " << partitionIndex << '\n';

	if (partitionIndex == -1) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	cout << s.substr(0, partitionIndex + 1) << '\n';
	cout << s.substr(partitionIndex + 1, n - (partitionIndex + 1)) << '\n';
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