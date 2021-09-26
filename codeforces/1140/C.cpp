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

	vector<pll> a;
	multiset<ll> s;
	rep(i, 0, n) {
		int t, b; cin >> t >> b;
		a.pb({b, t});
	}

	sort(all(a), greater<pii>());
	ll ans = 0, t = 0, mn = 1e12;
	int i = 0, cnt = 0;

	while (i < n) {
		if (cnt < k) {
			t += a[i].ss;
			mn = min(mn, a[i].ff);
			s.insert(a[i].ss);
			ans = max(ans, t * mn);
			cnt++;
		}
		else {
			t -= (*s.begin());
			s.erase(s.begin());
			t += a[i].ss;
			mn = min(mn, a[i].ff);
			s.insert(a[i].ss);
			ans = max(ans, t * mn);
		}

		i++;
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
	//cin >> t;
	while (t--) solve();

	return 0;
}