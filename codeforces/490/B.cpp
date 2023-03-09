#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;

void helper(vector<int> &ans, int n, map<int, int> &next, map<int, int> &pos, int prev)
{
	for (int i = next[prev]; pos[prev] < n - 2; ) {
		pos[i] = pos[prev] + 2;
		ans[pos[i]] = i;
		prev = i;
		i = next[i];
		if (i == 0) break;
	}
}

void solve()
{
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	vector<int> cnt(MAXN + 10, 0);
	map<int, int> next, pos;

	int secondPerson = 0;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
		cnt[x]++, cnt[y]++;
		if (x == 0) secondPerson = y;
		next[x] = y;
	}

	int firstPerson = 0, lastPerson = 0;
	for (int i = 1; i <= MAXN; i++) {
		if (cnt[i] == 1 && firstPerson == 0) firstPerson = i;
		else if (cnt[i] == 1 && lastPerson == 0) lastPerson = i;
	}

	for (auto &i : a) {
		if (i.first == lastPerson) {
			swap(firstPerson, lastPerson);
			break;
		}
	}

	vector<int> ans(n, 0);
	ans[0] = firstPerson, ans[n - 1] = lastPerson;
	pos[firstPerson] = 0, pos[lastPerson] = n - 1;
	helper(ans, n, next, pos, firstPerson);

	/*for (auto &i : next) {
		cout << i.first << ' ' << i.second << '\n';
	}*/

	ans[1] = secondPerson, pos[secondPerson] = 1;
	helper(ans, n, next, pos, secondPerson);

	for (auto &i : ans) {
		cout << i << ' ';
	}
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