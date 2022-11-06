#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll helper(int n, string &s, char ch)
{
	ll len = 0;
	for (int i = 0; i < n; i++) {
		ll temp = 0;
		while (i < n && s[i] == ch) {
			temp++, i++;
		}

		len = max(len, temp);
	}

	return len * len;
}

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	ll mx1 = helper(n, s, '1');
	ll mx2 = helper(n, s, '0');
	ll mx3 = 0;

	ll cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cnt1 += (s[i] == '0');
		cnt2 += (s[i] == '1');
	}

	mx3 = cnt1 * cnt2;

	cout << max({mx1, mx2, mx3}) << '\n';
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