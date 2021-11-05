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
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

void solve()
{
	int n, m;
	string s;
	cin >> n >> m >> s;

	int curr_x = 0, curr_y = 0, mx_x = 0, mn_x = 0, mx_y = 0, mn_y = 0, ans_x = -1, ans_y = -1;

	for (auto c : s) {
		curr_y += (c == 'R');
		curr_y -= (c == 'L');
		curr_x += (c == 'D');
		curr_x -= (c == 'U');

		mx_y = max(mx_y, curr_y);
		mn_y = min(mn_y, curr_y);
		mx_x = max(mx_x, curr_x);
		mn_x = min(mn_x, curr_x);

		if (mx_x - mn_x + 1 > n || mx_y - mn_y + 1 > m) {
			mn_y += (c == 'L');
			mn_x += (c == 'U');

			ans_x = -mn_x;
			ans_y = -mn_y;
			break;
		}
	}

	if (ans_x == -1) {
		ans_x = -mn_x;
		ans_y = -mn_y;
	}

	cout << ans_x + 1 << ' ' << ans_y + 1 << '\n';
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