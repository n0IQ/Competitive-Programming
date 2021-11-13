#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

int a[200][200];
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 1, 0};
vector<int> adj[100000];
int t;

int get_count(int x, int y)
{
	int cnt = 0;
	rep(i, 0, 4) {
		cnt += a[x + dx[i]][y + dy[i]] == 1;
	}
	return cnt;
}

void helper1(int x, int y)
{
	int x1, x2, x3, x4, y1, y2, y3, y4, cnt = 0;
	rep(i, 0, 4) {
		if (a[x + dx[i]][y + dy[i]] == 1) {
			x1 = x + dx[i], y1 = y + dy[i];
		}
		else if (cnt == 0) {
			x2 = x + dx[i], y2 = y + dy[i];
			cnt++;
		}
		else if (cnt == 1) {
			x3 = x + dx[i], y3 = y + dy[i];
			cnt++;
		}
		else {
			x4 = x + dx[i], y4 = y + dy[i];
		}
	}

	adj[t].pb(x1), adj[t].pb(y1), adj[t].pb(x2), adj[t].pb(y2), adj[t].pb(x3), adj[t].pb(y3), t++;
	adj[t].pb(x1), adj[t].pb(y1), adj[t].pb(x2), adj[t].pb(y2), adj[t].pb(x4), adj[t].pb(y4), t++;
	adj[t].pb(x1), adj[t].pb(y1), adj[t].pb(x3), adj[t].pb(y3), adj[t].pb(x4), adj[t].pb(y4), t++;
}

void helper2(int x, int y)
{
	int x1, y1, x2, y2;
	vector<int> zeros;
	bool ok = 1;

	rep(i, 0, 4) {
		if (a[x + dx[i]][y + dy[i]] == 1) {
			if (ok) {
				ok = 0;
				x1 = x + dx[i], y1 = y + dy[i];
			}
			else {
				x2 = x + dx[i], y2 = y + dy[i];
			}
		}
		else {
			zeros.pb(x + dx[i]);
			zeros.pb(y + dy[i]);
		}
	}

	ok = 1;
	rep(i, 0, 2) {
		if (ok) {
			ok = 0;
			adj[t].pb(x1), adj[t].pb(y1);
		}
		else {
			adj[t].pb(x2), adj[t].pb(y2);
		}
		for (auto it : zeros) adj[t].pb(it);
		t++;
	}
}

void helper3(int x, int y)
{
	rep(i, 0, 4) {
		if (a[x + dx[i]][y + dy[i]] == 1) {
			adj[t].pb(x + dx[i]);
			adj[t].pb(y + dy[i]);
		}
	}

	t++;
}

void helper4(int x, int y)
{
	int x1, x2, x3, x4, y1, y2, y3, y4, cnt = 0;
	rep(i, 0, 4) {
		if (cnt == 0) x1 = x + dx[i], y1 = y + dy[i], cnt++;
		else if (cnt == 1) x2 = x + dx[i], y2 = y + dy[i], cnt++;
		else if (cnt == 2) x3 = x + dx[i], y3 = y + dy[i], cnt++;
		else x4 = x + dx[i], y4 = y + dy[i];
	}

	adj[t].pb(x1), adj[t].pb(y1), adj[t].pb(x2), adj[t].pb(y2), adj[t].pb(x3), adj[t].pb(y3), t++;
	adj[t].pb(x2), adj[t].pb(y2), adj[t].pb(x3), adj[t].pb(y3), adj[t].pb(x4), adj[t].pb(y4), t++;
	adj[t].pb(x1), adj[t].pb(y1), adj[t].pb(x2), adj[t].pb(y2), adj[t].pb(x4), adj[t].pb(y4), t++;
	adj[t].pb(x1), adj[t].pb(y1), adj[t].pb(x3), adj[t].pb(y3), adj[t].pb(x4), adj[t].pb(y4), t++;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	t = 0;
	rep(i, 0, 100000) {
		adj[i].clear();
	}
	mem0(a);

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			char c; cin >> c;
			c == '0' ? a[i][j] = 0 : a[i][j] = 1;
		}
	}

	rep(i, 1, n) {
		rep(j, 1, m) {
			int cnt = get_count(i, j);
			if (cnt == 0) continue;
			if (cnt == 1) helper1(i, j);
			else if (cnt == 2) helper2(i, j);
			else if (cnt == 3) helper3(i, j);
			else if (cnt = 4) helper4(i, j);

			rep(k, 0, 4) {
				a[i + dx[k]][j + dy[k]] = 0;
			}
		}
	}

	cout << t << '\n';
	rep(i, 0, t) {
		for (auto x : adj[i]) cout << x << ' ';
		cout << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}