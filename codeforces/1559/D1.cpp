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

int find_set(int x, vector<int> &p)
{
	if (x == p[x]) return x;
	return p[x] = find_set(p[x], p);
}

void union_set(int a, int b, vector<int> &p, vector<int> &r)
{
	if (r[a] < r[b]) swap(a, b);
	p[b] = p[a];
	r[a] += r[b];
}

void solve()
{
	int n, m1, m2;
	cin >> n >> m1 >> m2;

	vector<int> p1(n), p2(n), r1(n, 1), r2(n, 1);
	iota(all(p1), 0), iota(all(p2), 0);

	rep(i, 0, m1) {
		int u, v; cin >> u >> v;
		--u, --v;
		u = find_set(u, p1);
		v = find_set(v, p1);

		if (u != v) {
			union_set(u, v, p1, r1);
		}
	}

	rep(i, 0, m2) {
		int u, v; cin >> u >> v;
		--u, --v;
		u = find_set(u, p2);
		v = find_set(v, p2);

		if (u != v) {
			union_set(u, v, p2, r2);
		}
	}

	vector<pii> edges;

	rep(i, 0, n) {
		int u, v, x, y;

		rep(j, i + 1, n) {
			u = find_set(i, p1), v = find_set(j, p1);
			x = find_set(i, p2), y = find_set(j, p2);

			if (u != v && x != y) {
				edges.pb({i, j});
				union_set(u, v, p1, r1);
				union_set(x, y, p2, r2);
			}
		}
	}

	cout << sz(edges) << '\n';
	for (auto [x, y] : edges) {
		cout << x + 1 << " " << y + 1 << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
	     freopen("input.txt","r",stdin);
	     freopen("output.txt","w",stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}