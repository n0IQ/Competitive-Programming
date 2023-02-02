#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define set_bits __builtin_popcountll

int n, k;
string a, b;

ll getPairs(vector<char> &arr, int mask)
{
	// cout << mask << '\n';
	ll ans = 0, l = 0;
	for (int i = 0; i < n; i++) {
		int idx = (int)(find(arr.begin(), arr.end(), a[i]) - arr.begin());
		// cout << a[i] << ' ' << idx << '\n';
		if (a[i] == b[i] || (mask & (1 << idx))) l++;
		else l = 0;
		ans += l;
	}
	return ans;
}

ll helper(vector<char> &arr, int i, int sz, int mask)
{
	if (i == sz || set_bits(mask) == k) {
		return getPairs(arr, mask);
	}

	ll ans = helper(arr, i + 1, sz, mask);
	ans = max(ans, helper(arr, i + 1, sz, mask | (1 << i)));
	return ans;
}

void solve()
{
	cin >> n >> k >> a >> b;

	set<char> s;
	for (auto &ch : a) s.insert(ch);
	vector<char> arr(s.begin(), s.end());

	cout << helper(arr, 0, (int)s.size(), 0) << '\n';
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