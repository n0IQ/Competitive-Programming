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

const int N = 2 * 1e6;
bool isPrime[N + 1];

void Sieve()
{
	rep(i, 0, N + 1) {
		isPrime[i] = true;
	}

	isPrime[0] = isPrime[1] = false;

	for (ll i = 2; i * i <= N; i++) {
		if (isPrime[i] && i * i <= N) {
			for (ll j = i * i; j <= N; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

ll check(ll n)
{
	ll x = sqrt(n);
	if (x * x == n) return x;
	return -1;
}

void solve()
{
	Sieve();
	int n;
	cin >> n;

	while (n-- > 0) {
		ll x; cin >> x;
		ll t = check(x);

		if (t != -1 && isPrime[t]) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin>>t;
	while (t--) solve();

	return 0;
}