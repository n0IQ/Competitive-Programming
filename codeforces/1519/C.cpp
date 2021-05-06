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

const int N = 2e5 + 1;
vvi dv, a;
int u[N];
ll ans[N];

void solve()
{
	a.clear(); a.resize(N);
	mem0(u), mem0(ans);

	int n;
	cin >> n;
	rep(i, 0, n) cin >> u[i];
	rep(i, 0, n) {
		int x; cin >> x;
		a[u[i]].pb(x);
	}

	rep(i, 1, n + 1) {
		sort(a[i].rbegin(), a[i].rend());
		vll p(sz(a[i]) + 1, 0);

		rep(j, 1, sz(a[i]) + 1) {
			p[j] = p[j - 1] + a[i][j - 1];

			for (int k : dv[j]) {
				ans[k] += p[j] - p[j - k];
			}
		}
	}

	rep(i, 1, n + 1) cout << ans[i] << " ";
	cout << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	dv.resize(N);

	rep(i, 1, N) {
		for (int j = i; j < N; j += i) {
			dv[j].pb(i);
		}
	}

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}