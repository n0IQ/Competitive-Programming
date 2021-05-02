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
int a[501][501];

bool check()
{
	rep(i, 0, n) {
		rep(j, 0, m) {
			if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
				if (a[i][j] > 2) {
					return false;
				}
			}
			if (i == 0 || i == n - 1) {
				if (a[i][j] > 3) {
					return false;
				}
			}
			if (j == 0 || j == m - 1) {
				if (a[i][j] > 3) {
					return false;
				}
			}
			else {
				if (a[i][j] > 4) {
					return false;
				}
			}
		}
	}

	return true;
}

void solve()
{
	cin >> n >> m;
	rep(i, 0, n) {
		rep(j, 0, m) {
			cin >> a[i][j];
		}
	}

	if (!check()) {
		cout << "NO" << '\n';
		return;
	}

	cout << "YES" << '\n';

	rep(i, 0, n) {
		rep(j, 0, m) {
			if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) a[i][j] = 2;
			else if (i == 0 || i == n - 1) a[i][j] = 3;
			else if (j == 0 || j == m - 1) a[i][j] = 3;
			else a[i][j] = 4;
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << a[i][j] << " ";
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

/*
rep(i, 0, m) {
		if (a[0][i] > 3) {
			cout << "NO" << '\n';
			return;
		}
	}

	rep(i, 0, n) {
		if (a[i][0] > 3) {
			cout << "NO" << '\n';
			return;
		}
	}

	rep(i, 0, m) {
		if (a[n - 1][i] > 3) {
			cout << "NO" << '\n';
			return;
		}
	}

	rep(i, 0, n) {
		if (a[i][m - 1] > 3) {
			cout << "NO" << '\n';
			return;
		}
	}
*/