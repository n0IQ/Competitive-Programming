#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	int sum = s[0] - '0';
	for (int i = 1; i < n; i++) {
		if (sum == 0) {
			cout << '+';
			sum += (s[i] - '0');
		}
		else {
			cout << '-';
			sum -= (s[i] - '0');
		}
	}

	cout << '\n';
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