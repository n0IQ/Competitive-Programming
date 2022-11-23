#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<long, long>> adj[100010];
ll exor[100010];
map<ll, vector<ll>> mp;
int a, b, ans;

void getXor(int u, int p, ll x)
{
	for (auto &it : adj[u]) {
		ll v = it.first, w = it.second;

		if (v != p) {
			exor[v] = (exor[u] ^ w);
			getXor(v, u, x);
		}
	}
}

void dfs(int u, int p, ll x)
{
	if (u == b) {
		if (x == 0) ans = 1;
		return;
	}

	if (mp.count(x)) {
		for (auto it : mp[x]) {
			if (it != b) {
				ans = 1;
				break;
			}
		}

		if (ans) return;
	}

	for (auto &it : adj[u]) {
		ll v = it.first, w = it.second;
		if (v != p) {
			dfs(v, u, (x ^ w));
		}
	}
}

void solve()
{
	int n;
	cin >> n >> a >> b;

	for (int i = 0; i < n + 1; i++) {
		adj[i].clear();
		exor[i] = 0;
	}
	mp.clear();
	ans = 0;

	for (int i = 0; i < n - 1; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	getXor(b, -1, 0LL);
	for (int i = 1; i <= n; i++) {
		mp[exor[i]].push_back(i);
	}

	dfs(a, -1, 0LL);

	if (ans) cout << "YES\n";
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