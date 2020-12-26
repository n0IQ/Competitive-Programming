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

bool Solve(int n, bool primes[])
{
	int divisors = 0;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0 && primes[i]) {
			divisors++;
		}
	}

	if (divisors == 2) {
		return true;
	}

	return false;
}

int main()
{
	fastio

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	const int N = 3005;
	static bool primes[N];

	for (int i = 0; i < N; i++) {
		primes[i] = true;
	}

	primes[0] = false;
	primes[1] = false;

	for (int i = 2; i < N; i++) {
		if (primes[i]) {
			for (ll j = i * i; j < N; j += i) {
				primes[j] = false;
			}
		}
	}

	int n;
	cin >> n;

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		if (Solve(i, primes)) {
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}