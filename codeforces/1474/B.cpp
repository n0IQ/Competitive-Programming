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

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 2e5;
bool isPrime[N + 10];
vi primes;

void sieve()
{
	for (int i = 0; i <= N; i++) {
		isPrime[i] = true;
	}

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= N; i++) {
		if (isPrime[i] && i * i <= N) {
			for (int j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	rep(i, 0, N) {
		if (isPrime[i]) primes.pb(i);
	}
}

void solve()
{
	int d;
	cin >> d;

	ll n, m;
	auto it1 = lb(all(primes), 1 + d);
	n = *it1;
	auto it2 = lb(all(primes), n + d);
	m = *it2;

	cout << n * 1LL * m << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	sieve();

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}