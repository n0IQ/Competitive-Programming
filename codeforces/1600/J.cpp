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

int n, m;
map<pii, vector<int>> valid;
bool visited[1001][1001];

void dfs(int i, int j, ll &cnt)
{
	if (visited[i][j]) return;

	visited[i][j] = 1;
	cnt++;
	vector<int> temp = valid[ {i, j}];

	if (!temp[0]) dfs(i - 1, j, cnt);
	if (!temp[1]) dfs(i, j + 1, cnt);
	if (!temp[2]) dfs(i + 1, j, cnt);
	if (!temp[3]) dfs(i, j - 1, cnt);
}

void solve()
{
	cin >> n >> m;

	rep(i, 0, n) {
		rep(j, 0, m) {
			int x, cnt = 0;
			cin >> x;
			vector<int> temp;

			while (cnt < 4) {
				if (x & 1) temp.pb(1);
				else temp.pb(0);

				cnt++;
				x >>= 1;
			}

			reverse(all(temp));
			valid[ {i, j}] = temp;
		}
	}

	vector<ll> rooms;
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (!visited[i][j]) {
				ll cnt = 0;
				dfs(i, j, cnt);
				rooms.pb(cnt);
			}
		}
	}

	sort(rall(rooms));
	for (auto x : rooms) cout << x << ' ';
	cout << '\n';
}

int main()
{
	fastio;

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}