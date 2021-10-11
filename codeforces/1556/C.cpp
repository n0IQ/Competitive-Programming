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

//Explanation: https://www.youtube.com/watch?v=AbeEJvmsx0E

void solve()
{
	int n;
	cin >> n;

	ll a[n];
	rep(i, 0, n) cin >> a[i];

	vector<ll> heights;
	heights.pb(0);

	rep(i, 0, n) {
		if (i % 2 == 0) heights.pb(heights.back() + a[i]);
		else heights.pb(heights.back() - a[i]);
	}

	n = sz(heights);
	ll ans = 0;
	rep(i, 0, n - 1) {
		if (heights[i] < heights[i + 1]) { // valid para shld start with increasing slope i.e.'(' and end with decreasing slope i.e. ')'
			ll minHeight = heights[i + 1];

			rep(j, i + 1, n - 1) {
				minHeight = min(minHeight, heights[j]);

				if (heights[j] > heights[j + 1]) {
					ll a = heights[i];
					ll b = heights[j + 1];
					ans += max(0LL, minHeight - max(a, b) + 1);

					if (i + 1 == j) { // invalid parathensis
						ans--;
					}
				}
			}
		}
	}

	cout << ans << '\n';
}

int main()
{
	fastio;

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}