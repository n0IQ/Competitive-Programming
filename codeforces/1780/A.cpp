#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n);
	vector<int> cnt(2, 0);
	vector<int> idx[2];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i] % 2]++;
		idx[a[i] % 2].push_back(i);
	}

	if (cnt[0] >= 2 && cnt[1] >= 1) {
		cout << "YES\n";
		cout << idx[0][0] + 1 << ' ' << idx[0][1] + 1 << ' ' << idx[1][0] + 1 << '\n';
	}
	else if (cnt[1] >= 3) {
		cout << "YES\n";
		cout << idx[1][0] + 1 << ' ' << idx[1][1] + 1 << ' ' << idx[1][2] + 1 << '\n';
	}
	else cout << "NO\n";
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