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
	int n, q;
	cin >> n >> q;

	vector<int> a(n), res(n);
	multiset<pii, greater<pii>> cnt;
	rep(i, 0, n) cin >> a[i];

	vector<int> v1, v2;
	vector<pii> queries;
	rep(i, 0, q) {
		int x, y; cin >> x >> y;
		queries.pb({x, y});
		v1.pb(--x);
		v2.pb(--y);
	}

	sort(all(v1)), sort(all(v2));
	sort(all(a), greater<ll>());

	rep(i, 0, n) {
		int j = ub(all(v1), i) - v1.begin();
		int k = lb(all(v2), i) - v2.begin();
		cnt.insert({abs(j - k), i});
	}

	int i = 0;
	for (auto it : cnt) {
		res[it.ss] = a[i++];
	}

	vector<ll> p(n + 1, 0);
	rep(i, 1, n + 1) {
		p[i] = res[i - 1] + p[i - 1];
	}

	ll ans = 0LL;
	for (auto [x, y] : queries) {
		ans += p[y] - p[x - 1];
	}

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