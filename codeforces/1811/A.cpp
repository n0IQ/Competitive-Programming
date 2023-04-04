#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, d;
	string s;
	cin >> n >> d >> s;

	char ch = (char)('0' + d);

	for (int i = 0; i < n; i++) {
		if (ch > s[i]) {
			s.insert(s.begin() + i, ch);
			cout << s << '\n';
			return;
		}
	}

	s.push_back(ch);
	cout << s << '\n';
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