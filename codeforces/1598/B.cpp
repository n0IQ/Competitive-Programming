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

	int a[n + 1][6];
	vector<int> days[6];

	rep(i, 1, n + 1) {
		rep(j, 1, 6) {
			cin >> a[i][j];

			if (a[i][j] == 1) {
				days[j].pb(i);
			}
		}
	}

	rep(i, 1, 6) {

		rep(j, i + 1, 6) {

			set<int> s1, s2, s3, s4;
			for (auto x : days[i]) s3.insert(x);
			for (auto x : days[j]) s3.insert(x);

			for (auto x : days[i]) {
				if (find(all(days[j]), x) == days[j].end()) {
					s1.insert(x);
				}
				else s4.insert(x);
			}

			for (auto x : days[j]) {
				if (!s4.count(x)) s2.insert(x);
			}

			if (sz(s1) <= n / 2 && sz(s2) <= n / 2 && sz(s3) >= n) {
				cout << "YES\n";
				return;
			}
		}
	}

	cout << "NO\n";
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