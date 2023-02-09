#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << "No\n";
		return;
	}

	vector<pair<int, int>> ans;
	set<int> s;
	for (int i = 1; i <= n * 2; i++) s.insert(i);
	int cnt = n / 2 + 1, l = 1, r = n * 2;

	for (int i = 0; i < cnt; i++) {
		s.erase(l);
		s.erase(r);
		ans.push_back({l, r});
		l++, r -= 2;
	}

	vector<int> rem(s.begin(), s.end());
	int sz = (int)rem.size();

	for (int i = 0; i < sz / 2; i++) {
		ans.push_back({rem[i], rem[sz - i - 1]});
	}

	cout << "Yes\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
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