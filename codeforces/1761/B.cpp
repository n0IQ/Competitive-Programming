#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	set<int> s;

	for (auto &x : a) {
		cin >> x;
		s.insert(x);
	}

	if (n <= 3) {
		cout << n << '\n';
		return;
	}

	if (s.size() == 2) cout << (n / 2) + 1 << '\n';
	else cout << n << '\n';
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