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

const int N = 2 * 1e5;

void solve()
{
	int n;
	cin >> n;

	int a[n];
	vvi adj(n + 1);

	rep(i, 0, n) {
		cin >> a[i];
		adj[a[i]].pb(i + 1);
	}

	int ans = INT_MAX, t = 0;
	vb mark(n + 1, false);

	rep(i, 0, n) {
		if (mark[a[i]]) continue;
		mark[a[i]] = true;
		if (sz(adj[a[i]]) == 1) continue;
		int j = 0, f, s;

		for (auto it : adj[a[i]]) {
			if (j == 0) {
				j++;
				s = it;
				continue;
			}

			f = s;
			s = it;

			ans = min(ans, s - f + 1);
		}
	}

	if (ans == INT_MAX) cout << -1 << '\n';
	else cout << ans << '\n';
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