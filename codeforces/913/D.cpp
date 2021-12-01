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

vector<pii> arr;
vector<int> res;
multimap<pii, int> idx;
int n, T;

bool check(int m)
{
	int time = 0, score = 0;
	multimap<pii, int> temp(idx);
	res.clear();

	rep(i, 0, n) {
		if (score == m) break;
		if (arr[i].ss >= m && arr[i].ss && time + arr[i].ff <= T) {
			auto it = temp.find({arr[i].ff, arr[i].ss});
			res.pb(it->ss);
			time += arr[i].ff;
			score++;
			temp.erase(it);
		}
	}

	return score >= m;
}

void solve()
{
	cin >> n >> T;

	arr = vector<pii>(n);
	for (auto &[t, a] : arr) cin >> a >> t;

	rep(i, 0, n) {
		idx.insert({{arr[i].ff, arr[i].ss}, i});
	}

	sort(all(arr));
	vector<int> b;
	int l = 0, r = n, ans = 0;

	while (l <= r) {
		int m = l + (r - l) / 2;

		if (check(m)) {
			ans = m;
			b.clear();
			for (auto x : res) b.pb(x);
			l = m + 1;
		}
		else r = m - 1;
	}

	cout << ans << '\n';
	cout << sz(b) << '\n';
	for (auto x : b) cout << x + 1 << ' ';
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