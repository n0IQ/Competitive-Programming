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

int n, m, k;
int a[1001][1001];
int visited[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
map<int, int> res;

void dfs(int x, int y, int &cnt, int num)
{
	if (a[x][y] == 1 || visited[x][y] != -1) return;

	visited[x][y] = num;
	rep(i, 0, 4) {
		if (a[x + dx[i]][y + dy[i]] == 1) cnt++;
	}
	rep(i, 0, 4) {
		dfs(x + dx[i], y + dy[i], cnt, num);
	}
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
	int num = 0;

	while (k--) {
		int x, y, cnt = 0; cin >> x >> y;
		--x, --y;
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