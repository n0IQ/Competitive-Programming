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
	int n, d;
	cin >> n >> d;

	vector<pii> a;
	rep(i, 0, n) {
		int x, y; cin >> x >> y;
		a.pb({x, y});
	}

	sort(all(a));
	int i = 0, j = 0, mn = a[0].ff;
	ll ans = 0, sum = 0;

	while (j < n) {

		while (j < n && abs(a[j].ff - mn) < d) {
			sum += a[j].ss;
			mn = min(mn, a[j].ff);
			j++;
		}

		ans = max(ans, sum);

		while (i < j && abs(a[i].ff - a[j].ff) >= d) {
			sum -= a[i].ss;
			i++;
		}

		mn = a[i].ff;
	}

	ans = max(ans, sum);

	cout << ans << '\n';
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