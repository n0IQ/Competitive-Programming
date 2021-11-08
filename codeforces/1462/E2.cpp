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

const int N = 2e5 + 5;
int fact[N];
int invfact[N];

int mult(int a, int b)
{
	int res = (a * 1LL * b) % MOD1;

	if (res < 0) {
		res += MOD1;
	}

	return res;
}

int power(int a, int b)
{
	int res = 1;

	while (b) {
		if (b % 2 == 1) {
			res = mult(a, res);
		}

		a = mult(a, a);
		b /= 2;
	}

	return res;
}

void precalc()
{
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mult(i, fact[i - 1]) % MOD1;
	}

	invfact[N - 1] = power(fact[N - 1], MOD1 - 2) % MOD1;
	for (int i = N - 2; i >= 0; i--) {
		invfact[i] = mult(invfact[i + 1], i + 1) % MOD1;
	}
}

int getnCr(int n, int r)
{
	if (r > n || n < 0 || r < 0) {
		return 0;
	}

	int res = mult(mult(fact[n], invfact[r]) % MOD1, invfact[n - r]) % MOD1;
	return res;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n);
	for (auto &x : a) cin >> x;

	sort(all(a));
	int l = 0, r = 0;
	ll ans = 0;

	while (l < n && r < n) {
		while (r - l + 1 < m) r++;
		if (r >= n) break;

		if (a[r] - a[l] > k) {
			while (l < n && a[r] - a[l] > k) l++;
		}
		else {
			int len = r - l + 1;
			ans += getnCr(len, len - m) - getnCr(len - 1, len - 1 - m);
			ans %= MOD1;
			if (ans < 0) ans += MOD1;
			r++;
		}
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

	precalc();
	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}