#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll cnt[])
{
	for (int i = 1; i < 26; i++) {
		if (cnt[i] > 0) return false;
	}
	return true;
}

void solve()
{
	int q;
	cin >> q;

	ll cnt1[26], cnt2[26];
	for (int i = 0; i < 26; i++) {
		cnt1[i] = cnt2[i] = 0;
	}
	cnt1[0] = cnt2[0] = 1;

	while (q--) {
		ll d, k;
		string s;
		cin >> d >> k >> s;

		ll temp[26] = {0};
		for (auto &ch : s) {
			temp[ch - 'a']++;
		}

		if (d == 1) {
			for (int i = 0; i < 26; i++) {
				cnt1[i] += (temp[i] * 1LL * k);
			}
		}
		else {
			for (int i = 0; i < 26; i++) {
				cnt2[i] += (temp[i] * 1LL * k);
			}
		}

		bool ok1 = check(cnt1);
		bool ok2 = check(cnt2);

		if (ok1 && ok2) {
			if (cnt1[0] < cnt2[0]) cout << "YES\n";
			else cout << "NO\n";
		}
		else if (ok1) {
			cout << "YES\n";
		}
		else if (ok2) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
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
	cin >> t;
	while (t--) solve();

	return 0;
}