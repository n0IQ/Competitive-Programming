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

int n, m, good, g_boy, b_boy;
char a[60][60];
bool visited[60][60];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

void dfs(int x, int y)
{
	if (x <= 0 || x > n || y <= 0 || y > m || a[x][y] == '#' || visited[x][y]) return;

	visited[x][y] = 1;
	g_boy += a[x][y] == 'G';
	b_boy += a[x][y] == 'B';

	rep(i, 0, 4) {
		dfs(x + dx[i], y + dy[i]);
	}
}

void solve()
{
	cin >> n >> m;

	rep(i, 0, 60) {
		rep(j, 0, 60) a[i][j] = '.';
	}
	good = 0, g_boy = 0, b_boy = 0;
	mem0(visited);

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			cin >> a[i][j];
			if (a[i][j] == 'G') good++;
		}
	}

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			if (a[i][j] == 'B') {
				rep(k, 0, 4) {
					if (a[i + dx[k]][j + dy[k]] == '.') a[i + dx[k]][j + dy[k]] = '#';
				}
			}
		}
	}

	dfs(n, m);

	if (good == 0 || (good == g_boy && b_boy == 0)) cout << "Yes\n";
	else cout << "No\n";
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