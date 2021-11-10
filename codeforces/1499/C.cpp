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
	int n;
	cin >> n;

	ll a[n];
	rep(i, 0, n) cin >> a[i];

	ll up = n * a[0], right = n * a[1];
	ll ans = up + right, mn_up = a[0], mn_right = a[1];

	rep(i, 2, n) {
		if (i % 2 == 0) {
			if (a[i] < mn_up) {
				up += (n - i / 2) * (a[i] - mn_up);
				mn_up = a[i];
			}
			else {
				up += a[i] - mn_up;
			}
		}
		else {
			if (a[i] < mn_right) {
				right += (n - i / 2) * (a[i] - mn_right);
				mn_right = a[i];
			}
			else {
				right += a[i] - mn_right;
			}
		}

		ans = min(ans, up + right);
	}

	cout << ans << '\n';
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