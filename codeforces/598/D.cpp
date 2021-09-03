#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

int n, m, k, ans;
int a[1001][1001];
int visited[1001][1001];
map<int, int> res;

void dfs(int i, int j, int &cnt, int num)
{
	if (i < 0 || j < 0 || i > n || j > m || a[i][j] == 1 || visited[i][j] != -1) return;

	visited[i][j] = num;
	if (a[i][j + 1] == 1) cnt++;
	if (a[i][j - 1] == 1) cnt++;
	if (a[i + 1][j] == 1) cnt++;
	if (a[i - 1][j] == 1) cnt++;
	dfs(i + 1, j, cnt, num);
	dfs(i - 1, j, cnt, num);
	dfs(i, j + 1, cnt, num);
	dfs(i, j - 1, cnt, num);
}

void solve()
{
	cin >> n >> m >> k;
	rep(i, 0, n) {
		rep(j, 0, m) {
			char c; cin >> c;
			if (c == '*') a[i][j] = 1;
			else a[i][j] = 0;
		}
	}

	mem1(visited);
	vector<pii> queries;
	while (k--) {
		int x, y; cin >> x >> y;
		queries.pb({--x, --y});
	}

	int num = 0;
	for (auto [x, y] : queries) {
		int cnt = 0;
		if (visited[x][y] == -1) {
			dfs(x, y, cnt, num);
			res[num] = cnt;
			cout << cnt << '\n';
			num++;
		}
		else {
			cout << res[visited[x][y]] << '\n';
		}
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}