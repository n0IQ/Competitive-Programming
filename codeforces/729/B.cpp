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

const int N = 1001;
int mat[N][N], dp[N][N];

void solve()
{
	int n, m;
	cin >> n >> m;

	rep(i, 1, n + 1) {
		rep(j, 1, m + 1) {
			cin >> mat[i][j];
		}
	}

	int ans = 0;
	bool f;

	rep(i, 1, n + 1) {
		f = false;
		rep(j, 1, m + 1) {
			if (mat[i][j] == 0 && f) ans++;
			if (mat[i][j] == 1) f = true;
		}
	}

	rep(i, 1, n + 1) {
		f = false;
		repR(j, m, 1) {
			if (mat[i][j] == 0 && f) ans++;
			if (mat[i][j] == 1) f = true;
		}
	}

	rep(j, 1, m + 1) {
		f = false;
		rep(i, 1, n + 1) {
			if (mat[i][j] == 0 && f) ans++;
			if (mat[i][j] == 1) f = true;
		}
	}

	rep(j, 1, m + 1) {
		f = false;
		repR(i, n, 1) {
			if (mat[i][j] == 0 && f) ans++;
			if (mat[i][j] == 1) f = true;
		}
	}

	cout << ans << '\n';
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