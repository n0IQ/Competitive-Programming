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

int low[3000000];
int high[3000000];
int sum[3000000];
int len[3000000];

void solve()
{
	string s;
	cin >> s;

	int n = sz(s);
	sum[0] = n + 10;

	rep(i, 0, n) {
		sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
	}

	rep(i, 0, 3000000) {
		low[i] = 1e9;
		high[i] = -1e9;
	}

	repR(i, n, 0) {
		if (i != n) {
			if (low[sum[i] - 1] != 1e9) {
				len[i] = low[sum[i] - 1] - i - 1;
			}
			else if (high[sum[i]] != -1e9) {
				len[i] = high[sum[i]] - i;
			}
		}

		low[sum[i]] = min(low[sum[i]], i);
		high[sum[i]] = max(high[sum[i]], i);
	}

	int mx = 0, cnt = 0;
	rep(i, 0, 3000000) {
		mx = max(mx, len[i]);
	}

	rep(i, 0, 3000000) {
		if (len[i] == mx) cnt++;
	}

	if (mx == 0) {
		cout << 0 << ' ' << 1 << '\n';
	}
	else {
		cout << mx << ' ' << cnt << '\n';
	}
}

int main()
{
	fastio;

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}