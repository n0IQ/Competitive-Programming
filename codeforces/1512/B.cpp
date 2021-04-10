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

void solve()
{
	int n;
	cin >> n;

	char a[401][401];
	vpii v;
	rep(i, 0, n) {
		rep(j, 0, n) {
			cin >> a[i][j];
			if (a[i][j] == '*') {
				v.pb({i, j});
			}
		}
	}

	int x1 = v[0].ff, y1 = v[0].ss, x2 = v[1].ff, y2 = v[1].ss;
	int x3, y3, x4, y4;

	if (x1 != x2 && y1 != y2) {
		x3 = x1; y3 = y2;
		x4 = x2; y4 = y1;
	}
	else if (x1 == x2 && y1 != y2) {
		if (x1 + 1 >= n) {
			x3 = x1 - 1; x4 = x1 - 1;
			y3 = y1; y4 = y2;
		}
		else {
			x3 = x1 + 1; x4 = x1 + 1;
			y3 = y1; y4 = y2;
		}
	}
	else if (x1 != x2 && y1 == y2) {
		if (y1 + 1 >= n) {
			x3 = x1; x4 = x2;
			y3 = y1 - 1; y4 = y2 - 1;
		}
		else {
			x3 = x1; x4 = x2;
			y3 = y1 + 1; y4 = y2 + 1;
		}
	}

	a[x3][y3] = '*';
	a[x4][y4] = '*';

	rep(i, 0, n) {
		rep(j, 0, n) {
			cout << a[i][j];
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
	cin >> t;
	while (t--) solve();

	return 0;
}