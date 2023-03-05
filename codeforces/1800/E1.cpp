#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> p, r; // parent and rank array

	DSU(int n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		r.assign(n + 1, 1);
	}

	int find_set(int x)
	{
		if (x == p[x]) return x;
		return p[x] = find_set(p[x]);
	}

	bool union_set(int a, int b)
	{
		a = find_set(a); b = find_set(b);
		if (a == b) return false;
		if (r[a] < r[b]) swap(a, b);
		p[b] = a;
		r[a] += r[b];
		return true;
	}
};

void solve()
{
	int n, k;
	string s, t;
	cin >> n >> k >> s >> t;

	DSU dsu(n);

	for (int i = 0; i < n; i++) {
		if (i + k <= n - 1) dsu.union_set(i, i + k);
		if (i + k + 1 <= n - 1) dsu.union_set(i, i + k + 1);
	}

	vector<vector<int>> adj(n);
	for (int i = 0; i < n; i++) {
		adj[dsu.find_set(i)].push_back(i);
	}

	for (int i = 0; i < n; i++) {
		if (adj[i].empty()) continue;
		string s1, s2;
		for (auto &idx : adj[i]) {
			s1.push_back(s[idx]);
			s2.push_back(t[idx]);
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if (s1 != s2) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
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