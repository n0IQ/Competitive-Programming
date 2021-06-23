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

vi getPrimefact(int n)
{
	vi primes;

	while (n % 2 == 0) {
		primes.pb(2);
		n /= 2;
	}

	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			primes.pb(i);
			n /= i;
		}
	}

	if (n > 2) primes.pb(n);

	return primes;
}

void solve()
{
	int n;
	cin >> n;

	vi primes = getPrimefact(n);

	if (sz(primes) < 3) {
		cout << "NO" << '\n';
		return;
	}

	set<int> s;
	s.insert(primes[0]);

	if (primes[1] != primes[0]) {
		s.insert(primes[1]);

		ll num = 1LL;
		rep(i, 2, sz(primes)) {
			num *= primes[i];
		}

		if (num != 1) s.insert(num);
	}
	else {
		ll num = (primes[1] * 1ll * primes[2]);
		s.insert(num);

		num = 1;
		rep(i, 3, sz(primes)) {
			num *= primes[i];
		}

		if (num != 1) s.insert(num);
	}

	if (sz(s) == 3) {
		cout << "YES" << '\n';
		for (auto it : s) cout << it << " ";
	}
	else cout << "NO";

	cout << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}