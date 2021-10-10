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
	cin >> n;

	int a[2][1000];
	rep(i, 0, 2) {
		rep(j, 0, n) {
			char c; cin >> c;

			if (c == '0') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}

	if (a[1][n - 1] == 1) {
		cout << "NO\n";
		return;
	}

	int i = 0, j = 0;
	while (j != n - 1) {
		if (i == 0) {
			if (a[i + 1][j + 1] == 0) {
				i++, j++;
			}
			else if (a[i][j + 1] == 0) {
				j++;
			}
			else break;
		}
		else if (i == 1) {
			if (a[i][j + 1] == 0) {
				j++;
			}
			else if (a[i - 1][j + 1] == 0) {
				i--, j++;
			}
			else break;
		}
	}

	if (i == 1 && j == n - 1) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	fastio;

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}