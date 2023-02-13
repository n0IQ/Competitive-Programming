#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	string s;
	cin >> n >> s;

	s = "#" + s;

	vector<ll> pref(n + 10, 0), suff(n + 10, 0);
	set<char> st;

	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1];
		if (!st.count(s[i])) pref[i]++;
		st.insert(s[i]);
	}

	st.clear();
	for (int i = n; i >= 1; i--) {
		suff[i] = suff[i + 1];
		if (!st.count(s[i])) suff[i]++;
		st.insert(s[i]);
	}

	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ans = max(ans, pref[i] + suff[i + 1]);
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