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

int mat[5001][5001], a[100001], b[100001], c[100001];

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<pii, int>> v;
	map<pii, int> points;

	rep(i, 0, k) {
		int t, x, color; cin >> t >> x >> color;
		a[i] = t, b[i] = x, c[i] = color;
	}

	repR(i, k - 1, 0) {
		int t = a[i], x = b[i], color = c[i];

		if (points.find({t, x}) == points.end()) {
			points[ {t, x}] = color;
			v.pb(mp(mp(t, x), color));
		}
	}

	reverse(all(v));

	for (auto it : v) {
		int x = it.ff.ss, color = it.ss;
		x--;

		if (it.ff.ff == 1) rep(i, 0, m) mat[x][i] = color;
		else rep(i, 0, n) mat[i][x] = color;
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << mat[i][j] << " ";
		}

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