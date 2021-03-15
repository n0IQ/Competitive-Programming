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

int mat[1001][1001];
int n, ax, ay, bx, by, cx, cy;
bool ans = 0, visited[1001][1001];

void DFS(int i, int j)
{
	if (i > n || j > n || i < 1 || j < 1) return;
	if (visited[i][j]) return;
	if (mat[i][j] == 1) return;

	visited[i][j] = 1;

	if (i == cx && j == cy) {
		ans = 1;
		return;
	}

	DFS(i, j + 1);
	DFS(i, j - 1);
	DFS(i + 1, j);
	DFS(i - 1, j);
	DFS(i + 1, j + 1);
	DFS(i - 1, j + 1);
	DFS(i - 1, j - 1);
	DFS(i + 1, j - 1);
}

void solve()
{
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

	rep(i, 1, n + 1) {
		mat[ax][i] = 1;
	}

	rep(i, 1, n + 1) {
		mat[i][ay] = 1;
	}

	for (int i = ax, j = ay; i >= 1 && j <= n; i--, j++) {
		mat[i][j] = 1;
	}

	for (int i = ax, j = ay; i <= n && j <= n; i++, j++) {
		mat[i][j] = 1;
	}

	for (int i = ax, j = ay; i <= n && j >= 1; i++, j--) {
		mat[i][j] = 1;
	}

	for (int i = ax, j = ay; i >= 1 && j <= n; i--, j--) {
		mat[i][j] = 1;
	}

	DFS(bx, by);

	if (ans) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
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