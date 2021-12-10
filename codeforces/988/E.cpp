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

ll helper(string &s, int n, char ch, int l)
{
	ll ans = 0;
	repR(i, n - l, 0) {
		if (s[i] == ch) {
			ans += (n - l - i);

			rep(j, i, n - l) {
				swap(s[j], s[j + 1]);
			}

			break;
		}
	}

	return ans;
}

ll first_non_zero(string &s, int n)
{
	rep(i, 0, n - 2) {
		if (s[i] != '0') return i;
	}

	return 1e9;
}

void solve()
{
	string s;
	cin >> s;

	int n = sz(s), cnt0 = 0, cnt2 = 0, cnt5 = 0, cnt7 = 0;
	rep(i, 0, n) {
		cnt0 += s[i] == '0';
		cnt2 += s[i] == '2';
		cnt5 += s[i] == '5';
		cnt7 += s[i] == '7';
	}

	ll ans = 1e12;

	if (cnt0 >= 2) {
		ll x = 0;
		string t = s;
		x += helper(t, n, '0', 1);
		x += helper(t, n, '0', 2);
		if (t[0] == '0') x += first_non_zero(t, n);
		ans = min(ans, x);
	}


	if (cnt2 >= 1 && cnt5 >= 1) { // 25
		ll x = 0;
		string t = s;
		x += helper(t, n, '5', 1);
		x += helper(t, n, '2', 2);
		if (t[0] == '0') x += first_non_zero(t, n);
		ans = min(ans, x);
	}

	if (cnt5 >= 1 && cnt0 >= 1) { // 50
		ll x = 0;
		string t = s;
		x += helper(t, n, '0', 1);
		x += helper(t, n, '5', 2);
		if (t[0] == '0') x += first_non_zero(t, n);
		ans = min(ans, x);
	}

	if (cnt7 >= 1 && cnt5 >= 1) { // 75
		ll x = 0;
		string t = s;
		x += helper(t, n, '5', 1);
		x += helper(t, n, '7', 2);
		if (t[0] == '0') x += first_non_zero(t, n);
		ans = min(ans, x);
	}

	if (ans == 1e12) cout << -1 << '\n';
	else cout << ans << '\n';
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