#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	char arr[8][8];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}

	for (int j = 7; j >= 0; j--) {
		bool ok = 1;
		for (int i = 0; i < 8; i++) {
			if (arr[i][j] != 'B') {
				ok = 0;
				break;
			}
		}

		if (ok) {
			cout << "B\n";
			return;
		}
	}

	cout << "R\n";
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