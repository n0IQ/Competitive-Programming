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

int n, m;
int dp[101][101];

int bersu(int a[], int b[], int i, int j) {
	if (i == n || j == m) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int p1 = 0, p2 = 0, p3 = 0;

	if (abs(a[i] - b[j]) <= 1) {
		p1 = 1 + bersu(a, b, i + 1, j + 1);
	}

	p2 = bersu(a, b, i, j + 1);
	p3 = bersu(a, b, i + 1, j);

	return dp[i][j] = max({p1, p2, p3});
}

void solve()
{
	//int n, m;
	cin >> n;

	int a[n];
	rep(i, 0, n) cin >> a[i];

	cin >> m;
	int b[m];
	rep(i, 0, m) cin >> b[i];

	sort(a, a + n);
	sort(b, b + m);

	mem1(dp);

	cout << bersu(a, b, 0, 0) << '\n';
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