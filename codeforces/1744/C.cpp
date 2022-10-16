#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	char ch;
	string s;
	cin >> n >> ch >> s;

	int ans = 0;

	for (int i = 0; i < n; ) {
		if (s[i] == ch) {
			int j = i;
			while (j < n && s[j] != 'g') {
				j++;
			}

			if (j == n) {
				int temp = j - i;

				for (j = 0; j < n; j++) {
					if (s[j] == 'g') {
						temp += j;
						break;
					}
				}

				ans = max(ans, temp);
				break;
			}
			else {
				ans = max(ans, j - i);
				i = j;
			}
		}

		i++;
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
	cin >> t;
	while (t--) solve();

	return 0;
}