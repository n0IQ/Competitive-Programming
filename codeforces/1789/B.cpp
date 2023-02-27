#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	int l = 0, r = n - 1, cnt = 0;

	while (l <= r) {
		if (s[l] != s[r]) {
			while (l <= r && s[l] != s[r]) {
				l++, r--;
			}
			cnt++;
		}
		l++, r--;
	}

	if (cnt <= 1) cout << "Yes\n";
	else cout << "No\n";
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