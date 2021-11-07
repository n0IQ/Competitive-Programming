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

ll a[100010], b[100010];

void helper(int n)
{
	for (int i = 0; i < n; i += 2) {
		b[i] = a[i + 1];
		b[i + 1] = a[i];

		if (a[i] * b[i] < 0) b[i] *= -1;
		if (a[i + 1] * b[i + 1] > 0) b[i] *= -1;
	}
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n) cin >> a[i];

	if (n % 2 == 0) {
		helper(n);
	}
	else {
		helper(n - 3);

		if (a[n - 3] + a[n - 2] != 0) {
			b[n - 3] = a[n - 1], b[n - 2] = a[n - 1], b[n - 1] = abs(a[n - 3]) + abs(a[n - 2]);

			if (a[n - 3] * b[n - 3] > 0) b[n - 3] *= -1;
			if (a[n - 2] * b[n - 2] > 0) b[n - 2] *= -1;
			if (a[n - 1] * b[n - 1] < 0) b[n - 1] *= -1;
		}
		else if (a[n - 3] + a[n - 1] != 0) {
			b[n - 3] = a[n - 2], b[n - 1] = a[n - 2], b[n - 2] = abs(a[n - 3]) + abs(a[n - 1]);

			if (a[n - 3] * b[n - 3] > 0) b[n - 3] *= -1;
			if (a[n - 1] * b[n - 1] > 0) b[n - 1] *= -1;
			if (a[n - 2] * b[n - 2] < 0) b[n - 2] *= -1;
		}
		else if (a[n - 2] + a[n - 1] != 0) {
			b[n - 2] = a[n - 3], b[n - 1] = a[n - 3], b[n - 3] = abs(a[n - 2]) + abs(a[n - 1]);

			if (a[n - 2] * b[n - 2] > 0) b[n - 2] *= -1;
			if (a[n - 1] * b[n - 1] > 0) b[n - 1] *= -1;
			if (a[n - 3] * b[n - 3] < 0) b[n - 3] *= -1;
		}
	}

	rep(i, 0, n) cout << b[i] << ' ';
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