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
	ll p1, p2, k1, k2, n;
	cin >> p1 >> p2 >> k1 >> k2 >> n;

	ll t = (p1 * (k1 - 1)) + (p2 * (k2 - 1)), mn = 0, mx = 0;
	if (t <= n) mn = abs(t - n);

	if (k1 < k2) {
		while (p1 && n > 0) {
			if (n - k1 >= 0) {
				mx++, p1--;
				n -= k1;
			}
			else break;
		}

		while (p2 && n > 0) {
			if (n - k2 >= 0) {
				mx++, p2--;
				n -= k2;
			}
			else break;
		}
	}
	else {
		while (p2 && n > 0) {
			if (n - k2 >= 0) {
				mx++, p2--;
				n -= k2;
			}
			else break;
		}
		while (p1 && n > 0) {
			if (n - k1 >= 0) {
				mx++, p1--;
				n -= k1;
			}
			else break;
		}
	}

	cout << mn << ' ' << mx << '\n';
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