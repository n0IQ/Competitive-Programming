#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	vector<int> cnt(26, 0);
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}

	vector<pair<int, int>> v(26);
	for (int i = 0; i < 26; i++) {
		v[i] = {cnt[i], i};
	}
	sort(v.rbegin(), v.rend());

	vector<int> oldCnt = cnt;
	int minDiff = n + 10;
	string ans;

	for (int k = 1; k <= 26; k++) {
		if (n % k != 0) continue;

		cnt = oldCnt;
		vector<int> reqCnt(26, 0);

		for (int i = 0; i < k; i++) {
			reqCnt[v[i].second] = n / k;
		}

		int j = 0, diff = 0;
		string t = s;

		for (int i = 0; i < n; i++) {
			int ch = s[i] - 'a';
			if (cnt[ch] <= reqCnt[ch]) continue;
			while (j < 26 && cnt[j] >= reqCnt[j]) j++;

			diff++;
			t[i] = 'a' + j;
			cnt[j]++;
			cnt[ch]--;
		}

		if (diff < minDiff) {
			minDiff = diff;
			ans = t;
		}
	}

	cout << minDiff << '\n';
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
	cin >> t;
	while (t--) solve();

	return 0;
}