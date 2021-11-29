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

const ll MAXN = 2e6 + 10;
bool isPrime[MAXN];

void sieve(ll n)
{
	isPrime[0] = isPrime[1] = 1;
	for (ll i = 2; i * i <= n; i++) {
		if (!isPrime[i]) {
			for (ll j = i * i; j <= n; j += i) {
				isPrime[j] = 1;
			}
		}
	}
}

void solve()
{
	int n, e;
	cin >> n >> e;

	ll a[n];
	rep(i, 0, n) cin >> a[i];

	ll ans = 0, ones[n] = {0}, primes[n] = {0};
	repR(i, n - 1, 0) {
		if (a[i] == 1) {
			ones[i] = 1;
			if (i + e < n) {
				ones[i] += ones[i + e];
				primes[i] += primes[i + e];
			}
		}
		else if (!isPrime[a[i]]) {
			primes[i] = 1;
			if (i + e < n) primes[i] += ones[i + e];
		}

		if (isPrime[a[i]]) ans += primes[i];
		else ans += max(0LL, primes[i] - 1);
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

	sieve(MAXN - 1);
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}