#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];

	vector<int> b(a);
	sort(all(b));

	vector<pair<pii, int>> ans;

	rep(i, 0, n) {
		if (a[i] != b[i]) {
			int t = find(a.begin() + i, a.end(), b[i]) - a.begin();
			vector<int> c, d;
			rep(j, i, t + 1) c.pb(a[j]);
			rotate(c.begin(), c.begin() + t - i, c.end());
			rep(j, 0, i) d.pb(a[j]);
			rep(j, 0, sz(c)) d.pb(c[j]);
			rep(j, t + 1, n) d.pb(a[j]);
			a.clear();
			a = d;

			ans.pb({{i + 1, t + 1}, {t - i}});
		}
	}

	cout << sz(ans) << '\n';
	for (auto it : ans) {
		cout << it.ff.ff << ' ' << it.ff.ss << ' ' << it.ss << '\n';
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}