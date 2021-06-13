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
	int n, k;
	cin >> n >> k;

	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	vector<pii> res;
	int m = 0, s = 0;

	while (m < k) {
		int low = 0, high = 0, mx = -1, mn = INT_MAX;

		rep(i, 0, n) {
			if (a[i] > mx) {
				mx = a[i];
				high = i;
			}

			if (a[i] < mn) {
				mn = a[i];
				low = i;
			}
		}

		if (mx == mn || low == high) break;

		res.pb({high, low});
		a[high]--, a[low]++;
		m++;
	}

	sort(all(a));
	s = a[n - 1] - a[0];

	cout << s << " " << sz(res) << '\n';
	for (auto it : res) cout << it.ff + 1 << " " << it.ss + 1 << '\n';
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