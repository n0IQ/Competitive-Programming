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

	int a[n], b[n];
	rep(i, 0, n) cin >> a[i];

	if (a[0] > 1) {
		cout << -1 << '\n';
		return;
	}

	mem1(b);
	vector<int> temp;
	int gaps = 0, req = 0;

	if (a[0] == 1) {
		b[0] = 0;
		gaps++;
	}

	rep(i, 1, n) {
		if (a[i] != a[i - 1]) {
			b[i] = a[i - 1];
			gaps++;
		}

		if (a[i] - a[i - 1] - 1 > 0) {
			req += a[i] - a[i - 1] - 1;
			rep(j, a[i - 1] + 1, a[i]) {
				temp.pb(j);
			}
		}
	}

	gaps = n - gaps;
	if (req > gaps) {
		cout << -1 << '\n';
		return;
	}

	rep(i, 100000, 1000000) temp.pb(i);

	int j = 0;
	rep(i, 0, n) {
		if (b[i] == -1) {
			if (j == sz(temp)) j = 0;
			b[i] = temp[j];
			j++;
		}
	}

	rep(i, 0, n) cout << b[i] << ' ';
	cout << '\n';
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}