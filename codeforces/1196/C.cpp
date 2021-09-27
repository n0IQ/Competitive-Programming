#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
	int n;
	cin >> n;

	int moves[n][4];
	vector<pii> dx, dy;

	rep(i, 0, n) {
		int x, y;
		cin >> x >> y;
		dx.pb({x, i});
		dy.pb({y, i});

		rep(j, 0, 4) cin >> moves[i][j];
	}

	sort(all(dx)), sort(all(dy));

	int ansx, ansy, x, y, idx = n - 1;
	rep(i, 0, n - 1) {
		if (moves[dx[i].ss][2] == 0) {
			idx = i;
			x = dx[i].ff;
			break;
		}
	}

	repR(i, n - 1, idx + 1) {
		if (dx[i].ff != x && moves[dx[i].ss][0] == 0) {
			cout << 0 << '\n';
			return;
		}
	}

	ansx = dx[idx].ff;

	idx = n - 1;
	rep(i, 0, n - 1) {
		if (moves[dy[i].ss][1] == 0) {
			idx = i;
			y = dy[i].ff;
			break;
		}
	}

	repR(i, n - 1, idx + 1) {
		if (dy[i].ff != y && moves[dy[i].ss][3] == 0) {
			cout << 0 << '\n';
			return;
		}
	}

	ansy = dy[idx].ff;

	cout << 1 << ' ' << ansx << ' ' << ansy << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}