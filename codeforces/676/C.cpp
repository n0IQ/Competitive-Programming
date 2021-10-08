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

int helper(string s, int n, int k, char c)
{
	int i = 0, j = 0, ans = 0, l = 0;
	vector<int> idx;

	while (j < n) {
		if (s[j] == c) l++;
		else {
			if (k > 0) {
				idx.pb(j);
				l++, k--;
			}
			else {
				ans = max(ans, l);

				if (!idx.empty()) {
					l = j - idx[0];
					idx.erase(idx.begin());
					idx.pb(j);
				}
			}
		}

		j++;
	}

	ans = max(ans, l);

	return ans;
}

void solve()
{
	int n, k;
	string s;
	cin >> n >> k >> s;

	if (k == 0) {
		int ans = 0, l = 1;
		rep(i, 1, n) {
			if (s[i] == s[i - 1]) l++;
			else {
				ans = max(ans, l);
				l = 1;
			}
		}

		cout << max(ans, l) << '\n';
	}
	else {
		cout << max(helper(s, n, k, 'a'), helper(s, n, k, 'b')) << '\n';
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
	//cin >> t;
	while (t--) solve();

	return 0;
}