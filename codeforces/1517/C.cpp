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

int mat[510][510];
int n;

void dfs(int i, int j, int x, int &count)
{
	if (i < 1 || j < 1 || i > n || j > n || mat[i][j] != 0) return;
	if (count == x) return;

	mat[i][j] = x;
	count++;
	dfs(i, j - 1, x, count);
	dfs(i + 1, j, x, count);
}

void solve()
{
	cin >> n;

	vi a(n);
	rep(i, 0, n) {
		int x, count = 0; cin >> x;
		dfs(i + 1, i + 1, x, count);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) cout << mat[i][j] << " ";
		cout << '\n';
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