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

int mat[3][1001];

void solve()
{
	int n, k1, k2, w, b;
	cin >> n >> k1 >> k2 >> w >> b;

	rep(i, 0, 3) {
		rep(j, 0, 1001) {
			mat[i][j] = 2;
		}
	}

	rep(i, 1, k1 + 1) {
		mat[1][i] = 1;
	}

	rep(i, 1, k2 + 1) {
		mat[2][i] = 1;
	}

	rep(i, 1, 3) {
		rep(j, 1, n + 1) {
			if (mat[i][j] == 1 && w > 0) {
				if (i != 2 && mat[i + 1][j] == 1) {
					w--;
					mat[i][j] = 0, mat[i + 1][j] = 0;
				}
				else if (j != n && mat[i][j + 1] == 1 && w > 0) {
					w--;
					mat[i][j] = 0, mat[i][j + 1] = 0;
				}
			}
			else if (mat[i][j] == 2 && b > 0) {
				if (i != 2 && mat[i + 1][j] == 2) {
					b--;
					mat[i][j] = 0, mat[i + 1][j] = 0;
				}
				else if (j != n && mat[i][j + 1] == 2 && b > 0) {
					b--;
					mat[i][j] = 0, mat[i][j + 1] = 0;
				}
			}

		}
	}

	if (w == 0 && b == 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
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