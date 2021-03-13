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

	int a[n + 1], b[n + 1], t[n + 1];
	a[0] = b[0] = t[0] = 0;
	rep(i, 1, n + 1) {
		cin >> a[i] >> b[i];
	}

	rep(i, 1, n + 1) {
		cin >> t[i];
	}

	ll tt = 0;
	vpii ans(n + 1);
	ans[0].ff = ans[0].ss = 0;

	rep(i, 1, n + 1) {
		int arr = (a[i] - b[i - 1]) + t[i];
		int temp = arr + ans[i - 1].ss;
		ans[i].ff = temp;

		int dep = 0;
		((b[i] - a[i]) % 2 == 0 ? dep = (b[i] - a[i]) / 2 : dep = ((b[i] - a[i]) / 2) + 1);
		dep += ans[i].ff;

		if (dep < b[i]) dep = b[i];

		ans[i].ss = dep;
	}

	cout << ans[n].ff << '\n';
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