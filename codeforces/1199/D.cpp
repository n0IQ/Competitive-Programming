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
	cin >> n;

	vi a(n);
	rep(i, 0, n) cin >> a[i];

	cin >> q;
	vector<pair<int, pii>> queries;
	rep(i, 0, q) {
		int type; cin >> type;

		if (type == 1) {
			int x, y; cin >> x >> y;
			queries.pb({type, {x, y}});
		}
		else {
			int x; cin >> x;
			queries.pb({type, {0, x}});
		}
	}

	reverse(all(queries));
	map<int, int> info;
	int x = 0;

	for (auto it : queries) {
		int type = it.ff, idx = it.ss.ff, val = it.ss.ss;

		if (type == 1) {
			if (info.count(idx)) continue;
			info[idx] = max(x, val);
		}
		else {
			x = max(x, val);
		}
	}

	rep(i, 0, n) {
		if (info.count(i + 1)) {
			a[i] = info[i + 1];
		}
		else {
			a[i] = max(a[i], x);
		}
	}

	for (auto x : a) cout << x << " ";
	cout << '\n';
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