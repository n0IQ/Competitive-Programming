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

#define mod 998244353
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 2e5 + 5;
int fact[N];
int invfact[N];

int mult(int a, int b)
{
	int res = (a * 1LL * b) % mod;

	if (res < 0) {
		res += mod;
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
	rep(i, 1, N) {
		fact[i] = mult(i, fact[i - 1]) % mod;
	}

	invfact[N - 1] = power(fact[N - 1], mod - 2) % mod;
	repR(i, N - 2, 0) {
		invfact[i] = mult(invfact[i + 1], i + 1) % mod;
	}
}

int getnCr(int n, int r)
{
	if (r > n || n < 0 || r < 0) {
		return 0;
	}

	int res = mult(mult(fact[n], invfact[r]) % mod, invfact[n - r]) % mod;

	return res;
}

void solve()
{
	int n;
	cin >> n;

	map<int, int, greater<int>> m;
	rep(i, 0, n) {
		int x; cin >> x;
		m[x]++;
	}

	if (m.begin()->ss > 1) {
		cout << fact[n] % mod << '\n';
		return;
	}

	auto it = m.begin();
	auto it1 = it; it1++;
	if (abs(it->ff - it1->ff) > 1) {
		cout << 0 << '\n';
		return;
	}

	int countmax = it->ss, countsecmax = it1->ss;
	int arrangeSmall = mult(getnCr(n, countmax + countsecmax), fact[n - countmax - countsecmax]); // arrange numbers smaller than max and second max * their permutation
	int arrangeSecmax = fact[countsecmax]; // ways to arrange second max
	int badPermutation = mult(arrangeSmall, arrangeSecmax);
	int ans = ((fact[n] % mod) - (badPermutation % mod)) % mod;

	if (ans < 0) ans += mod;
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