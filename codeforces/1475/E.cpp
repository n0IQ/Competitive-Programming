#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repR(i, n) for (int i = n-1; i >= 0; --i)
#define repA(i, a, n) for (int i = a; i <= n; ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vd vector<double>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>
#define vpdd vector<pdd>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

const int N = 1e3 + 5;
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
	repA(i, 1, N - 1) {
		fact[i] = mult(i, fact[i - 1]) % mod;
	}

	invfact[N - 1] = power(fact[N - 1], mod - 2) % mod;
	repR(i, N - 1) {
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

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	precalc();

	int T;
	cin >> T;

	while (T-- > 0)
	{
		int n, k;
		cin >> n >> k;

		vi v(n);

		rep(i, n) {
			cin >> v[i];
		}

		sort(all(v), greater<>());
		int count = 1, blog = k;

		repA(i, 1, n - 1) {
			if (v[i] == v[i - 1]) {
				count++;
			}
			else {
				if (count > k) {
					break;
				}

				k -= count;
				count = 1;
			}
		}

		ll ans = 1;

		if (k > 0) {
			ans = getnCr(count, k);
		}

		cout << ans << '\n';
	}

	return 0;
}