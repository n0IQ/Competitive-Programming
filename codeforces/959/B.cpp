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
	int n, k, m;
	cin >> n >> k >> m;

	vs v(n + 1);
	vi a(n + 1);
	rep(i, 1, n + 1) cin >> v[i];
	rep(i, 1, n + 1) cin >> a[i];

	map<string, int> mp;
	rep(i, 1, n + 1) {
		mp[v[i]] = i;
	}

	rep(i, 0, k) {
		int x; cin >> x;
		if (x > 1) {
			vi v;
			int cost = INT_MAX;

			rep(j, 0, x) {
				int w; cin >> w;
				v.pb(w);
				cost = min(cost, a[w]);
			}

			rep(j, 0, sz(v)) {
				a[v[j]] = cost;
			}
		}
		else {
			int w; cin >> w;
		}
	}

	ll cost = 0LL;
	rep(i, 1, m + 1) {
		string s; cin >> s;
		int x = mp[s];
		cost += a[x];
	}

	cout << cost << '\n';
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