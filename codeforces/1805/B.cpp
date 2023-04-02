#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	char minC = s[0];
	int idx = 0;

	for (int i = 1; i < n; i++) {
		if (s[i] <= minC) {
			idx = i;
			minC = s[i];
		}
	}

	string ans;
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		ans.push_back(s[i]);
	}
	ans.insert(ans.begin(), minC);

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