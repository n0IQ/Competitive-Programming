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

void solve()
{
	int n;
	cin >> n;

	vi a(n);
	rep(i, 0, n) cin >> a[i];

	vll alice, bob;
	alice.pb(0), bob.pb(0);

	int l = 0, r = n - 1, moves = 0;
	bool al = 1;

	while (l <= r) {
		if (al) {
			ll points = bob[sz(bob) - 1];
			ll temp = 0LL;

			while (l <= r && temp <= points) temp += a[l++];

			alice.pb(temp);
			al = 0;
		}
		else {
			ll points = alice[sz(alice) - 1];
			ll temp = 0LL;

			while (l <= r && temp <= points) temp += a[r--];

			bob.pb(temp);
			al = 1;
		}

		moves++;
	}

	ll points1 = accumulate(all(alice), 0LL);
	ll points2 = accumulate(all(bob), 0LL);

	cout << moves << " " << points1 << " " << points2 << '\n';
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