#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	reverse(s.begin(), s.end());
	while (!s.empty() && s.back() == '0') s.pop_back();
	reverse(s.begin(), s.end());
	n = (int)s.size();

	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) cnt++;
	}

	cout << cnt << '\n';
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