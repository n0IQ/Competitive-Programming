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
	int n, a, b;
	cin >> n >> a >> b;

	int m = n / 2;
	if ((a <= m && b <= m) || (a > m && b > m) || (a > m + 1) || (b < m)) {
		cout << -1 << '\n';
		return;
	}

	int arr[n];
	vector<int> v;
	rep(i, 1, n + 1) {
		if (i != a && i != b) v.pb(i);
	}

	bool mark[n + 1] = {0};
	arr[0] = a, arr[n / 2] = b;
	int j = 1, k = (n / 2) + 1;

	rep(i, 0, sz(v)) {
		if (v[i] < a) {
			arr[k] = v[i];
			k++;
			mark[v[i]] = 1;
		}
		else if (v[i] > b) {
			arr[j] = v[i];
			j++;
			mark[v[i]] = 1;
		}
	}

	set<int> s;
	rep(i, 0, sz(v)) {
		if (mark[v[i]] == 0) s.insert(v[i]);
	}

	while (j < n / 2) {
		arr[j] = *s.begin();
		s.erase(s.begin());
		j++;
	}

	while (k < n) {
		arr[k] = *s.begin();
		s.erase(s.begin());
		k++;
	}

	rep(i, 0, n) cout << arr[i] << ' ';
	cout << '\n';
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