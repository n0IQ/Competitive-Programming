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
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

void solve()
{
	ll a, b, c;
	cin >> a >> b >> c;

	ll weeks = min({a / 3, b / 2, c / 2});
	ll ans = weeks * 7;

	a -= weeks * 3;
	b -= weeks * 2;
	c -= weeks * 2;

	ll mx = 0;
	rep(i, 0, 7) {
		ll ta = a, tb = b, tc = c, days = 0;
		int j = i;
		while (1) {
			if (j == 7) j = 0;
			if (j == 0 || j == 1 || j == 4) {
				if (ta == 0) break;
				else days++, ta--;
			}
			else if (j == 2 || j == 6) {
				if (tb == 0) break;
				else days++, tb--;
			}
			else {
				if (tc == 0) break;
				else days++, tc--;
			}

			j++;
		}

		mx = max(mx, days);
	}

	cout << ans + mx << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}