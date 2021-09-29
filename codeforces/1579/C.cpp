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

int a[50][50], mark[50][50];
int n, m, k, cnt1, cnt2;

bool check(int x, int y)
{
	cnt1 = -1;

	for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
		if (a[i][j] == 1) cnt1++;
		else break;
	}

	cnt2 = -1;

	for (int i = x, j = y; i >= 0 && j < m; i--, j++) {
		if (a[i][j] == 1) cnt2++;
		else break;
	}

	return (cnt1 > 0 && cnt2 > 0 && cnt1 >= k && cnt2 >= k);
}

void color(int x, int y)
{
	int cnt3 = -1;
	for (int i = x, j = y; i >= 0 && j >= 0 && cnt3 < min(cnt1, cnt2); i--, j--, cnt3++) mark[i][j] = 1;
	cnt3 = -1;
	for (int i = x, j = y; i >= 0 && j < m && cnt3 < min(cnt1, cnt2); i--, j++, cnt3++) mark[i][j] = 1;
}

void solve()
{
	cin >> n >> m >> k;

	mem0(a);
	mem0(mark);

	rep(i, 0, n) {
		rep(j, 0, m) {
			char c; cin >> c;
			if (c == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			if (a[i][j] == 1) {
				if (check(i, j)) {
					color(i, j);
				}
			}
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			if (a[i][j] == 1 && mark[i][j] == 0) {
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
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