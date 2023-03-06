#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPalindrome(string s)
{
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n - i - 1]) return false;
	}
	return true;
}

void solve()
{
	int n;
	cin >> n;

	vector<string> a(n * 2 - 2);
	int max_size = 0;
	for (int i = 0; i < n * 2 - 2; i++) {
		cin >> a[i];
		max_size = max(max_size, (int)a[i].size());
	}

	string pref, suff;
	for (auto &s : a) {
		if ((int)s.size() == max_size) {
			if (pref.empty()) pref = s;
			else suff = s;
		}
	}

	if (isPalindrome(pref + suff) || isPalindrome(suff + pref)) cout << "YES\n";
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