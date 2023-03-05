#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	transform(s.begin(), s.end(), s.begin(), ::tolower);
	vector<char> a = {'m', 'e', 'o', 'w'};
	int j = 0;

	for (int i = 0; i < n; i++) {
		if (j >= 4) {
			cout << "NO\n";
			return;
		}
		if (s[i] == a[j]) {
			while (i < n && s[i] == a[j]) i++;
			i--;
		}
		else {
			cout << "NO\n";
			return;
		}
		j++;
	}

	if (j == 4) cout << "YES\n";
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