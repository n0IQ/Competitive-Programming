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
	int n;
	string s;
	cin >> n >> s;

	int cnt = 0;
	rep(i, 0, n) {
		cnt += s[i] == '0';
	}

	if (s[0] != '1' || s[n - 1] != '1' || cnt % 2) {
		cout << "NO\n";
		return;
	}

	int res1[n], res2[n];
	mem1(res1), mem1(res2);
	res1[0] = res2[0] = 1;

	int prev = 1;
	rep(i, 1, n) {
		if (s[i] == '0') {
			res1[i] = prev;
			prev ^= 1;
			res2[i] = prev;
		}
	}

	cnt = (n - (cnt + 2)) / 2;
	rep(i, 0, n) {
		if (res1[i] == -1) {
			if (cnt > 0) {
				res1[i] = res2[i] = 1;
				cnt--;
			}
			else res1[i] = res2[i] = 0;
		}
	}

	string ans1, ans2;
	rep(i, 0, n) {
		if (res1[i]) ans1.pb('(');
		else ans1.pb(')');

		if (res2[i]) ans2.pb('(');
		else ans2.pb(')');
	}

	cout << "YES\n";
	cout << ans1 << '\n';
	cout << ans2 << '\n';
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