#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s, ans;
	cin >> n >> s;

	s.push_back('#');

	for (int i = 0; i < n; i++) {
		if (s[i] == 'n' && s[i + 1] == 'a') {
			ans += "nya";
			i++;
		}
		else ans.push_back(s[i]);
	}

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
	// cin >> t;
	while (t--) solve();

	return 0;
}