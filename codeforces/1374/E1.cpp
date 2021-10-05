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
	int n, k;
	cin >> n >> k;

	multiset<int> a, b, c;
	rep(i, 0, n) {
		int t, x, y;
		cin >> t >> x >> y;

		if (x == 1 && y == 1) c.insert(t);
		else if (x == 1) a.insert(t);
		else if (y == 1) b.insert(t);
	}

	ll ans = 0;

	while (k > 0 && !a.empty() && !b.empty() && !c.empty()) {
		if (*c.begin() < (*a.begin()) + (*b.begin())) {
			ans += *c.begin();
			c.erase(c.begin());
			k--;
		}
		else {
			ans += (*a.begin()) + (*b.begin());
			a.erase(a.begin());
			b.erase(b.begin());
			k--;
		}
	}

	while (k > 0 && !c.empty()) {
		ans += *c.begin();
		c.erase(c.begin());
		k--;
	}

	int cnt = k;

	while (k > 0 && !a.empty()) {
		ans += *a.begin();
		a.erase(a.begin());
		k--;
	}

	while (cnt > 0 && !b.empty()) {
		ans += *b.begin();
		b.erase(b.begin());
		cnt--;
	}

	if (k == 0 && cnt == 0) cout << ans << '\n';
	else cout << -1 << '\n';
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