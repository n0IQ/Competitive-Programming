#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	for (int x = 0; x <= 1000; x++) {
		int ok = 0, cnt = 0, sum = 0;

		for (int i = 0; i < n; i++) {
			int val = (s[i] - '0');

			if (sum + val <= x) {
				sum += val;

				if (sum == x) {
					cnt++;
					sum = 0;
				}
			}
			else {
				ok = 1;
				break;
			}
		}

		if (!ok && sum == 0 && cnt >= 2) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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