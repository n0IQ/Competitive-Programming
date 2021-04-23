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

int a[50][50], b[50][50];

bool check(int n, int m)
{
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (a[i][j] != b[i][j]) return false;
		}
	}

	return true;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> a[i][j];
		}
	}

	vpii v;

	rep(i, 0, n - 1) {
		rep(j, 0, m - 1) {
			if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
				v.pb({i + 1, j + 1});
				b[i][j] = 1; b[i][j + 1] = 1;
				b[i + 1][j] = 1; b[i + 1][j + 1] = 1;
			}
		}
	}

	if (check(n, m)) {
		cout << sz(v) << '\n';

		for (auto p : v) {
			cout << p.ff << " " << p.ss << '\n';
		}
	}
	else {
		cout << -1 << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}