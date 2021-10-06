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

bool check(vector<int> a)
{
	rep(i, 1, sz(a)) {
		if (a[i] != a[i - 1]) {
			return false;
		}
	}

	return true;
}

void solve()
{
	int n;
	cin >> n;

	map<int, int> m;
	int ans = 0;

	rep(i, 1, n + 1) {
		int x;
		cin >> x;
		m[x]++;

		vector<int> a;
		for (auto it : m) a.pb(it.ss);
		sort(all(a));

		if (sz(a) == 1) ans = a[0];
		else if (sz(a) == 2) {
			if (a[0] == 1 || a[1] == 1 || a[1] - a[0] == 1) {
				ans = i;
			}
		}
		else {
			bool ok = true;
			int t = -1;

			rep(j, 1, sz(a)) {
				if (a[j] != a[j - 1]) {
					t = j;
					break;
				}
			}

			if (t == -1) {
				if (a[sz(a) - 1] == 1) ans = i;
			}
			else {
				vector<int> b;
				a[t - 1]--;
				rep(j, 0, sz(a)) {
					if (a[j] != 0) b.pb(a[j]);
				}

				if (check(b)) ans = i;
				a[t - 1]++;
				a[t]--;
				b.clear();
				rep(j, 0, sz(a)) {
					if (a[j] != 0) b.pb(a[j]);
				}
				if (check(b)) ans = i;
			}
		}
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