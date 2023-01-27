#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string PI = "314159265358979323846264338327";

void solve()
{
	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == PI[i]) ans++;
		else break;
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