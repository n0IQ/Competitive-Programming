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

bool check(deque<int> a, deque<int> res, int n)
{
	deque<int> b;
	int i, j;
	for (i = 0, j = n - 1; i < j;) {
		if (a[i] < a[j]) {
			b.push_front(a[i]);
			i++;
		}
		else {
			b.pb(a[j]);
			j--;
		}
	}

	deque<int> c(b);
	b.pb(a[i]);
	c.push_front(a[i]);

	if (b == res || c == res) return 1;
	else return 0;
}

void solve()
{
	int n;
	cin >> n;

	deque<int> a;
	rep(i, 0, n) {
		int x; cin >> x;
		a.pb(x);
	}

	deque<int> b;
	int i, j;
	for (i = 0, j = n - 1; i < j;) {
		if (a[i] < a[j]) {
			b.push_front(a[i]);
			i++;
		}
		else {
			b.pb(a[j]);
			j--;
		}
	}

	deque<int> c(b);
	b.pb(a[i]);
	c.push_front(a[i]);

	if (check(b, a, n)) {
		rep(i, 0, n) cout << b[i] << ' ';
		cout << '\n';
	}
	else if (check(c, a, n)) {
		rep(i, 0, n) cout << c[i] << ' ';
		cout << '\n';
	}
	else cout << -1 << '\n';
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