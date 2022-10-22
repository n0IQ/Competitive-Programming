#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> colorx[100010], colory[100010];

void solve()
{
	int n, m;
	cin >> n >> m;

	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			colorx[arr[i][j]].push_back(i);
			colory[arr[i][j]].push_back(j);
		}
	}

	ll ans = 0;
	for (int i = 0; i < 100010; i++) {
		int sz = (int)colorx[i].size();

		if (sz > 0) {
			sort(colorx[i].begin(), colorx[i].end());
			vector<ll> suff(sz, 0);
			suff[sz - 1] = colorx[i][sz - 1];

			for (int j = sz - 2; j >= 0; j--) {
				suff[j] = colorx[i][j] + suff[j + 1];
			}

			for (int j = 0; j < sz - 1; j++) {
				ans += suff[j] - (colorx[i][j] * (sz - j));
			}
		}

		sz = (int)colory[i].size();

		if (sz > 0) {
			sort(colory[i].begin(), colory[i].end());
			vector<ll> suff(sz, 0);
			suff[sz - 1] = colory[i][sz - 1];

			for (int j = sz - 2; j >= 0; j--) {
				suff[j] = colory[i][j] + suff[j + 1];
			}

			for (int j = 0; j < sz - 1; j++) {
				ans += suff[j] - (colory[i][j] * (sz - j));
			}
		}
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