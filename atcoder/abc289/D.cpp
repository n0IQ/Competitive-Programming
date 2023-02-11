#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, x;
vector<ll> a;
set<ll> s;
ll dp[1000000];

bool helper(int steps)
{
	if (steps == x) {
		return true;
	}
	if (dp[steps] != -1) {
		return dp[steps];
	}

	bool isPossible = false;
	for (int i = 0; i < n; i++) {
		if ((steps + a[i] <= x) && !s.count(steps + a[i])) {
			isPossible |= helper(steps + a[i]);
		}
	}

	return dp[steps] = isPossible;
}

void solve()
{
	cin >> n;

	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		ll b;
		cin >> b;
		s.insert(b);
	}

	cin >> x;

	memset(dp, -1, sizeof(dp));
	bool isPossible = helper(0);

	if (isPossible) cout << "Yes\n";
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
	// cin >> t;
	while (t--) solve();

	return 0;
}