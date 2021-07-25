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

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return (b, a % b);
}

void solve()
{
	ll n;
	cin >> n;

	ll res1 = 1e17, res2 = 1e17;

	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ll a = n / i, b = i;
			ll lcm = (a * b) / __gcd(a, b);
			//cout << "lcm: " <<  lcm << '\n';

			if (lcm == n) {
				if (max(res1, res2) > max(a, b)) {
					res1 = b, res2 = a;
				}
			}
		}
	}

	cout << res1 << " " << res2 << '\n';
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