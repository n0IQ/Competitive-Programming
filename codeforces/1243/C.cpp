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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<ll> d;
ll n;

bool isPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}

	return true;
}

void divisors()
{
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i == i) d.pb(i);
			else {
				d.pb(i);
				d.pb(n / i);
			}
		}
	}

	sort(all(d));
}

void solve()
{
	cin >> n;
	divisors();

	if (n == 1 || isPrime(n)) {
		cout << n << '\n';
		return;
	}

	int cnt = 0;
	rep(i, 0, sz(d)) {
		if (isPrime(d[i])) cnt++;
	}

	if (cnt >= 2) cout << 1 << '\n';
	else cout << n / d[sz(d) - 1] << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}