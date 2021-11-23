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

int n;
int arr[(int)2e5 + 10];
ll low, high;

ll checkLow(ll a)
{
	ll l = 0, r = n - 1, ans = -1;
	while (l <= r) {
		ll m = l + (r - l) / 2;
		ll x = a + arr[m];

		if (x >= low) {
			if (x <= high) ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return ans;
}

ll checkHigh(ll a)
{
	ll l = 0, r = n - 1, ans = -1;
	while (l <= r) {
		ll m = l + (r - l) / 2;
		ll x = a + arr[m];

		if (x <= high) {
			if (x >= low) ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	return ans;
}

void solve()
{
	cin >> n >> low >> high;
	rep(i, 0, n) cin >> arr[i];

	sort(arr, arr + n);
	ll ans = 0;

	rep(i, 0, n) {
		ll a = checkHigh(arr[i]);
		ll b = checkLow(arr[i]);
		if (a > -1) ans += a - b + 1;
		if (low <= 2 * arr[i] && 2 * arr[i] <= high) ans--;
	}

	cout << ans / 2 << '\n';
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