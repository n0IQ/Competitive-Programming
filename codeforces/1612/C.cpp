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

ll check(ll m, ll k)
{
	ll val = 0;
	if (m <= k) val = (m * (m + 1)) / 2;
	else {
		val = (k * (k + 1)) / 2;
		ll t = k - 1;
		ll a = (t * (t + 1)) / 2;
		t = 2 * k - 1 - m;
		ll b = (t * (t + 1)) / 2;
		a -= b;
		val += a;
	}

	return val;
}

void solve()
{
	ll k, x;
	cin >> k >> x;

	ll l = 0, r = 2 * k - 1, ans = 0;
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (check(m, k) <= x) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	if (ans < 2 * k - 1 && check(ans, k) < x) ans++;

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